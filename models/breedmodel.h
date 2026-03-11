#ifndef BREEDMODEL_H
#define BREEDMODEL_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include <QStringList>

class BreedModel : public QObject {
    //Q_OBJECT
public:
    explicit BreedModel(QObject* parent = nullptr);
    void initModel();
    void setField(int column, const QVariant& value);
    QVariant getField(int column) const;
    QByteArray toJson() const;

private:
    QStringList m_headers;
    QJsonObject m_values;
};

#endif
