#include "Trooper.h"
#include <QPixmap>
#include <QTimer>
#include <QSoundEffect>

Trooper::Trooper(QWidget *parent)
    : QLabel(parent), defeated(false)
{
    setPixmap(QPixmap(":/images/3.png"));
    setScaledContents(true);

    QTimer::singleShot(2000, this, &Trooper::checkIfMissed);
}

void Trooper::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !defeated)
    {
        defeated = true;

        setPixmap(QPixmap(":/images/4.png"));
        emit trooperDefeated();

        QSoundEffect *effect = new QSoundEffect(this);
        effect->setSource(QUrl("qrc:/sounds/clash.wav"));
        effect->setVolume(0.8);
        effect->play();

        QTimer::singleShot(2000, this, &QWidget::hide);
    }
}

void Trooper::checkIfMissed()
{
    if (!defeated)
    {
        emit trooperMissed();
        this->hide();
    }
}
