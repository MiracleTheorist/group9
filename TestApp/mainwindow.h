/**
  @brief This class takes a given QQuickWidget and displays an image given the absolute path
  @author Meghan Hannon
  **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QQuickWidget>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/** 
  @brief constructorfor MainWindow
  @return a MainWindow 
  @param parent Qwidget widget to
**/ 
    explicit MainWindow(QWidget *parent = nullptr);
/**
  @brief destructor for MainWindow
**/
    ~MainWindow();

private:
/**The user interface object for MainWindow */
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
