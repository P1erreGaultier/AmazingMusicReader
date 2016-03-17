#ifndef KEYBOARDOPTWIDGET_H
#define KEYBOARDOPTWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>

class KeyboardOptWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardOptWidget(QWidget *parent = 0);

private:
    QVBoxLayout layout__;
    QCheckBox showNotes__;
    QComboBox selectStyle__;

signals:

public slots:
};

#endif // KEYBOARDOPTWIDGET_H
