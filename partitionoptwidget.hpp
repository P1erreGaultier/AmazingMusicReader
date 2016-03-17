#ifndef PARTITIONOPTWIDGET_H
#define PARTITIONOPTWIDGET_H

#include <QComboBox>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class PartitionOptWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PartitionOptWidget(QWidget *parent = 0);

private:
    QVBoxLayout layout__;
    QPushButton play__;
    QComboBox difficulty__;
    QComboBox partition__;

signals:
    void currentPartitionChanged(const QString &partition);
    void playClicked();

private slots:
    void difficultyChanged(const QString & text);
    void partitionChanged(const QString & text);
    void start();

public slots:
    void stop();
};

#endif // PARTITIONOPTWIDGET_H
