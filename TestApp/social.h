/**
 @brief This class takes a given parent QQuickWidget and displays a social media blog in it
 @author Stacey Gunderson, Alison Lee
 */

#ifndef SOCIAL_H
#define SOCIAL_H
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
 @brief The social class inherits from QObject to get access to signals and slots for updating
 @author Stacey Gunderson, Alison Lee
 */
class social: public QObject
{
    Q_OBJECT
    //Creates a social media browser in the widget given
private:
/**The webview widget pointer*/
    QWebEngineView *wv; 
/**The button that takes refresh clicks*/
    QPushButton *reloadbutton;
/**The CSS style to use for textbox */
    const QString style = "background-color: #A3C1DA; color: white;";
/**The CSS style to use for buttons */
    QString stylebutton = "background-color: white; color: black";
/**The textbox that takes the tumblr username */
    QLineEdit *urlbox;
/**The url to load for tumblr pages on reload */
    QString url;

public:
/**
  @brief Constructor that takes the given parent widget and displays a social media blog inside it, can be updated on button click
  @author Stacey Gunderson, Alison Lee
  @return A social object
  @param parent QQuickWidget to display the social media blog in
 **/
        social(QQuickWidget*parent = nullptr);

public slots:
/**
  @brief Upon button click signal, reloads the url to refresh what is on the page
  @author Stacey Gunderson, Alison Lee
  @return void
 **/
    void on_reload();

signals:
/** A signal that gets sent to on_reload to reload the social media*/
    void reload();
};

#endif // SOCIAL_H
