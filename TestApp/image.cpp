/**
  @brief This class takes a given QQuickWidget and displays an image given the absolute path. Will update on a change in picturename
  @author Stacey Gunderson, Alison Lee
  */

#include "image.h"
#include "picturename.h"

/**
  @brief This class takes a given QQuickWidget and sets up a label to call an image refresh to load the picture name
  @param parent The widget to make parent of this
  @author Stacey Gunderson, Alison Lee
  **/
image::image(QQuickWidget *parent)
{
    //Creates and sets alignment of the label image to center
    image::label = new QLabel(parent);
    label->setAlignment(Qt::AlignTop);
    label->resize(500,500);
    picturename::instance().add_observer(this);

    image::update();
}

/**
 * @brief Loads the image name in the singleton class picturename to the widget's label and displays the image or an error if no image exists
 * @author Stacey Gunderson, Alison Lee
 */
void image::update()
{
    //Pulls the image name from the picturename instance
    picturename::instance();
    QString name = picturename::instance().get_picture();
    //Adds the name to a path so it can be pulled from the image resourcres
    QString link = "://" + name +".jpg";
    //Makes the path a string
    QImage* thing = new QImage(link);

    //Checks if the object exists and if not tries to load the image as a png
    //.jpg is used if both .jpg and .png exist
    if (thing->isNull()) {

        //Quick fix for if the image is a png and not jpg
        QString link = "://" + name +".png";
        QImage* thing = new QImage(link);
        if (thing->isNull())
        {
            //If neither png or jpg exits, then simply set an error message
            label->setText("Image not found");
        }
        else
        {
            //Scales the image to fit the label without breaking the aspect ratio, fixed size
            QPixmap pix = QPixmap::fromImage(*thing);
            pix = pix.scaled(label->size(),Qt::KeepAspectRatio);
            label->setPixmap(pix);
        }
    }
    else
    {
        //Scales the image to fit the label without breaking the aspect ratio, fixed size
        QPixmap pix = QPixmap::fromImage(*thing);
        pix = pix.scaled(label->size(),Qt::KeepAspectRatio);
        label->setPixmap(pix);
    }
  //Shows the label
    label->show();
}

