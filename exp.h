#ifndef EXP_H
#define EXP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class exp;
}
QT_END_NAMESPACE

class exp : public QMainWindow
{
    Q_OBJECT

public:
    exp(QWidget *parent = nullptr);
    ~exp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionClear_triggered();

    void on_actionSave_triggered();

    void on_actionNew_Goals_triggered();

private:
    Ui::exp *ui;
    QString currentfile; // to be used for the entire current file ... maybe notes+stats
    QString pushupg="", pullupg="", situpg="";

};
#endif // EXP_H
