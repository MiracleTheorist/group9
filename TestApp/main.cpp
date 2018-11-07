#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "digitalclock.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow win;

    //QWidget *testWindow = new QWidget;
    // testWindow->setParent((&w));
    DigitalClock clock(&win);
    // clock.show();

    // Grid layout with 3 buttons
    QGridLayout *gridLayout = new QGridLayout;
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");

    // addWidget(*Widget, row, column, rowspan, colspan)
    // 0th row
    gridLayout->addWidget(&clock,0,0,1,1);
    gridLayout->addWidget(b2,0,1,1,1);
    gridLayout->addWidget(b3,0,2,1,1);

    // 1st row
    gridLayout->addWidget(b4,1,0,1,1);

    // 2nd row with 2-column span
    gridLayout->addWidget(b5,2,0,1,2);

    // 3rd row with 3-column span
    gridLayout->addWidget(b6,3,0,1,3);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // Window title
    w->setWindowTitle("Grid Layouts (3x4)");


    // set parent
    w->setParent(&win);
    // Display
    w->show();
    win.setCentralWidget(w);
    win.show();




    return a.exec();
}
