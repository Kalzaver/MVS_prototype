#include "blogservice.h"
#include "objects/blog.h"
#include <TreeFrogModel>


void BlogService::index()
{
    auto blogList = Blog::getAll();
    texport(blogList);
}

void BlogService::show(int id)
{
    auto blog = Blog::get(id);
    texport(blog);
}

int BlogService::create(THttpRequest &request)
{
    auto blog = request.formItems("blog");
    auto model = Blog::create(blog);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        texport(blog);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void BlogService::edit(TSession& session, int id)
{
    auto model = Blog::get(id);
    if (!model.isNull()) {
        session.insert("blog_lockRevision", model.lockRevision());
        auto blog = model.toVariantMap();
        texport(blog);
    }
}

int BlogService::save(THttpRequest &request, TSession &session, int id)
{
    int rev = session.value("blog_lockRevision").toInt();
    auto model = Blog::get(id, rev);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto blog = request.formItems("blog");
    model.setProperties(blog);
    if (!model.save()) {
        texport(blog);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool BlogService::remove(int id)
{
    auto blog = Blog::get(id);
    return blog.remove();
}

