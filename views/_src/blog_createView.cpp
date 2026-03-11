#include <QtCore>
#include <TreeFrogView>
#include "objects/blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_createView : public TActionView
{
public:
  blog_createView() : TActionView() { }
  QString toString();
};

QString blog_createView::toString()
{
  responsebody.reserve(1101);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n");
    tfetch(QVariantMap, blog);
  responsebody += QStringLiteral("<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\r\n\r\n<h1>New Blog</h1>\r\n\r\n");
  echo(formTag(urla("create"), Tf::Post));
  responsebody += QStringLiteral("\r\n  <p>\r\n    <label>Title<br><input name=\"blog[title]\" value=\"");
  eh(blog["title"]);
  responsebody += QStringLiteral("\" /></label>\r\n  </p>\r\n  <p>\r\n    <label>Body<br><input name=\"blog[body]\" value=\"");
  eh(blog["body"]);
  responsebody += QStringLiteral("\" /></label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Create\" />\r\n  </p>\r\n</form>\r\n\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QStringLiteral("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_createView)

