#ifndef IDENTITY_CHOOSE_H
#define IDENTITY_CHOOSE_H

#include <QDialog>

namespace Ui {
class identity_choose;
}

class identity_choose : public QDialog
{
    Q_OBJECT

signals:
    void windowHidden();

public slots:
    void hideEvent(QHideEvent *event) override
    {
        emit windowHidden();
        QWidget::hideEvent(event);
    }

public:
    explicit identity_choose(QWidget *parent = nullptr);

    int getChoose();

    int choose;

    ~identity_choose();

private slots:
    void on_pushButton_admin_clicked();

    void on_pushButton_teacher_clicked();

    void on_pushButton_student_clicked();

private:
    Ui::identity_choose *ui;
};

#endif // IDENTITY_CHOOSE_H
