#include "SslSocket.h"

SslSocket::SslSocket(QObject *parent) :
  QSslSocket(parent)
{
  connect(this, SIGNAL(bytesWritten(qint64)),
          SLOT(slotBytesWritten(qint64)));
  connect(this, SIGNAL(connected()),
          SLOT(slotConnected()));
  connect(this, SIGNAL(disconnected()),
          SLOT(slotDisconnected()));
  connect(this, SIGNAL(encrypted()),
          SLOT(slotEncrypted()));
  connect(this, SIGNAL(encryptedBytesWritten(qint64)),
          SLOT(slotEncryptedBytesWritten(qint64)));
  connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
          SLOT(slotError(QAbstractSocket::SocketError)));
  connect(this, SIGNAL(modeChanged(QSslSocket::SslMode)),
          SLOT(slotModeChanged(QSslSocket::SslMode)));
  connect(this, SIGNAL(peerVerifyError(QSslError)),
          SLOT(slotPeerVerifyError(QSslError)));
  connect(this, SIGNAL(sslErrors(QList<QSslError>)),
          SLOT(slotSslErrors(QList<QSslError>)));
  connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
          SLOT(slotStateChanged(QAbstractSocket::SocketState)));
}

void SslSocket::slotBytesWritten(qint64 bytes)
{
  qDebug() << "bytes written:\t" << bytes << " bytes";
}

void SslSocket::slotConnected()
{
  qDebug() << "abstract socket connected";
}

void SslSocket::slotDisconnected()
{
  qDebug() << "socket Disconnected";
}

void SslSocket::slotEncrypted()
{
  qDebug() << objectName() << "ssl socket is Encrypted";
}

void SslSocket::slotEncryptedBytesWritten(qint64 bytes)
{
  qDebug() << objectName() << "ssl socket has written:\t" << bytes << " bytes";
}

void SslSocket::slotError(QAbstractSocket::SocketError error)
{
  qDebug() << objectName() << "socket error:\t" << error;
}

void SslSocket::slotModeChanged(QSslSocket::SslMode mode)
{
  qDebug() << objectName() << "sslMode changed:\t" << mode;
}

void SslSocket::slotPeerVerifyError(QSslError error)
{
  qDebug() << objectName() << "ssl Peer Veryfy Error:\t" << error;
}

void SslSocket::slotSslErrors(QList<QSslError> errors)
{
  qDebug() << "ssl Errors:\n";
  foreach(QSslError error, errors) {
    qDebug() << objectName() << error;
  }
}

void SslSocket::slotStateChanged(QAbstractSocket::SocketState state)
{
  qDebug() << objectName() << "socket State Changed:\t" << state;
}
