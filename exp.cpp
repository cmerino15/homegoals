#include "exp.h"
#include "./ui_exp.h"
#include "QDateTime"
#include "QFileDialog"

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


void exp::on_actionClear_triggered()
{
    currentfile.clear();
    ui->notes->setText("");
    ui->pushups->setText("");
}


void exp::on_actionSave_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Save file as");
    currentfile = filename;
    QFile file(filename);
    QTextStream out(&file);
    QString mytext = ui->notes->toPlainText() + "\n" + ui->pushups->displayText();
    out << mytext;
    file.close();
}

