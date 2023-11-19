#ifndef IDENTITY_CHOOSE_H
#define IDENTITY_CHOOSE_H

#include <QDialog>

namespace Ui {
class identity_choose;
}

class identity_choose : public QDialog
{
    Q_OBJECT

public:
    explicit identity_choose(QWidget *parent = nullptr);
    ~identity_choose();

private:
    Ui::identity_choose *ui;
};

#endif // IDENTITY_CHOOSE_H
