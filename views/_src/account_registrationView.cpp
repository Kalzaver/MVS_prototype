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
  responsebody.reserve(3130);
  responsebody += tr("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>Регистрация</title>\r\n  <style>\r\n      body {\r\n        margin: 0;\r\n        padding: 20px;\r\n        font-family: sans-serif;\r\n        background: #f5f5f5;\r\n        display: flex;\r\n        justify-content: center;\r\n        align-items: center;\r\n        min-height: 100vh;\r\n      }\r\n      .grid-form {\r\n        display: grid;\r\n        grid-template-columns: minmax(180px, auto) 1fr;\r\n        gap: 20px 15px;\r\n        align-items: center;\r\n        max-width: 600px;\r\n        width: 100%;\r\n        background: white;\r\n        padding: 30px;\r\n        border-radius: 12px;\r\n        box-shadow: 0 4px 12px rgba(0,0,0,0.1);\r\n      }\r\n      .grid-form label {\r\n        font-weight: 600;\r\n        text-align: right;\r\n        padding-right: 15px;\r\n        font-size: 16px;\r\n        color: #333;\r\n      }\r\n      .grid-form input[type=\"text\"],\r\n      .grid-form input[type=\"password\"] {\r\n        width: 100%;\r\n        padding: 12px 15px;\r\n        font-size: 16px;\r\n        border: 2px solid #ddd;\r\n        border-radius: 8px;\r\n        box-sizing: border-box;\r\n      }\r\n      .grid-form input:focus {\r\n        border-color: #007bff;\r\n        outline: none;\r\n      }\r\n      .error {\r\n        grid-column: 2 / 3;\r\n        color: red;\r\n        font-size: 14px;\r\n      }\r\n      .actions {\r\n        grid-column: 2 / 3;\r\n        display: flex;\r\n        gap: 20px;\r\n        margin-top: 20px;\r\n      }\r\n      .actions a, .actions input[type=\"submit\"] {\r\n        padding: 12px 28px;\r\n        background-color: #007bff;\r\n        color: white;\r\n        text-decoration: none;\r\n        border: none;\r\n        border-radius: 8px;\r\n        cursor: pointer;\r\n        font-size: 16px;\r\n        font-weight: 500;\r\n      }\r\n      .actions a:hover, .actions input[type=\"submit\"]:hover {\r\n        background-color: #0056b3;\r\n      }\r\n      h1 { text-align: center; margin-bottom: 20px; font-size: 28px; }\r\n  </style>\r\n</head>\r\n<body>\r\n<div>\r\n  <h1>Регистрация</h1>\r\n  <div class=\"grid-form\">\r\n    ");
  echo(formTag(urla("regist"), Tf::Post));
  responsebody += tr("\r\n      <label for=\"username\">Логин</label>\r\n      <input type=\"text\" name=\"username\" id=\"username\" required>\r\n      <div style=\"color: red;\">");
  techoex(message);
  responsebody += tr("</div>\r\n\r\n      <label for=\"password\">Пароль</label>\r\n      <input type=\"password\" name=\"password\" id=\"password\" required>\r\n      <div style=\"color: red;\">");
  techoex(message);
  responsebody += tr("</div>\r\n\r\n      <label for=\"password2\">Повторите пароль</label>\r\n      <input type=\"password\" name=\"password2\" id=\"password2\" required>\r\n      <div style=\"color: red;\">");
  techoex(message);
  responsebody += tr("</div>\r\n\r\n      <div class=\"actions\">\r\n        <input type=\"submit\" value=\"Создать аккаунт\">\r\n      </div>\r\n    </form>\r\n  </div>\r\n</div>\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(account_registrationView)

