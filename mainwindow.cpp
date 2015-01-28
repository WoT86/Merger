#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->labelImg1->setStyleSheet("QLabel { color : blue; }");
    this->ui->labelImg2->setStyleSheet("QLabel { color : green; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBrowseImage1_clicked()
{
    QString file1 = QFileDialog::getOpenFileName(this,tr("Choose Image 1"));

    if(!file1.isNull())
        this->ui->graphicsViewImage1->loadImage(file1);
}

void MainWindow::on_buttonBrowseImage2_clicked()
{
    QString file2 = QFileDialog::getOpenFileName(this,tr("Choose Image 2"));

    if(!file2.isNull())
        this->ui->graphicsViewImage2->loadImage(file2);
}
