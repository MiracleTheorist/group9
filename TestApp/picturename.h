#ifndef PICTURENAME_H
#define PICTURENAME_H
#include <QString>
#include <QObject>
#include <QList>
#include "image.h"

/**
  @brief A singleton design that holds a single given QString object for a picture name
  @author Stacey Gunderson, Alison Lee
 */
class picturename : private QObject
{
    Q_OBJECT
private:
/**The string containing the picture to load */
    QString picturelink;
    /**Overrides the copy function */
    picturename(picturename& other){};
    /**Overrides the assignment function */
    picturename& operator=(picturename& other){};
    /** The singular instance of picturename*/
    static picturename* _instance;
    /** The list of observers, even though it is not used to signal*/
    QList<image*> observers;

public:
/**
   @brief Returns a pointer to a singleton instance of picturename, creates one if it does not exist
   @author Stacey Gunderson, Alison Lee
   @return the pointer to the instance of picturename
 */
    static picturename& instance();
    /**
   @brief Returns the QString with the name of the picture
   @return The name of the image stored
   @author Stacey Gunderson, Alison Lee
 */
    QString get_picture();
    /**
   @brief Adds an observer to the list, and creates a signal connection
   @param The image object to add to the observer list
   @author Stacey Gunderson, Alison Lee
 */
    void add_observer(image*);
    /**
   @brief Removes an observer from the list
   @author Stacey Gunderson, Alison Lee
   @param obj the image object to remove from the list
 */
    void remove_observer(image*);
    /**
   @brief Sets the QString for the picture name to the given QString and notifies observers
   @param The string name to set for the picture
   @author Stacey Gunderson, Alison Lee
 */
    void set_picture(QString);

signals:
/** Sends a signal to notify observers that the image name was updated*/
    void notify();

protected:
/**
   @brief Creates an instance of picturename, set aurora as default image
   @author Stacey Gunderson, Alison Lee
 */
    picturename();

};

#endif // PICTURENAME_H
