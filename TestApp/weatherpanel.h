#ifndef WEATHERPANEL_H
#define WEATHERPANEL_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>


#include <QWidget>
#include <qnetworkconfigmanager.h>
#include <qnetworksession.h>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>
#include <QApplication>
#include <QtWidgets>
/**
 *@brief Takes a qquickwidget and displays the weather in it
 * @author Thomas Grummett
 */
class QQuickWidget;
class weatherpanel: public QLabel
{
public:
       int getWeatherID();
       void setWeatherID(int toSet);
       QString wToImage;
       int weatherID;
       weatherpanel(QQuickWidget *parent=0);
       QString getID();
       void setWeather(QString weatherIn);
       void setTemp(QString tempIn);
       QString city;
       QNetworkAccessManager *nam;
       QNetworkSession *ns;
       QString getWeather();
       QString getTemp();
       QString appID;
       void updateText();
private slots:
       void pullWeather();
private:
       void updateImage();
       QString weather;
       QString temperature;
       void dataToVars(QNetworkReply *netreply);
       QString KtoC(double temp);

};

#endif // WEATHERPANEL_H
