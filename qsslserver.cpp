#include <QtNetwork/qsslsocket.h>
#include <QSslKey>
#include "qsslserver.h"
#include "SslSocket.h"


QT_BEGIN_NAMESPACE

QSslServer::QSslServer(QObject *parent)
  : QTcpServer(parent)
{
}

QSslServer::~QSslServer()
{
}

bool QSslServer::hasSslPendingConnections() const
{
  return !pendingSslConnections.isEmpty();
}

SslSocket *QSslServer::nextSslPendingConnection()
{
  if (pendingSslConnections.isEmpty())
    return 0;

  nextPendingConnection();
  return pendingSslConnections.takeFirst();
}

void QSslServer::addPendingSslSocket(SslSocket *socket)
{
  pendingSslConnections.append(socket);
}


void QSslServer::setPrivateKey(const QSslKey &key)
{
  privateKey = key;
#if defined(QSSLSERVER_DEBUG)
  qDebug("QSslServer::setPrivateKey: the key is %s",
         key.isNull() ? "NULL, Invalid" : "Valid");
#endif
}

void QSslServer::setLocalCertificate(const QSslCertificate &certificate)
{
  localCertificate = certificate;
#if defined(QSSLSERVER_DEBUG)
  qDebug("QSslServer::setLocalCertificate: the Cert is %s",
         certificate.isNull() ? "NULL, Invalid" : "Not NULL");
#endif
}

void QSslServer::incomingConnection(qintptr socketDescriptor)
{
#if defined(QSSLSERVER_DEBUG)
  qDebug("QSslServer::incomingConnection(%i)", (int)socketDescriptor);
#endif

  SslSocket *socket = new SslSocket(this);
  socket->setObjectName("ServerToClient In incommingConnection");

  socket->setPrivateKey(privateKey);
  socket->setLocalCertificate(localCertificate);

#if defined(QSSLSERVER_DEBUG)
  if (privateKey.isNull())
    qDebug("Warning: QSslServer::privateKey is Null");
  if (localCertificate.isNull())
    qDebug("Warning: QSslServer::localCertificate is Null");
#endif

  if(socket->setSocketDescriptor(socketDescriptor)) {
    socket->startServerEncryption();
    addPendingSslSocket(socket);
    emit newSslConnection(socket);
  }
  else
    delete socket;
}

QT_END_NAMESPACE

#include "moc_qsslserver.cpp"
