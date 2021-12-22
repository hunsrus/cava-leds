#ifndef CONFPUERTO_H
#define CONFPUERTO_H

#include <QDialog>

namespace Ui {
class confPuerto;
}

class confPuerto : public QDialog
{
    Q_OBJECT

public:
    explicit confPuerto(QWidget *parent = nullptr);
    ~confPuerto();

    Ui::confPuerto *ui;
private slots:
    void on_btnAceptar_clicked();

    void on_btnCancelar_clicked();

private:

};

#endif // CONFPUERTO_H
