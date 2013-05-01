#ifndef SSLSOCKET_H
#define SSLSOCKET_H

#include <QSslSocket>

class SslSocket : public QSslSocket
{
  Q_OBJECT
public:
  explicit SslSocket(QObject *parent = 0);
  
public slots:
  void slotBytesWritten(qint64 bytes);
  void slotConnected();
  void slotDisconnected();
  void slotEncrypted();
  void slotEncryptedBytesWritten(qint64 bytes);
  void slotError(QAbstractSocket::SocketError error);
  void slotModeChanged(QSslSocket::SslMode mode);
  void slotPeerVerifyError(QSslError error);
  void slotSslErrors(QList<QSslError> errors);
  void slotStateChanged(QAbstractSocket::SocketState state);
  
};

#endif // SSLSOCKET_H
