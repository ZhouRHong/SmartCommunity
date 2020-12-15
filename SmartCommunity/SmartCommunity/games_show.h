#ifndef GAMES_SHOW_H
#define GAMES_SHOW_H

#include <QMainWindow>

namespace Ui
{
    class Games_show;
}

class Games_show : public QMainWindow
{
    Q_OBJECT

public:
    explicit Games_show(QWidget* parent = nullptr);
    ~Games_show();

private slots:
    void on_gobang_pushButton_clicked();

    void on_back_pushButton_clicked();

private:
    Ui::Games_show* ui;
};

#endif // GAMES_SHOW_H
