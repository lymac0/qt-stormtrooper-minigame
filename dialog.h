#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    void setUsername(const QString &name) {username = name;}

    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void spawnTrooper();
    void updateTime();
    void trooperDefeatedSlot();
    void trooperMissedSlot();

private:
    int skor = 0;
    int missed = 0;
    QString username;

    Ui::Dialog *ui;
};
#endif // DIALOG_H
