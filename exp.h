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

private:
    Ui::exp *ui;
    QString currentfile; // the entire current file ... not a text box

};
#endif // EXP_H
