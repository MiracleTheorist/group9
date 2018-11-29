/**
 @brief This class takes a given parent QQuickWidget and displays a news feed blog in it
 @bug May throw warnings and errors to console about missing sync tokens, will not crash and everything works nicely on the front end
 @author Stacey Gunderson, Alison Lee
 */

#ifndef news_H
#define news_H
#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QNetworkInterface>
#include <QQuickWidget>
#include <QObject>
#include <QApplication>
#include <QLineEdit>


/**
 @brief The news class inherits from QObject to get access to signals and slots for updating
 @author Stacey Gunderson, Alison Lee
 */
class news: public QObject
{
    Q_OBJECT
    //Creates a news browser in the widget given
private:
/**The widget to use to display the newsfeed */
    QWebEngineView *wv;
/**The button that takes refresh clicks */
    QPushButton *reloadbutton;
/**The style to give to the button to make it visible */
    QString stylebutton = "background-color: white; color: black";
/**The url to load the feed */
    QString url;

public:
/**
  @brief Constructor that takes the given parent widget and displays a news feed inside it, can be updated on button click
  @author Stacey Gunderson, Alison Lee
  @param QQuickWidget parent widget to display the news media blog in
 **/
        news(QQuickWidget*parent = nullptr);

public slots:
/**
  @brief Upon button click signal, reloads the url to refresh what is on the page
  @author Stacey Gunderson, Alison Lee
  @return void
 **/
    void on_reload();

signals:
/**Will signal to reload the newsfeed when the button is pressed*/
    void reload();
};

#endif // news_H
