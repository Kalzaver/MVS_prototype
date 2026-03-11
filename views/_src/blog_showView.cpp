#include <QtCore>
#include <TreeFrogView>
#include "objects/blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_showView : public TActionView
{
public:
  blog_showView() : TActionView() { }
  QString toString();
};

QString blog_showView::toString()
{
  responsebody.reserve(1282);
  responsebody += QStringLiteral("<!DOCTYPE html>\r\n");
    tfetch(Blog, blog);
  responsebody += QStringLiteral("<html>\r\n<head>\r\n  <meta charset=\"UTF-8\">\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\r\n\r\n<h1>Showing Blog</h1>\r\n<dt>ID</dt><dd>");
  eh(blog.id());
  responsebody += QStringLiteral("</dd><br>\r\n<dt>Title</dt><dd>");
  eh(blog.title());
  responsebody += QStringLiteral("</dd><br>\r\n<dt>Body</dt><dd>");
  eh(blog.body());
  responsebody += QStringLiteral("</dd><br>\r\n<dt>Created at</dt><dd>");
  eh(blog.createdAt());
  responsebody += QStringLiteral("</dd><br>\r\n<dt>Updated at</dt><dd>");
  eh(blog.updatedAt());
  responsebody += QStringLiteral("</dd><br>\r\n<dt>Lock Revision</dt><dd>");
  eh(blog.lockRevision());
  responsebody += QStringLiteral("</dd><br>\r\n\r\n");
  echo(linkTo("Edit", urla("save", blog.id())));
  responsebody += QStringLiteral(" |\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QStringLiteral("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_showView)

