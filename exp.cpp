#include "exp.h"
#include "./ui_exp.h"
#include "QDateTime"

exp::exp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exp)
{
    ui->setupUi(this);
}

exp::~exp()
{
    delete ui;
}

void exp::on_pushButton_clicked()
{
    QDate date = QDate::currentDate();

    QString dateS = date.toString("yyyy.MM.dd");


    ui->summary->setText("Date:\t" + dateS + "\npushups: " + ui->pushups->displayText() );

}


void exp::on_pushButton_2_clicked()
{
    QDate date = QDate::currentDate();

    QString dateS = date.toString("yyyy.MM.dd");

    QString notes = ui->notes->toPlainText();
    static bool summary_state = 0;
    if(summary_state){
        ui->summary->setText("Date:\t" + dateS + "\npushups: " + ui->pushups->displayText() );
        summary_state = 0;
    }
    else{
        ui->summary->setPlainText(notes);
        summary_state = 1;
    }

}

