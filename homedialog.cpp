#include "homedialog.h"
#include "ui_homedialog.h"

HomeDialog::HomeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HomeDialog)
{
    ui->setupUi(this);
    setWindowTitle("Welcome, Jedi");

    connect(ui->startButton, &QPushButton::clicked, this, &HomeDialog::accept);
}

HomeDialog::~HomeDialog()
{
    delete ui;
}

QString HomeDialog::getPlayerName() const
{
    return ui->nameInput->text();
}
