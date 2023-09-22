#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void Render();
    void SosiCock();
    void RenderHorizontalLayout1(QHBoxLayout*);
    void RenderVerticalLayout2(QVBoxLayout*);
    void RenderHorizontalLayout3(QHBoxLayout*);
    void createFrameFromImage(QString styleSheet, QWidget* parentWidget);
    QHBoxLayout* createHorizontalLayoutForButton(QString styleSheet1, QString styleSheet2);
    QPushButton* createButton(QString styleSheet);
    QFrame* createFrame();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
