#ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QWidget>
#include <QLabel>


class QGridLayout;
class QLineEdit;

class ClickableLabel: public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(const QString& text = "", QWidget *parent = nullptr);
    ~ClickableLabel();

Q_SIGNALS:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};


class SearchBox : public QWidget
{
    Q_OBJECT

public:
    explicit SearchBox(QWidget *parent = nullptr);
    ~SearchBox();

private:
    QGridLayout *m_layout;
    QLineEdit *m_lineEdit;
    ClickableLabel *m_label;
};
#endif // SEARCHBOX_H
