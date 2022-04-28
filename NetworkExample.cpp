#include "NetworkExample.h"
#include <QNetworkReply>

NetworkExample::NetworkExample(QObject *parent)
    : QObject{parent}
{
    _manager = new QNetworkAccessManager(this);
}


void NetworkExample::doGetRequest(const QString& url)
{
    setResponse("");
    auto _request = QScopedPointer<QNetworkRequest>(new QNetworkRequest());
    _request->setUrl(url);
    _request->setTransferTimeout(5000);
    _request->setRawHeader("User-Agent", "Mozilla/5.0 (X11; Linux x86_64; rv:94.0) Gecko/20100101 Firefox/94.0");

    QNetworkReply *reply = _manager->get(*_request);
    QObject::connect(reply, &QNetworkReply::finished, this, &NetworkExample::slotFinished);
}

const QString &NetworkExample::response() const
{
    return _response;
}

void NetworkExample::setResponse(const QString &newResponse)
{
    if (_response == newResponse)
        return;
    _response = newResponse;
    emit responseChanged(_response);
}

void NetworkExample::slotFinished()
{
    QNetworkReply *reply = dynamic_cast<QNetworkReply*>(sender());
    if(reply != nullptr) {
        setResponse(reply->readAll());
        reply->deleteLater();
    }
}
