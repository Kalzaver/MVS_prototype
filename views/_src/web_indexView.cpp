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
  responsebody.reserve(3946);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\r\n  <style>\r\n      body {\r\n        display: grid;\r\n        grid-template-columns: repeat(5, 1fr);\r\n        margin: 0;\r\n        padding: 20px;\r\n        gap: 10px; /* отступы между колонками, при желании */\r\n      }\r\n\r\n      /* Контейнер с кнопками занимает колонки со 2 по 4 */\r\n      .container {\r\n        grid-column: 2 / 5; /* с линии 2 до линии 5 (колонки 2,3,4) */\r\n        display: grid;\r\n        grid-template-columns: repeat(3, 1fr); /* три внутренние колонки */\r\n        gap: 10px; /* отступы между внутренними колонками */\r\n        background: #f5f5f5; /* для наглядности, можно убрать */\r\n        padding: 20px;\r\n        border-radius: 8px;\r\n      }\r\n\r\n      /* Скрываем <br> внутри контейнера, чтобы они не ломали сетку */\r\n      .container > br {\r\n        display: none;\r\n      }\r\n\r\n      /* Все кнопки внутри контейнера */\r\n      .container > button {\r\n        /* Размещение по колонкам: нечётные – в первую внутреннюю (глобальная колонка 2),\r\n          чётные – в третью внутреннюю (глобальная колонка 4) */\r\n        grid-column: 1; /* значение по умолчанию для нечётных */\r\n        white-space: normal;   /* разрешаем перенос текста */\r\n        word-wrap: break-word; /* перенос длинных слов */\r\n        padding: 12px 16px;\r\n        border: none;\r\n        background-color: #007bff;\r\n        color: white;\r\n        font-size: 16px;\r\n        border-radius: 4px;\r\n        cursor: pointer;\r\n        transition: background-color 0.3s;\r\n        width: 100%;          /* кнопка занимает всю ширину колонки */\r\n        box-sizing: border-box;\r\n      }\r\n\r\n      /* Чётные кнопки помещаем в третью колонку */\r\n      .container > button:nth-child(even) {\r\n        grid-column: 3;\r\n      }\r\n\r\n      /* Стили для ссылок внутри кнопок (если linkTo генерирует <a>) */\r\n      .container > button a {\r\n        color: inherit;\r\n        text-decoration: none;\r\n        display: block;\r\n        width: 100%;\r\n        height: 100%;\r\n      }\r\n\r\n      /* Эффект при наведении */\r\n      .container > button:hover {\r\n        background-color: #0056b3;\r\n      }\r\n\r\n      .user-info {\r\n        grid-column: 5 / 6;\r\n        text-align: right;\r\n        padding: 10px;\r\n        background: #e9ecef;\r\n        border-radius: 8px;\r\n        font-size: 14px;\r\n        margin-bottom: 10px;\r\n      }\r\n      \r\n      .user-info p {\r\n        grid-column: 1 / 6;\r\n      }\r\n\r\n  </style>\r\n</head>\r\n<body>\r\n\r\n<h1>Главное меню</h1>\r\n<p>Достпные к заполнению шаблоны документов РКФ</p>\r\n\r\n<div class=\"user-info\">\r\n    ");
  tfetch(QString, username);
  responsebody += QStringLiteral(" <p>");
  eh(username);
  responsebody += QStringLiteral("</p>\r\n    <button type=\"button\">");
  echo(linkTo("Выйти", QUrl("http://localhost:8800/account/form")));
  responsebody += QStringLiteral("</button>\r\n</div>\r\n\r\n<div class=\"container\">\r\n  <button type=\"button\">");
  echo(linkTo("племенной смотр", urla("changePage")));
  responsebody += QStringLiteral("</button>\r\n  <button type=\"button\">");
  echo(linkTo("отчёт главного судьи", urla("mainReport")));
  responsebody += QStringLiteral("</button>\r\n\r\n  <button type=\"button\">");
  echo(linkTo("заявка на проведение племенного смотра", urla("ReqBreed")));
  responsebody += QStringLiteral("</button>\r\n  <button type=\"button\">");
  echo(linkTo("заявка на присвоение титула", urla("ReqTitul")));
  responsebody += QStringLiteral("</button>\r\n\r\n  <button type=\"button\">");
  echo(linkTo("реестр получения документов", urla("Reesrt")));
  responsebody += QStringLiteral("</button>\r\n</div>\r\n\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(web_indexView)

