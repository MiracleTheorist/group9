/**
  @brief This class takes a given QQuickWidget and displays an image given the absolute path
  @author Stacey Gunderson, Alison Lee
  **/

#ifndef IMAGE_H
#define IMAGE_H

#include <QQuickWidget>
#include <QLabel>
#include <QCoreApplication>
#include <QObject>

/**
 @brief The image class displays an image using a QLabel
 @author Stacey Gunderson, Alison Lee
 **/
class image : public QObject
{
    Q_OBJECT
private:
/** The label that the image is displayed in */
    QLabel* label;

public:
/**
  @brief This class takes a given QQuickWidget and sets up a label to call an image refresh to load the picture name
  @param parent The quickwidget to set the QLabel's parent
  @author Stacey Gunderson, Alison Lee
  **/
    explicit image(QQuickWidget *parent = nullptr);

public slots:
/**
 * @brief Loads the image name in the singleton class picturename to the widget's label and displays the image or an error if no image exists
 * @author Stacey Gunderson, Alison Lee
 */
    void update();
};

#endif // IMAGE_H
