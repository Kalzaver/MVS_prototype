#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT web_changeStatusView : public TActionView
{
public:
  web_changeStatusView() : TActionView() { }
  QString toString();
};

QString web_changeStatusView::toString()
{
  responsebody.reserve(483);
  responsebody += tr("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>Другая страница</title>\r\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"/css/style.css\">\r\n</head>\r\n<body>\r\n   ");
  tfetch(QString, newTitle);
  responsebody += QStringLiteral("   <h1>");
  eh(newTitle);
  responsebody += QStringLiteral("</h1>\r\n   ");
  echo(linkTo("Вернуться на главную", urla("index")));
  responsebody += QStringLiteral("\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(web_changeStatusView)

