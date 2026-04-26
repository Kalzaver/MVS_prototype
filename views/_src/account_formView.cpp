#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_formView : public TActionView
{
public:
  account_formView() : TActionView() { }
  QString toString();
};

QString account_formView::toString()
{
  responsebody.reserve(818);
  responsebody += QStringLiteral("<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n</head>\r\n<body>\r\n  <h1>Login Form</h1>\r\n  <div style=\"color: red;\">");
  techoex(message);
  responsebody += QStringLiteral("</div>\r\n\r\n  <button type=\"button\">");
  echo(linkTo("Регистрация", urla("regist")));
  responsebody += QStringLiteral("</button>\r\n\r\n  ");
  echo(formTag(urla("login")));
  responsebody += QStringLiteral("\r\n    <div>\r\n      User Name: <input type=\"text\" name=\"username\" value=\"\" />\r\n    </div>\r\n    <div>\r\n      Password: <input type=\"password\" name=\"password\" value=\"\" />\r\n    </div>\r\n    <div>\r\n      <input type=\"submit\" value=\"Login\" />\r\n    </div>\r\n  </form>\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(account_formView)

