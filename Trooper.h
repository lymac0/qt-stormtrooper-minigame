#ifndef TROOPER_H
#define TROOPER_H

#include <QLabel>
#include <QMouseEvent>

class Trooper : public QLabel {
    Q_OBJECT

public:
    explicit Trooper(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void trooperDefeated();
    void trooperMissed();

private slots:
    void checkIfMissed();

private:
    bool defeated;
};

#endif // TROOPER_H
