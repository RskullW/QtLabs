#pragma once

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>
class ComputerConfigurator : public QWidget {
    Q_OBJECT

public:
    ComputerConfigurator(QWidget *parent = nullptr) : QWidget(parent) {
        createMainMenu();
        loadComponents();
    }

private slots:
    void calculateTotalPrice();

    void loadComponents();

    void addComponent();

    void saveConfiguration();

    void saveComponents(QString categoryName, QString nameComponent, int price);

    void loadConfiguration();
    void createMainMenu();

private:
    QStringList categories = {"Процессор", "Материнская плата", "Видеокарта", "Оперативная память", "Жесткий диск"};
    QMap<QString, QComboBox *> comboBoxes;
    QLineEdit *configNameLineEdit;
    QMap<QString, int> componentPrices;
    QString fileComponentsName = "";
    QLabel *totalPriceLabel;
    bool isConfigurationOpen = false;

};
