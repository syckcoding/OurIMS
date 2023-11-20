#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>

namespace Ui {
class Teacher;
}

class Teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
