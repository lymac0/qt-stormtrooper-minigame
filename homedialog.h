#ifndef HOMEDIALOG_H
#define HOMEDIALOG_H

#include <QDialog>

namespace Ui {
class HomeDialog;
}

class HomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HomeDialog(QWidget *parent = nullptr);
    ~HomeDialog();

    QString getPlayerName() const;

private:
    Ui::HomeDialog *ui;
};

#endif // HOMEDIALOG_H
