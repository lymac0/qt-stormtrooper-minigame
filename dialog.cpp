#include "dialog.h"
#include "ui_dialog.h"
#include "Trooper.h"

QTimer *timer1 = new QTimer;
QTimer *timer2 = new QTimer;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/images/5.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);

    QDialog::setFixedSize(700,700);

    timer1->start(1000);
    connect(timer1,&QTimer::timeout,this, &Dialog::updateTime);

    connect(timer2, &QTimer::timeout, this, &Dialog::spawnTrooper);
    timer2->start(500);

}

Dialog::~Dialog()
{
    delete ui;
}

int sure = 30;

void Dialog::updateTime() {
    ui->sure->setText(QString::number(sure));

    if(sure==0)
    {
        timer1->stop();
        timer2->stop();

        QFile file("skorlar.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << username << " " << skor << "\n";
            file.close();
        }

        int maxSkor = 0;
        QFile fileIn("skorlar.txt");
        if (fileIn.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&fileIn);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    int s = parts[1].toInt();
                    if (s > maxSkor)
                        maxSkor = s;
                }
            }
            fileIn.close();
        }

        QString mesaj = QString("Player: %1\nYour Score: %2\nMissed: %3\n\n")
                            .arg(username)
                            .arg(skor)
                            .arg(missed);

        if (skor >= maxSkor)
            mesaj += "New Record! May the force be with you Jedi!";
        else
            mesaj += QString("Highest Score: %1\nGreat warrior. Hmm. Wars not make one great.").arg(maxSkor);

        QMessageBox::information(this, "Game Over", mesaj);

        this->accept();
    }
    sure--;
}

void Dialog::spawnTrooper() {
    Trooper *trooper = new Trooper(this);
    int xPosition = rand() % (this->width() - 50);
    int yPosition = rand() % (this->height() - 50);
    trooper->setGeometry(xPosition, yPosition, 50, 50);

    connect(trooper,&Trooper::trooperDefeated, this, &Dialog::trooperDefeatedSlot);
    connect(trooper, &Trooper::trooperMissed, this, &Dialog::trooperMissedSlot);

    trooper->show();
}

void Dialog::trooperDefeatedSlot() {
    skor++;
    ui->defeatedTroopers->setText(QString::number(skor));

}

void Dialog::trooperMissedSlot() {
    missed++;
    ui->missedTroopers->setText(QString::number(missed));
}


