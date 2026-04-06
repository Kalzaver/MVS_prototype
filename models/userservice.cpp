#include "userservice.h"
#include "objects/user.h"
#include <TreeFrogModel>


void UserService::index()
{
    auto userList = User::getAll();
    texport(userList);
}

void UserService::show(const QString &username)
{
    auto user = User::get(username);
    texport(user);
}

QString UserService::create(THttpRequest &request)
{
    auto user = request.formItems("user");
    auto model = User::create(user);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        texport(user);
        return QString();
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.username();
}

void UserService::edit(TSession& session, const QString &username)
{
    auto model = User::get(username);
    if (!model.isNull()) {
        auto user = model.toVariantMap();
        texport(user);
    }
}

int UserService::save(THttpRequest &request, TSession &session, const QString &username)
{
    auto model = User::get(username);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto user = request.formItems("user");
    model.setProperties(user);
    if (!model.save()) {
        texport(user);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool UserService::remove(const QString &username)
{
    auto user = User::get(username);
    return user.remove();
}

