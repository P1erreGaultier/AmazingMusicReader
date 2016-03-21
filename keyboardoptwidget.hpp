#ifndef KEYBOARDOPTWIDGET_H
#define KEYBOARDOPTWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>

class KeyboardOptWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardOptWidget(QWidget *parent = 0);

private:
    QGroupBox groupBox__;
    QVBoxLayout groupBoxLayout__;
    QVBoxLayout layout__;
    QCheckBox notesCheckBox__;
    QComboBox styleComboBox__;

signals:
    void showNotes(int state);

private slots:
    void showNotes__(int state);
};

#endif // KEYBOARDOPTWIDGET_H
