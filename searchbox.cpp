#include "searchbox.h"
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>


ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(text, parent)
{
}


ClickableLabel::~ClickableLabel()
{
}


void ClickableLabel::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}


SearchBox::SearchBox(QWidget *parent)
    : QWidget(parent),
      m_layout(new QGridLayout),
      m_lineEdit(new QLineEdit),
      m_label(new ClickableLabel)
{
    m_label->setPixmap(QIcon(":/magnifying_glass.png").pixmap(QSize(32, 16)));
    m_label->setFixedWidth(32);
    m_lineEdit->setPlaceholderText("Search");
    m_lineEdit->setTextMargins(32, 0, 0, 0);

    m_layout->setSpacing(0);
    m_layout->addWidget(m_lineEdit, 0, 0);
    m_layout->addWidget(m_label, 0, 0);

    setLayout(m_layout);

    connect(m_label, &ClickableLabel::clicked, this, [&](){ m_lineEdit->setFocus(); });
}


SearchBox::~SearchBox()
{
}

