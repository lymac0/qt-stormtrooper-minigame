#include "homedialog.h"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HomeDialog home;
    if (home.exec() == QDialog::Accepted) {
        QString playerName = home.getPlayerName();

        Dialog gameWindow;
        gameWindow.setUsername(playerName);
        gameWindow.show();

        return app.exec();
    }

    return 0;
}
