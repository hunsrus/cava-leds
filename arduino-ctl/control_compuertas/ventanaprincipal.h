#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QDialog>
#include <qextserialport.h>

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaPrincipal; }
QT_END_NAMESPACE

class VentanaPrincipal : public QDialog
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal();

    QextSerialPort *puertoSerie;

private slots:
    void on_pbSalir_clicked();

    void on_pbConfig_clicked();

    void on_pbProbar_toggled(bool checked);

private:
    Ui::VentanaPrincipal *ui;
};
#endif // VENTANAPRINCIPAL_H
