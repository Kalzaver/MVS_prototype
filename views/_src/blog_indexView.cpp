#include <QtCore>
#include <TreeFrogView>
#include "objects/blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_indexView : public TActionView
{
public:
  blog_indexView() : TActionView() { }
  QString toString();
};

QString blog_indexView::toString()
{
  responsebody.reserve(1391);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n");
    responsebody += QStringLiteral("<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\r\n</head>\r\n<body>\r\n\r\n<h1>Listing Blog</h1>\r\n\r\n");
  echo(linkTo("Create a new Blog", urla("create")));
  responsebody += QStringLiteral("<br>\r\n<br>\r\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\r\n  <tr>\r\n    <th>ID</th>\r\n    <th>Title</th>\r\n    <th>Body</th>\r\n  </tr>\r\n");
  tfetch(QList<Blog>, blogList);
  for (const auto &i : blogList) {
  responsebody += QStringLiteral("  <tr>\r\n    <td>");
  eh(i.id());
  responsebody += QStringLiteral("</td>\r\n    <td>");
  eh(i.title());
  responsebody += QStringLiteral("</td>\r\n    <td>");
  eh(i.body());
  responsebody += QStringLiteral("</td>\r\n    <td>\r\n      ");
  echo(linkTo("Show", urla("show", i.id())));
  responsebody += QStringLiteral("\r\n      ");
  echo(linkTo("Edit", urla("save", i.id())));
  responsebody += QStringLiteral("\r\n      ");
  echo(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')"));
  responsebody += QStringLiteral("\r\n    </td>\r\n  </tr>\r\n");
  };
  responsebody += QStringLiteral("</table>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_indexView)

