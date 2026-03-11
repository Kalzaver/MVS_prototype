#include <QtCore>
#include <TreeFrogView>
#include "objects/blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_saveView : public TActionView
{
public:
  blog_saveView() : TActionView() { }
  QString toString();
};

QString blog_saveView::toString()
{
  responsebody.reserve(1409);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n");
    tfetch(QVariantMap, blog);
  responsebody += QStringLiteral("<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\r\n\r\n<h1>Editing Blog</h1>\r\n\r\n");
  echo(formTag(urla("save", blog["id"]), Tf::Post));
  responsebody += QStringLiteral("\r\n  <p>\r\n    <label>ID<br><input type=\"text\" name=\"blog[id]\" value=\"");
  eh(blog["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\r\n  </p>\r\n  <p>\r\n    <label>Title<br><input type=\"text\" name=\"blog[title]\" value=\"");
  eh(blog["title"]);
  responsebody += QStringLiteral("\" /></label>\r\n  </p>\r\n  <p>\r\n    <label>Body<br><input type=\"text\" name=\"blog[body]\" value=\"");
  eh(blog["body"]);
  responsebody += QStringLiteral("\" /></label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Save\" />\r\n  </p>\r\n</form>\r\n\r\n");
  echo(linkTo("Show", urla("show", blog["id"])));
  responsebody += QStringLiteral(" |\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QStringLiteral("\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_saveView)

