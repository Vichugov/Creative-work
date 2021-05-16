#ifndef KLASS_H
#define KLASS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Klass; }
QT_END_NAMESPACE

class Klass : public QMainWindow
{
    Q_OBJECT

public:
    Klass(QWidget *parent = nullptr);
    ~Klass();

private slots:
    void number();
    void on_clear_clicked();
    void on_go_clicked();
    void on_plus_clicked();
    void on_minus_clicked();
    void on_doble_clicked();
    void on_ins_clicked();
    void on_inm_clicked();
    void on_inh_clicked();
    void nextline();
    void StandartColor();
    void SetButtonColor();
    void ShowLines();
    void on_umnojit_clicked();

    void on_delit_clicked();

    void on_bpoint_clicked();

private:
    Ui::Klass *ui;
};
#endif // KLASS_H
