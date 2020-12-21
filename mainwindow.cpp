#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int HashSum(std::string text, int maxVal)
{
    unsigned int sum=0;
    for (int i=0; i<text.length(); ++i)
    {
        sum+=(int)text[i];
    }
    return sum%maxVal;
}

int Gamma( std::string text)
{
    int a=23;
    int b=7;
    int c=256;
    int t0=131;
    int sum=0;

    int* mas= new int[text.length()];
    int* rng= new int[text.length()];
    int* finMas= new int[text.length()];

    rng[0]=t0;

    for (int i=0; i<text.length(); i++)
    {
        mas[i]=text[i];
        if (i>0)
        {
            rng[i]=(a*rng[i-1]+b)%c;
        }
        finMas[i]=mas[i]^rng[i];
        sum+=finMas[i];
    }
    return (sum%255);
}

void MainWindow::on_pushButton_clicked()
{
    ui->KSumm1_label->clear();
    ui->KSumm2_label->clear();
    ui->KSumm3_label->clear();
    ui->KSumm4_label->clear();

     ui->SummKodBukvOtkr1_label->clear();
     ui->SummKodBukvOtkr2_label->clear();
     ui->SummKodBukvOtkr3_label->clear();
     ui->SummKodBukvOtkr4_label->clear();

    int maxVal=255;
    int kSumm1=0;
    int kSumm2=0;
    int kSumm3=0;
    int kSumm4=0;


    std::string k1="0123456789";
    std::string k2="9876543210";
    std::string k3="1000005";
    std::string k4="1500000";

    kSumm1=HashSum(k1, maxVal);
    kSumm2=HashSum(k2, maxVal);
    kSumm3=HashSum(k3, maxVal);
    kSumm4=HashSum(k4, maxVal);

    ui->KSumm1_label->setText(ui->KSumm1_label->text() + QString::number(kSumm1));
    ui->KSumm2_label->setText(ui->KSumm2_label->text() + QString::number(kSumm2));
    ui->KSumm3_label->setText(ui->KSumm3_label->text() + QString::number(kSumm3));
    ui->KSumm4_label->setText(ui->KSumm4_label->text() + QString::number(kSumm4));

    ui->SummKodBukvOtkr1_label->setText(ui->SummKodBukvOtkr1_label->text()+ QString::number(Gamma(k1)));
    ui->SummKodBukvOtkr2_label->setText(ui->SummKodBukvOtkr2_label->text()+ QString::number(Gamma(k2)));
    ui->SummKodBukvOtkr3_label->setText(ui->SummKodBukvOtkr3_label->text()+ QString::number(Gamma(k3)));
    ui->SummKodBukvOtkr4_label->setText(ui->SummKodBukvOtkr4_label->text()+ QString::number(Gamma(k4)));
}
