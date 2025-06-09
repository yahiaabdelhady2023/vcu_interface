#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString ASSI_status_value="AS_Status";
    int LabelSize = 18;
    QFont label_font;
    label_font.setPointSize(LabelSize);

    ui->ASSI_label->setText(ASSI_status_value);
    ui->ASSI_label->setFont(label_font);
    ui->ASSI_label->setAlignment(Qt::AlignCenter);

    QStringList items;
    items << "No Selected" << "Acceleration" << "Skidpad" << "Autocross"; //list
    ui->AMI_ComboBox->addItems(items);
    ui->AMI_ComboBox->setFont(label_font);

    int rowCount = ui->AMI_ComboBox->count();

    for (int i = 0; i < rowCount; ++i) {
        QModelIndex index = ui->AMI_ComboBox->model()->index(i,0);
        ui->AMI_ComboBox->model()->setData(index, QSize(100, 100), Qt::SizeHintRole);
    }




    int Row =ui->DataTable->rowCount();
    ui->DataTable->insertRow(Row );
    ui->DataTable->setItem(Row,0, new QTableWidgetItem("48 Battery Voltage"));
    ui->DataTable->setItem(Row,1, new QTableWidgetItem("52.76"));
    ui->DataTable->setItem(Row,2, new QTableWidgetItem("V"));




    //===========================================================================================
    int Row_Table_Two =ui->SignalTable->rowCount();
    ui->SignalTable->insertRow(Row_Table_Two );
    ui->SignalTable->setItem(Row_Table_Two,0, new QTableWidgetItem("48 Battery Voltage"));
    ui->SignalTable->setItem(Row_Table_Two,1, new QTableWidgetItem("52.76"));
    ui->SignalTable->setItem(Row_Table_Two,2, new QTableWidgetItem("V"));
    ui->SignalTable->setItem(Row_Table_Two,3, new QTableWidgetItem("ABC"));

    ui->DataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ensures that columns take all avaiable space
    ui->SignalTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ensures that columns take all avaiable space


    ui->DataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->SignalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NextPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);

}


void MainWindow::on_PreviousPag_clicked()
{
     ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
}

