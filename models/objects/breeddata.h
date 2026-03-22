#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class BreedDataObject;
class QJsonArray;


class T_MODEL_EXPORT BreedData : public TAbstractModel {
public:
    BreedData();
    BreedData(const BreedData &other);
    BreedData(const BreedDataObject &object);
    ~BreedData();

    int id() const;
    QString nameOfTheBreed() const;
    void setNameOfTheBreed(const QString &nameOfTheBreed);

    double putWeightHere() const;
    void setPutWeightHere(double putWeightHere);

    double putHieghtHere() const;
    void setPutHieghtHere(double putHieghtHere);

    double putHere() const;
    void setPutHere(double putHere);

    double putElbowHere() const;
    void setPutElbowHere(double putElbowHere);

    double putDepthHere() const;
    void setPutDepthHere(double putDepthHere);

    double putChestHere() const;
    void setPutChestHere(double putChestHere);

    double putCircimferenceHere() const;
    void setPutCircimferenceHere(double putCircimferenceHere);

    double putHeadLengthHere() const;
    void setPutHeadLengthHere(double putHeadLengthHere);

    double putMuzzleHere() const;
    void setPutMuzzleHere(double putMuzzleHere);

    double putSkullHere() const;
    void setPutSkullHere(double putSkullHere);

    double putFoundingHere() const;
    void setPutFoundingHere(double putFoundingHere);

    QString createdAt() const;
    BreedData &operator=(const BreedData &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static BreedData create(const QString &nameOfTheBreed, double putWeightHere, double putHieghtHere, 
        double putHere, double putElbowHere, double putDepthHere, double putChestHere, double putCircimferenceHere, 
        double putHeadLengthHere, double putMuzzleHere, double putSkullHere, double putFoundingHere);
    static BreedData create(const QVariantMap &values);
    static BreedData get(int id);
    static int count();
    static QList<BreedData> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<BreedDataObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const BreedData &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, BreedData &model);
};

Q_DECLARE_METATYPE(BreedData)
Q_DECLARE_METATYPE(QList<BreedData>)

