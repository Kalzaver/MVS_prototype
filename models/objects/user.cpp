#include <TreeFrogModel>
#include "user.h"
#include "sqlobjects/userobject.h"


User::User() :
    TAbstractUser(),
    TAbstractModel(),
    d(new UserObject())
{
    // set the initial parameters
}

User::User(const User &other) :
    TAbstractUser(),
    TAbstractModel(),
    d(other.d)
{ }

User::User(const UserObject &object) :
    TAbstractUser(),
    TAbstractModel(),
    d(new UserObject(object))
{ }


User::~User()
{
    // If the reference count becomes 0,
    // the shared data object 'UserObject' is deleted.
}

QString User::username() const
{
    return d->username;
}

void User::setUsername(const QString &username)
{
    d->username = username;
}

QString User::password() const
{
    return d->password;
}

void User::setPassword(const QString &password)
{
    d->password = password;
}

User &User::operator=(const User &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

User User::authenticate(const QString &username, const QString &password)
{
    if (username.isEmpty() || password.isEmpty())
        return User();

    TSqlORMapper<UserObject> mapper;
    UserObject obj = mapper.findFirst(TCriteria(UserObject::Username, username));
    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }
    return User(obj);
}

User User::create(const QString &username, const QString &password)
{
    UserObject obj;
    obj.username = username;
    obj.password = password;
    if (!obj.create()) {
        return User();
    }
    return User(obj);
}

User User::create(const QVariantMap &values)
{
    User model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

User User::get(const QString &username)
{
    TSqlORMapper<UserObject> mapper;
    return User(mapper.findByPrimaryKey(username));
}

User User::getByIdentityKey(const QString& username)
{
    TSqlORMapper<UserObject> mapper;
    TCriteria cri(UserObject::Username, username);
    return User(mapper.findFirst(cri));
}

int User::count()
{
    TSqlORMapper<UserObject> mapper;
    return mapper.findCount();
}

QList<User> User::getAll()
{
    return tfGetModelListByCriteria<User, UserObject>();
}

QJsonArray User::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *User::modelData()
{
    return d.data();
}

const TModelObject *User::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const User &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, User &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}
