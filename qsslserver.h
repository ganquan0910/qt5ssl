#ifndef QSSLSERVER_H
#define QSSLSERVER_H


#define QTCPSERVER_DEBUG
#define QSSLSERVER_DEBUG

#include <QtNetwork/QTcpServer>
#include <QtNetwork/qsslerror.h>
#include <QtNetwork/qsslkey.h>
#include <QtNetwork/qsslcertificate.h>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_SSL



class SslSocket;

class QSslServer : public QTcpServer
{
  Q_OBJECT
public:
  explicit QSslServer(QObject *parent = 0);
  virtual ~QSslServer();
  virtual bool hasSslPendingConnections() const;
  virtual SslSocket *nextSslPendingConnection();

  void setPrivateKey(const QSslKey &key);
  void setLocalCertificate (const QSslCertificate &certificate);

protected:
  virtual void incomingConnection(qintptr socketDescriptor);
  void addPendingSslSocket(SslSocket *socket);
Q_SIGNALS:
  void newSslConnection(SslSocket *socket);

private slots:

private:
  QList<SslSocket *> pendingSslConnections;

  QSslKey privateKey;
  QSslCertificate localCertificate;
};

#endif // QT_NO_SSL

QT_END_NAMESPACE

#endif // QSSLSERVER_H
