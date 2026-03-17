#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT web_reportpageView : public TActionView
{
public:
  web_reportpageView() : TActionView() { }
  QString toString();
};

QString web_reportpageView::toString()
{
  responsebody.reserve(5132);
  responsebody += tr("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>Другая страница</title>\r\n  <style>\r\n      body {\r\n        margin: 0;\r\n        padding: 20px;\r\n        font-family: sans-serif;\r\n        background: #f5f5f5;\r\n      }\r\n\r\n      .grid-form {\r\n        display: grid;\r\n        grid-template-columns: minmax(200px, 1fr) minmax(200px, 1fr) repeat(3, 1fr);\r\n        gap: 20px 15px;\r\n        align-items: center;\r\n        max-width: 1400px;\r\n        margin: 0 auto;\r\n        background: white;\r\n        padding: 30px;\r\n        border-radius: 12px;\r\n        box-shadow: 0 4px 12px rgba(0,0,0,0.1);\r\n      }\r\n\r\n      .field {\r\n        display: contents;\r\n      }\r\n\r\n      .field label {\r\n        grid-column: 1 / 3;\r\n        font-weight: 600;\r\n        text-align: left;\r\n        padding-right: 15px;\r\n        font-size: 16px;\r\n        color: #333;\r\n      }\r\n\r\n      .field input,\r\n      .field select,\r\n      .field textarea {\r\n        grid-column: 3 / 6;\r\n        width: 100%;\r\n        box-sizing: border-box;\r\n        padding: 12px 15px;\r\n        font-size: 16px;\r\n        border: 2px solid #ddd;\r\n        border-radius: 8px;\r\n        transition: border-color 0.2s;\r\n      }\r\n\r\n      .field input:focus,\r\n      .field select:focus,\r\n      .field textarea:focus {\r\n        border-color: #007bff;\r\n        outline: none;\r\n      }\r\n\r\n      .photo {\r\n        grid-column: 2 / 5;\r\n        text-align: center;\r\n        margin: 20px 0;\r\n      }\r\n\r\n      .photo img {\r\n        width: 100%;              /* растягиваем на всю ширину родителя */\r\n        max-height: 300px;        /* ограничиваем высоту, чтобы не вылезало */\r\n        height: auto;             /* сохраняем пропорции */\r\n        object-fit: contain;      /* вписываем изображение в отведённую область без обрезания */\r\n        display: block;           /* убираем лишние отступы */\r\n        margin: 0 auto;           /* центрирование (при необходимости) */\r\n        border-radius: 8px;\r\n        box-shadow: 0 2px 8px rgba(0,0,0,0.1);\r\n      }\r\n\r\n      .radio-row {\r\n        display: contents;\r\n      }\r\n\r\n      .radio-row .label-text {\r\n        grid-column: 1 / 3;\r\n        text-align: left;\r\n        padding-right: 15px;\r\n        font-weight: 600;\r\n        font-size: 16px;\r\n        color: #333;\r\n      }\r\n\r\n      .radio-row .radio-group {\r\n        grid-column: 3 / 6;\r\n        display: flex;\r\n        flex-wrap: wrap;\r\n        gap: 20px;\r\n        align-items: center;\r\n      }\r\n\r\n      .radio-group label {\r\n        display: inline-flex;\r\n        align-items: center;\r\n        gap: 8px;\r\n        font-weight: normal;\r\n        font-size: 16px;\r\n        cursor: pointer;\r\n      }\r\n\r\n      .radio-group input[type=\"radio\"] {\r\n        width: 18px;\r\n        height: 18px;\r\n        cursor: pointer;\r\n      }\r\n\r\n      .actions {\r\n        grid-column: 2 / 5;\r\n        display: flex;\r\n        justify-content: space-between;\r\n        margin-top: 30px;\r\n      }\r\n\r\n      .actions a,\r\n      .actions input[type=\"submit\"] {\r\n        padding: 14px 28px;\r\n        background-color: #007bff;\r\n        color: white;\r\n        text-decoration: none;\r\n        border: none;\r\n        border-radius: 8px;\r\n        cursor: pointer;\r\n        font-size: 18px;\r\n        font-weight: 500;\r\n        transition: background-color 0.2s;\r\n      }\r\n\r\n      .actions a:hover,\r\n      .actions input[type=\"submit\"]:hover {\r\n        background-color: #0056b3;\r\n      }\r\n\r\n      @media (max-width: 2000px) {\r\n        .grid-form {\r\n          grid-template-columns: 1fr;\r\n          padding: 20px;\r\n        }\r\n        \r\n        .field label,\r\n        .field input,\r\n        .radio-row .label-text,\r\n        .radio-row .radio-group,\r\n        .photo,\r\n        .actions {\r\n          grid-column: 1 / -1;\r\n        }\r\n        \r\n        .field label,\r\n        .radio-row .label-text {\r\n          text-align: left;\r\n          margin-bottom: 5px;\r\n        }\r\n      }\r\n  </style>\r\n</head>\r\n<body>\r\n    ");
  tfetch(QString, newTitle);
  responsebody += QStringLiteral("    <h1>");
  eh(newTitle);
  responsebody += QStringLiteral("</h1>\r\n\r\n    ");
  tfetch(QString, pathValue);
  responsebody += QStringLiteral("    <p>");
  eh(pathValue);
  responsebody += QStringLiteral("</p>\r\n\r\n       <div class=\"reportContainer grid-form\">\r\n      ");
  echo(formTag(urla("submitReport"), Tf::Post));
  responsebody += tr("\r\n        <div class=\"field\">\r\n          <label>Полное название клуба</label>\r\n          <input type=\"text\"    name=\"test\">\r\n        </div>\r\n\r\n      \r\n        <div class=\"actions\">\r\n          ");
  echo(linkTo("Вернуться на главную", urla("index")));
  responsebody += tr("\r\n          <input type=\"submit\" value=\"Отправить в Qt\">\r\n        </div>\r\n      </form>\r\n   </div>\r\n\r\n</body>\r\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(web_reportpageView)

