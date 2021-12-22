#include <iostream>

#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

#include "confpuerto.h"
#include "ui_confpuerto.h"

#include "qextserialenumerator.h"
#include <QTimer>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    puertoSerie = new QextSerialPort();
    puertoSerie->setBaudRate(BAUD115200);
    puertoSerie->setDataBits(DATA_8);
    puertoSerie->setParity(PAR_NONE);
    puertoSerie->setStopBits(STOP_1);
    puertoSerie->setFlowControl(FLOW_OFF);
    //connect(puertoSerie, SIGNAL(readyRead()), this, SLOT(datosListos()));
}

VentanaPrincipal::~VentanaPrincipal()
{
    if(puertoSerie->isOpen())
      puertoSerie->close();
    delete puertoSerie;
    delete ui;
}
void VentanaPrincipal::on_pbSalir_clicked()
{
    close();
}

void VentanaPrincipal::on_pbConfig_clicked()
{
    confPuerto ventConf(this);
    if (puertoSerie->isOpen()) puertoSerie->close();
    QList<QextPortInfo> puertos = QextSerialEnumerator::getPorts();

    foreach( QextPortInfo unPuerto, puertos )
        if (unPuerto.portName != "")
            ventConf.ui->cmbPuertos->addItem(unPuerto.portName);

    if(ventConf.exec())
    {
        puertoSerie->setPortName(ventConf.ui->cmbPuertos->currentText());
        puertoSerie->open(QIODevice::ReadWrite);
    }
    if(puertoSerie->isOpen())
        this->setWindowTitle("Conectado a "+puertoSerie->portName());
    else
        this->setWindowTitle("Desconectado");
}

/*void VentanaPrincipal::on_rbA_toggled(bool checked)
{
    unsigned char dato;
    if(checked)
        dato = 1;
    else
        dato = 2;
    puertoSerie->write((char *) &dato, 1);
}*/

void VentanaPrincipal::on_pbProbar_toggled(bool checked)
{
    int i = 0, digitos[3];
    unsigned char recibido, dato;
    while(checked)
    {
        std::cin >> recibido;
        if((recibido != 59) && (recibido != 45))
        {
            digitos[i] = recibido-48;
            i++;
        }else if(recibido == 59)
        {
            if(i == 3) dato = digitos[0]*100+digitos[1]*10+digitos[2];
            else if(i == 2) dato = digitos[0]*10+digitos[1];
            else if(i == 1) dato = digitos[0];

            puertoSerie->write((char *) &dato, 1);
            //std::cout << "valor: " << (int)dato << " i: " << i  << std::endl;
            i = 0;
        }else if((int)recibido == 45)
        {
            std::cout << "-" << std::endl;
            //puertoSerie->write((char *) &dato, 1);
        }
        //puertoSerie->write((char *) &recibido, 1);
    }
}

