#ifndef PARTITIONOPTWIDGET_H
#define PARTITIONOPTWIDGET_H

#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>

/**
* La classe qui represente les options de la partition
* @author Alexis Giraudet & Pierre Gaultier
*/
class PartitionOptWidget : public QWidget
{
    Q_OBJECT
public:
    /**
    * Constructeur
    * Crée un PartitionOptWidget
    * @param Widget parent
    */
    explicit PartitionOptWidget(QWidget *parent = 0);

private:
    QGroupBox groupBox__;
    QVBoxLayout groupBoxLayout__;
    QVBoxLayout layout__;
    QPushButton demo__;
    QPushButton play__;
    QComboBox difficulty__;
    QComboBox partition__;
    QLabel difficultyLabel__;
    QLabel partitionLabel__;

signals:
    void partitionChanged(const QString &partition);
    void playDemo();
    void playGame();

private slots:
    void difficultyChanged__(const QString & text);
    void partitionChanged__(const QString & text);
    void playDemo__();
    void playGame__();

public slots:
    void enable();
    void disable();
};

#endif // PARTITIONOPTWIDGET_H
