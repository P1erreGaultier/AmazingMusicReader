#ifndef SCORETABWIDGET_H
#define SCORETABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QTreeWidget>
#include <QTreeView>
#include <QVector>
#include <QStringList>
#include <QVBoxLayout>

/**
* La classe qui represente l'onglet performance
* @author Alexis Giraudet & Pierre Gaultier
*/
class ScoreTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreTabWidget(QWidget *parent = 0);

private:
    QVBoxLayout layout__;
    QComboBox playerName__;
    QTreeWidget scoreTree__;
    QVector<QStringList> scores__;
    QVector<QTreeWidgetItem*> items__;

    void clearScoreTree__();

signals:

private slots:
    void currentPlayerNameChanged__(const QString & text);

public slots:
    void updateScore();
};

#endif // SCORETABWIDGET_H
