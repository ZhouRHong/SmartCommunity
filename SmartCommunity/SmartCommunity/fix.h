#ifndef FIX_H
#define FIX_H

#include <QMainWindow>

namespace Ui {
class Fix;
}

class Fix : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fix(QWidget *parent = nullptr);
    ~Fix();

private:
    Ui::Fix *ui;
};

#endif // FIX_H
