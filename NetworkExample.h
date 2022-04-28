#ifndef NETWORKEXAMPLE_H
#define NETWORKEXAMPLE_H

#include <QNetworkAccessManager>
#include <QObject>

class NetworkExample : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString response READ response WRITE setResponse NOTIFY responseChanged)

public:
    explicit NetworkExample(QObject *parent = nullptr);

    Q_INVOKABLE void doGetRequest(const QString& url);

    const QString &response() const;

public slots:
    void setResponse(const QString &newResponse);
    void slotFinished();

signals:

    void responseChanged(const QString &response);

private:
    QNetworkAccessManager* _manager = nullptr;
    QString _response;
};

#endif // NETWORKEXAMPLE_H
