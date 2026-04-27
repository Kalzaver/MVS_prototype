#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_registrationView : public TActionView
{
public:
  account_registrationView() : TActionView() { }
  QString toString();
};

QString account_registrationView::toString()
{
  responsebody.reserve(1213);
  responsebody += tr("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>Регистрация</title>\r\n\r\n</head>\r\n<body>\r\n<div>\r\n  <h1>Регистрация</h1>\r\n  <div class=\"grid-form\">\r\n    ");
  echo(formTag(urla("regist"), Tf::Post));
  responsebody += tr("\r\n      <label for=\"username\">Логин</label>\r\n      <input type=\"text\" name=\"username\" id=\"username\" >\r\n      <div style=\"color: red;\">");
  techoex(message_UN);
  responsebody += QStringLiteral("</div>\r\n      <div style=\"color: red;\">");
  techoex(message);
  responsebody += tr("</div>\r\n\r\n      <label for=\"password\">Пароль</label>\r\n      <input type=\"password\" name=\"password\" id=\"password\" >\r\n      <div style=\"color: red;\">");
  techoex(message_PW1);
  responsebody += tr("</div>\r\n\r\n      <label for=\"password2\">Повторите пароль</label>\r\n      <input type=\"password\" name=\"password2\" id=\"password2\" >\r\n      <div style=\"color: red;\">");
  techoex(message_PW2);
  responsebody += tr("</div>\r\n\r\n      <div class=\"actions\">\r\n        <input type=\"submit\" value=\"Создать аккаунт\">\r\n      </div>\r\n    </form>\r\n  </div>\r\n</div>\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(account_registrationView)

