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
#include <QFileSystemWatcher>

/**
* La classe qui represente l'onglet performance
* @author Alexis Giraudet & Pierre Gaultier
*/
class ScoreTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreTabWidget(QWidget *parent = 0);
    ~ScoreTabWidget();

private:
    QVBoxLayout layout__;
    QLabel playerNameLabel__;
    QComboBox playerName__;
    QTreeWidget scoreTree__;
    QVector<QTreeWidgetItem*> items__;
    QVector<QStringList> scores__;
    QFileSystemWatcher scoreWatcher__;

signals:

private slots:
    void playerNameChanged__(const QString & text);
    void scoreChanged__(const QString & file);

public slots:
};

#endif // SCORETABWIDGET_H
