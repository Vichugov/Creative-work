#include "klass.h"
#include "ui_klass.h"
int op=0;
int stroka=1;
QString result;
double h,m,s,r;
Klass::Klass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Klass)
{
    ui->setupUi(this);
    ui->CText->hide();
    ui->consta->hide();
    ui->hours->setFocus();
    StandartColor();
    connect(ui->b0,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b1,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b2,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b3,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b4,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b5,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b6,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b7,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b8,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b9,SIGNAL(clicked()),this,SLOT(number()));
    connect(ui->b0,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b1,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b2,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b3,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b4,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b5,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b6,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b7,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b8,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->b9,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->plus,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->minus,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->umnojit,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->delit,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->bpoint,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->doble,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->clear,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->inh,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->inm,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->ins,SIGNAL(pressed()),this,SLOT(SetButtonColor()));
    connect(ui->hours,SIGNAL(returnPressed()),this,SLOT(nextline()));
    connect(ui->minuts,SIGNAL(returnPressed()),this,SLOT(nextline()));
    connect(ui->secunds,SIGNAL(returnPressed()),this,SLOT(nextline()));
    connect(ui->hours_2,SIGNAL(returnPressed()),this,SLOT(nextline()));
    connect(ui->minuts_2,SIGNAL(returnPressed()),this,SLOT(nextline()));
    connect(ui->secunds_2,SIGNAL(returnPressed()),this,SLOT(nextline()));
}

Klass::~Klass()
{
    delete ui;
}
void Klass::number()
{
    QPushButton *button = (QPushButton *)sender();
    button->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    QString buf;
    double dbuf;
    switch(stroka){
    case 1:
        dbuf = (ui->hours->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->hours->setText(buf);
        break;
    case 2:
        dbuf = (ui->minuts->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->minuts->setText(buf);
        break;
    case 3:
        dbuf = (ui->secunds->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->secunds->setText(buf);
        break;
    case 4:
        dbuf = (ui->hours_2->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->hours_2->setText(buf);
        break;
    case 5:
        dbuf = (ui->minuts_2->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->minuts_2->setText(buf);
        break;
    case 6:
        dbuf = (ui->secunds_2->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->secunds_2->setText(buf);
        break;
    case 8:
        dbuf = (ui->consta->text() + button->text()).toDouble();
        buf = QString::number(dbuf,'g',15);
        ui->consta->setText(buf);
        break;
    }

}

void Klass::on_clear_clicked()
{
    ui->clear->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 18px;color: white;");
    ui->hours->setText("");
    ui->minuts->setText("");
    ui->secunds->setText("");
    ui->hours_2->setText("");
    ui->minuts_2->setText("");
    ui->secunds_2->setText("");
    ui->consta->setText("");
    ui->resval->setText(""); 
    h=0;
    m=0;
    s=0;
    r=0;
    stroka=1;
    ui->hours->setFocus();
    StandartColor();
}
void Klass::on_go_clicked()
{
    if(ui->consta->text().toDouble()==0) ui->consta->setText("1");
    switch (op) {
    case 0: r=(ui->hours->text()).toDouble()*3600+(ui->minuts->text()).toDouble()*60+(ui->secunds->text()).toDouble()+(ui->hours_2->text()).toDouble()*3600+(ui->minuts_2->text()).toDouble()*60+(ui->secunds_2->text()).toDouble();break;
    case 1: r=((ui->hours->text()).toDouble()*3600+(ui->minuts->text()).toDouble()*60+(ui->secunds->text()).toDouble())-((ui->hours_2->text()).toDouble()*3600+(ui->minuts_2->text()).toDouble()*60+(ui->secunds_2->text()).toDouble());break;
    case 2: r=((ui->hours->text()).toDouble()*3600+(ui->minuts->text()).toDouble()*60+(ui->secunds->text()).toDouble())*(ui->consta->text()).toDouble();break;
    case 3: r=((ui->hours->text()).toDouble()*3600+(ui->minuts->text()).toDouble()*60+(ui->secunds->text()).toDouble())/(ui->consta->text()).toDouble();break;
    }
    h=static_cast<int>(r)/3600;
    r-=h*3600;
    m=static_cast<int>(r)/60;
    r-=m*60;
    s=r;
    result=QString::number(h,'g',15)+':'+QString::number(m,'g',15)+':'+QString::number(s,'g',15);
    ui->resval->setText(result);
}
void Klass::ShowLines(){
    switch (op) {
    case 0: ui->CText->hide();ui->consta->hide();ui->hours_2->show();ui->minuts_2->show();ui->secunds_2->show();ui->Htext2->show();ui->Mtext2->show();ui->Stext2->show();break;
    case 1: ui->CText->hide();ui->consta->hide();ui->hours_2->show();ui->minuts_2->show();ui->secunds_2->show();ui->Htext2->show();ui->Mtext2->show();ui->Stext2->show();break;
    case 2: ui->CText->show();ui->consta->show();ui->hours_2->hide();ui->minuts_2->hide();ui->secunds_2->hide();ui->Htext2->hide();ui->Mtext2->hide();ui->Stext2->hide();break;
    case 3: ui->CText->show();ui->consta->show();;ui->hours_2->hide();ui->minuts_2->hide();ui->secunds_2->hide();ui->Htext2->hide();ui->Mtext2->hide();ui->Stext2->hide();break;
    }
}
void Klass::on_plus_clicked()
{
    ui->plus->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    ui->znak->setText("+");
    op=0;
    ShowLines();
}

void Klass::on_minus_clicked()
{
    ui->minus->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    ui->znak->setText("-");
    op=1;
    ShowLines();
}
void Klass::on_umnojit_clicked()
{
    ui->umnojit->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    ui->znak->setText("*");
    op=2;
    ShowLines();
}

void Klass::on_delit_clicked()
{
    ui->delit->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    ui->znak->setText("/");
    op=3;
    ShowLines();
}
void Klass::on_doble_clicked()
{
    ui->doble->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
nextline();
}

void Klass::on_ins_clicked()
{
    ui->ins->setStyleSheet("background-color: rgb(0,200,150);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
    r=h*3600+m*60+s;
    result=QString::number(r,'g',15);
    ui->resval->setText(result);
}

void Klass::on_inm_clicked()
{
    ui->inm->setStyleSheet("background-color: rgb(0,200,150);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
    r=h*60+m+s/60;
    result=QString::number(r,'g',15);
    ui->resval->setText(result);
}

void Klass::on_inh_clicked()
{
    ui->inh->setStyleSheet("background-color: rgb(0,200,150);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
    r=h+m/60+s/3600;
    result=QString::number(r,'g',10);
    ui->resval->setText(result);
}
void Klass::StandartColor(){
    ui->hours->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->minuts->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->secunds->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->hours_2->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->minuts_2->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->secunds_2->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    ui->consta->setStyleSheet("background-color: rgb(0,200,230);border-radius: 10px;border: 1px solid black;color: white;");
    switch (stroka) {
    case 1:ui->hours->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->hours->setFocus();break;
    case 2: ui->minuts->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->minuts->setFocus();break;
    case 3: ui->secunds->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->secunds->setFocus();break;
    case 4: ui->hours_2->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->hours_2->setFocus();break;
    case 5: ui->minuts_2->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->minuts_2->setFocus();break;
    case 6: ui->secunds_2->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->secunds_2->setFocus();break;
    case 8: ui->consta->setStyleSheet("background-color: rgb(200,00,100);border-radius: 10px;border: 1px solid black;color: white;");ui->consta->setFocus();break;
    }
}
void Klass::nextline(){
    if (op<2){
    if (stroka<6) stroka++;
    else stroka=1;
    }
    else{
        if (stroka<3) stroka++;
        else if (stroka==3) stroka=8;
        else stroka=1;
    }
    StandartColor();
}
void Klass::SetButtonColor(){
    QPushButton *button = (QPushButton *)sender();
    button->setStyleSheet("background-color: rgb(0,200,200);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    if(button==ui->clear) ui->clear->setStyleSheet("background-color: rgb(0,200,200);border-radius: 10px;border: 1px solid black;font-size: 18px;color: white;");
    if(button==ui->inh) ui->inh->setStyleSheet("background-color: rgb(0,180,130);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
    if(button==ui->inm) ui->inm->setStyleSheet("background-color: rgb(0,180,130);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
    if(button==ui->ins) ui->ins->setStyleSheet("background-color: rgb(0,180,130);border-radius: 10px;border: 1px solid black;color: white;font-size: 16px;");
}



void Klass::on_bpoint_clicked()
{
    ui->bpoint->setStyleSheet("background-color: rgb(0,220,220);border-radius: 10px;border: 1px solid black;font-size: 30px;color: white;");
    QString s;
    switch (stroka) {
    case 1:  if (!ui->hours->text().contains('.')){s= ui->hours->text();s+='.';ui->hours->setText(s);} break;
        case 2:  if (!ui->minuts->text().contains('.')){s= ui->minuts->text();s+='.';ui->minuts->setText(s);}break;
        case 3:  if (!ui->secunds->text().contains('.')){s= ui->secunds->text();s+='.';ui->secunds->setText(s);}break;
        case 4:  if (!ui->hours_2->text().contains('.')){s= ui->hours_2->text();s+='.';ui->hours_2->setText(s);}break;
        case 5:  if (!ui->minuts_2->text().contains('.')){s= ui->minuts_2->text();s+='.';ui->minuts_2->setText(s);}break;
        case 6:  if (!ui->secunds_2->text().contains('.')){s= ui->secunds_2->text();s+='.';ui->secunds_2->setText(s);}break;
    case 8: if (!ui->consta->text().contains('.')){s= ui->consta->text();s+='.';ui->consta->setText(s);}break;
    }
}
