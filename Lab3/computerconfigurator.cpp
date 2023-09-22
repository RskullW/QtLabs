#include "computerconfigurator.h"

void ComputerConfigurator::loadComponents() {
    QString fileName = QFileDialog::getOpenFileName(this, "Загрузить компоненты", "", "JSON Files (*.json)");

    if (!fileName.isEmpty()) {
        QFile configFile(fileName);
        if (configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QByteArray jsonData = configFile.readAll();
            QJsonDocument configDoc = QJsonDocument::fromJson(jsonData);
            QJsonObject configObject = configDoc.object();

            for (const QString &category : configObject.keys()) {

                if (comboBoxes[category]) {
                    QJsonObject components = configObject.value(category).toObject();
                    for (const QString &componentName : components.keys()) {
                        comboBoxes[category]->addItem(componentName);
                        int componentPrice = components.value(componentName).toInt();
                        componentPrices[componentName] = componentPrice;
                    }
                }
            }

            configFile.close();
            QMessageBox::information(this, "Загрузка", "Компоненты загружены из файла");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось загрузить компоненты из файла");
        }
    }
}
void ComputerConfigurator::calculateTotalPrice() {
    int total = 0;
    for (QString category: categories) {
        for (QComboBox *comboBox : comboBoxes) {
            QString selectedComponent = comboBox->currentText();
            if (componentPrices.contains(selectedComponent)) {
                total += componentPrices.value(selectedComponent);
            }
        }
    }

    totalPriceLabel->setText("Итоговая цена: " + QString::number(total) + " RUB");
}
void ComputerConfigurator::addComponent() {
    bool ok;
    QString componentName = QInputDialog::getText(this, "Добавить комплектующее", "Введите имя комплектующего:", QLineEdit::Normal, "", &ok);
    QString categoryName = "";
    int priceComponent = 0;
    if (ok) {
        categoryName = QInputDialog::getText(this, "Выбор категории", "Введите название категории (ПР - процессор, МП - материнская плата, ВК - видеокарта, ОП - оперативная память, ЖД - жесткий диск):", QLineEdit::Normal, "", &ok);
    }


    if (ok) {
        priceComponent = QInputDialog::getInt(this, "Установка цены" ,"Введите цену на комплектующее", QLineEdit::Normal, 0);
    }

    if (ok && !componentName.isEmpty() && !categoryName.isEmpty()) {
        componentPrices.insert(componentName, priceComponent);

        if (categoryName == "ПР") {
            categoryName = "Процессор";
        }

        else if (categoryName == "МП") {
            categoryName = "Материнская плата";
        }

        else if (categoryName == "ОП") {
            categoryName = "Оперативная память";
        }

        else if (categoryName == "ВК") {
            categoryName = "Видеокарта";
        }

        else {
            categoryName = "Жесткий диск";
        }

        comboBoxes[categoryName]->addItem(componentName);

        saveComponents(categoryName, componentName, priceComponent);
    }
}
void ComputerConfigurator::saveConfiguration() {
    QJsonObject configObject;

    for (int i = 0; i < categories.size(); ++i) {
        QString category = categories[i];
        QString selectedComponent = comboBoxes[category]->currentText();
        configObject[categories[i]] = selectedComponent;
    }

    QString configName = configNameLineEdit->text();
    configObject["ConfigName"] = configName;

    // Создание JSON документа и сохранение в файл
    QJsonDocument configDoc(configObject);
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить конфигурацию", "", "JSON Files (*.json)");
    if (!fileName.isEmpty()) {
        QFile configFile(fileName);
        if (configFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            configFile.write(configDoc.toJson());
            configFile.close();
            QMessageBox::information(this, "Сохранение", "Конфигурация сохранена в файл");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить конфигурацию в файл");
        }
    }
}
void ComputerConfigurator::saveComponents(QString categoryName, QString nameComponent, int price) {
    QString fileName;

    if (fileComponentsName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Сохранить комплектующие", "", "JSON Files (*.json)");
    }

    else {
        fileName = fileComponentsName;
    }

    QFile configFile(fileName);

    if (configFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QByteArray jsonData = configFile.readAll();
        configFile.resize(0);

        QJsonDocument configDoc;
        if (!jsonData.isEmpty()) {
            configDoc = QJsonDocument::fromJson(jsonData);
        }

        QJsonObject configObject = configDoc.object();

        QJsonObject categoryObject = configObject[categoryName].toObject();
        categoryObject[nameComponent] = price;

        configObject[categoryName] = categoryObject;

        QJsonDocument newConfigDoc(configObject);
        configFile.write(newConfigDoc.toJson(QJsonDocument::Compact));
        configFile.close();

        QMessageBox::information(this, "Сохранение", "Комплектующие сохранены в файл");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить комплектующие в файл");
    }
}
void ComputerConfigurator::loadConfiguration() {
    QString fileName = QFileDialog::getOpenFileName(this, "Загрузить конфигурацию", "", "JSON Files (*.json)");
    if (!fileName.isEmpty()) {
        QFile configFile(fileName);
        if (configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QByteArray jsonData = configFile.readAll();
            QJsonDocument configDoc = QJsonDocument::fromJson(jsonData);
            QJsonObject configObject = configDoc.object();

            for (int i = 0; i < categories.size(); ++i) {
                if (configObject.contains(categories[i])) {
                    comboBoxes[categories[i]]->setCurrentText(configObject.value(categories[i]).toString());
                }
            }

            if (configObject.contains("ConfigName")) {
                configNameLineEdit->setText(configObject.value("ConfigName").toString());
            }

            calculateTotalPrice();

            QMessageBox::information(this, "Загрузка", "Конфигурация загружена из файла");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось загрузить конфигурацию из файла");
        }
    }
}
void ComputerConfigurator::createMainMenu() {
    QVBoxLayout *layout = new QVBoxLayout;

    for (const QString &category : categories) {
        QComboBox *comboBox = new QComboBox;
        comboBoxes[category] = comboBox;
        layout->addWidget(new QLabel(category));
        layout->addWidget(comboBoxes[category]);

        connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(calculateTotalPrice()));
    }

    configNameLineEdit = new QLineEdit;
    layout->addWidget(new QLabel("Имя конфигурации:"));
    layout->addWidget(configNameLineEdit);

    QPushButton *addComponentButton = new QPushButton("Добавить комплектующее");
    connect(addComponentButton, &QPushButton::clicked, this, &ComputerConfigurator::addComponent);
    layout->addWidget(addComponentButton);

    QPushButton *saveButton = new QPushButton("Сохранить");
    connect(saveButton, &QPushButton::clicked, this, &ComputerConfigurator::saveConfiguration);
    layout->addWidget(saveButton);

    QPushButton *loadButton = new QPushButton("Загрузить");
    connect(loadButton, &QPushButton::clicked, this, &ComputerConfigurator::loadConfiguration);
    layout->addWidget(loadButton);

    totalPriceLabel = new QLabel("Итоговая цена: 0 RUB");
    layout->addWidget(totalPriceLabel);

    setLayout(layout);
}
