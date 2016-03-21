#ifndef HOMETABWIDGET_H
#define HOMETABWIDGET_H

#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QSignalMapper>
#include <QTabWidget>

/**
* La classe qui represente l'onglet d'accueil
* @author Alexis Giraudet & Pierre Gaultier
*/
class HomeTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeTabWidget(QTabWidget & tabParent, QWidget *parent = 0);

private:
    QTabWidget & tabParent__;
    QLabel labelImage__;
    QLabel labelText__;
    QVBoxLayout layout__;
    QPushButton buttonScore__;
    QPushButton buttonPlay__;


signals:

private slots:

    void scoreClicked();
    void playClicked();

public slots:
};

#endif // HOMETABWIDGET_H
