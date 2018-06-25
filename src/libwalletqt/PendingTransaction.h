#ifndef PENDINGTRANSACTION_H
#define PENDINGTRANSACTION_H

#include <QObject>

#include <wallet/api/wallet2_api.h>

//namespace Moneda {
//class PendingTransaction;
//}

class PendingTransaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status)
    Q_PROPERTY(QString errorString READ errorString)
    Q_PROPERTY(quint64 amount READ amount)
    Q_PROPERTY(quint64 dust READ dust)
    Q_PROPERTY(quint64 fee READ fee)
    Q_PROPERTY(QStringList txid READ txid)
    Q_PROPERTY(quint64 txCount READ txCount)

public:
    enum Status {
        Status_Ok       = Moneda::PendingTransaction::Status_Ok,
        Status_Error    = Moneda::PendingTransaction::Status_Error,
        Status_Critical    = Moneda::PendingTransaction::Status_Critical
    };
    Q_ENUM(Status)

    enum Priority {
        Priority_Low    = Moneda::PendingTransaction::Priority_Low,
        Priority_Medium = Moneda::PendingTransaction::Priority_Medium,
        Priority_High   = Moneda::PendingTransaction::Priority_High
    };
    Q_ENUM(Priority)


    Status status() const;
    QString errorString() const;
    Q_INVOKABLE bool commit();
    quint64 amount() const;
    quint64 dust() const;
    quint64 fee() const;
    QStringList txid() const;
    quint64 txCount() const;
    Q_INVOKABLE void setFilename(const QString &fileName);

private:
    explicit PendingTransaction(Moneda::PendingTransaction * pt, QObject *parent = 0);

private:
    friend class Wallet;
    Moneda::PendingTransaction * m_pimpl;
    QString m_fileName;
};

#endif // PENDINGTRANSACTION_H
