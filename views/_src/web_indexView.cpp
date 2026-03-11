#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT web_indexView : public TActionView
{
public:
  web_indexView() : TActionView() { }
  QString toString();
};

QString web_indexView::toString()
{
  responsebody.reserve(1110);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\r\n</head>\r\n<body>\r\n\r\n<h1>Главное меню</h1>\r\n<p>Достпные к заполнению шаблоны документов РКФ</p>\r\n<div class=\"container\">\r\n  <button type=\"button\">");
  echo(linkTo("племенной смотр", urla("changePage")));
  responsebody += QStringLiteral("</button>\r\n  <button type=\"button\">");
  echo(linkTo("отчёт главного судьи", urla("mainReport")));
  responsebody += QStringLiteral("</button>\r\n  <br>\r\n  <button type=\"button\">");
  echo(linkTo("заявка на проведение племенного смотра", urla("ReqBreed")));
  responsebody += QStringLiteral("</button>\r\n  <button type=\"button\">");
  echo(linkTo("заявка на присвоение титула", urla("ReqTitul")));
  responsebody += QStringLiteral("</button>\r\n  <br>\r\n  <button type=\"button\">");
  echo(linkTo("реестр получения документов", urla("Reesrt")));
  responsebody += QStringLiteral("</button>\r\n</div>\r\n\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(web_indexView)

