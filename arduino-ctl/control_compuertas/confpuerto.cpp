#include "confpuerto.h"
#include "ui_confpuerto.h"

confPuerto::confPuerto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confPuerto)
{
    ui->setupUi(this);
}

confPuerto::~confPuerto()
{
    delete ui;
}


void confPuerto::on_btnAceptar_clicked()
{
    QDialog::accept();
}

void confPuerto::on_btnCancelar_clicked()
{
    QDialog::reject();
}
