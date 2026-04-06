#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserObject : public TSqlObject, public QSharedData {
public:
    QString username;
    QString password;

    enum PropertyIndex {
        Username = 0,
        Password,
    };

    int primaryKeyIndex() const override { return Username; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QStringLiteral("user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
};

