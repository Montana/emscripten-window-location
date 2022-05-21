#ifndef WASM_H
#define WASM_H

#include <QObject>
#include <QVariantMap>

class WASM : public QObject
{
    Q_OBJECT

public:
    explicit WASM(QObject *parent = nullptr);

    Q_INVOKABLE QVariantMap queryItems();
    Q_INVOKABLE QString location();

signals:

};
