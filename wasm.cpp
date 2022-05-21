#include "wasm.h"

#include <QUrlQuery>
#include <QPair>

#include <emscripten.h>

EM_JS(char*, __js_location, (void), {
    var locstr = window.location.href;
    var len = lengthBytesUTF16(locstr) + 1;
    var strbuf = _malloc(len);
    stringToUTF16(locstr, strbuf, len+1);
    return strbuf;
});

WASM::WASM(QObject *parent)
    : QObject{parent}
{

}

QVariantMap WASM::queryItems()
{
    QUrlQuery q = QUrlQuery( QUrl(location()) );

    QVariantMap result;
    for( QPair<QString,QString> pair : q.queryItems() )
    {
        result[ pair.first ] = pair.second;
    }
    return result;
}

QString WASM::location()
{
    char *jsloc = (char *)__js_location();
    QString result = QString::fromUtf16( (const char16_t *)jsloc );
    free((void*)jsloc);
    return result;
