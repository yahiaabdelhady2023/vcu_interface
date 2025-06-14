#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_NextPage_clicked();

    void on_PreviousPag_clicked();

    void on_exitButn_clicked();

    void on_set_button_clicked();

    void on_PreviousPage_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
