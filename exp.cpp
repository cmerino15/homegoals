#include "exp.h"
#include "./ui_exp.h"
#include "QDateTime"
#include "QFileDialog"
#include "QInputDialog"
#include "QMessageBox"

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
    QString summary = "Date:\t" + dateS + "\n\n\npushups: " + ui->pushups->displayText() + "\npullups: " + ui->pullups->displayText() + "\nsitups: " + ui->situps->displayText() ;

    ui->summary->setText(summary);

    double num1 = ui->pushups->displayText().toDouble();
    num1 = double(num1/pushupg.toDouble());
    double num2 = ui->pullups->displayText().toDouble();
    num2 = double(num2/pushupg.toDouble());
    double num3 = ui->situps->displayText().toDouble();
    num3 = double(num3/situpg.toDouble());
    ui->progressBar->setValue((num1+num2+num3)*100.0/3.0);

}


void exp::on_pushButton_2_clicked()
{
    QDate date = QDate::currentDate();

    QString dateS = date.toString("yyyy.MM.dd");
    QString summary = "Date:\t" + dateS + "\npushups: " + ui->pushups->displayText() + "\npullups: " + ui->pullups->displayText() + "\nsitupts: " + ui->situps->displayText() ;


    QString notes = ui->notes->toPlainText();
    static bool summary_state = 0;
    if(summary_state){
        ui->summary->setText(summary);
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
    ui->pullups->setText("");
    ui->situps->setText("");
    ui->summary->setText("");
}


void exp::on_actionSave_triggered()
{
    QDate date = QDate::currentDate();
    QString dateS = date.toString("yyyy.MM.dd");
    QString notes = ui->notes->toPlainText();

    QString summary = "Date:\t" + dateS + "\npushups: " + ui->pushups->displayText() + "\npullups: " + ui->pullups->displayText() + "\nsitupts: " + ui->situps->displayText() ;

    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Save file as");
    currentfile = filename;
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);

    out << summary;
    file.close();
}


void exp::on_actionNew_Goals_triggered()
{
    bool ok;
    pushupg = QInputDialog::getText(this, "Pushups Goal for 3 sets of ___", "pushups", QLineEdit::Normal,"0", &ok);
    pullupg = QInputDialog::getText(this, "Pullups Goal for 3 sets of ___", "pullups", QLineEdit::Normal,"0", &ok);
    situpg = QInputDialog::getText(this, "Situps Goal for 3 sets of ___", "situps", QLineEdit::Normal,"0", &ok);
    ui->label_12->setText(situpg);
    ui->label_11->setText(pullupg);
    ui->label_10->setText(pushupg);
}


void exp::on_actionAbout_triggered()
{
    QMessageBox::about(this, "How to Use", "How to use\n\n1. Click on goals and set, if not already set.\n2. Submit your workout.\n3. Save File for records.\n\nSome progress is better than no progress!");

}

