#include <TreeFrogModel>
#include "breeddata.h"
#include "sqlobjects/breeddataobject.h"


BreedData::BreedData() :
    TAbstractModel(),
    d(new BreedDataObject())
{
    // set the initial parameters
}

BreedData::BreedData(const BreedData &other) :
    TAbstractModel(),
    d(other.d)
{ }

BreedData::BreedData(const BreedDataObject &object) :
    TAbstractModel(),
    d(new BreedDataObject(object))
{ }

BreedData::~BreedData()
{
    // If the reference count becomes 0,
    // the shared data object 'BreedDataObject' is deleted.
}

int BreedData::id() const
{
    return d->id;
}

QString BreedData::nameOfTheBreed() const
{
    return d->name_of_the_breed;
}

void BreedData::setNameOfTheBreed(const QString &nameOfTheBreed)
{
    d->name_of_the_breed = nameOfTheBreed;
}

double BreedData::putWeightHere() const
{
    return d->put_weight_here;
}

void BreedData::setPutWeightHere(double putWeightHere)
{
    d->put_weight_here = putWeightHere;
}

double BreedData::putHieghtHere() const
{
    return d->put_hieght_here;
}

void BreedData::setPutHieghtHere(double putHieghtHere)
{
    d->put_hieght_here = putHieghtHere;
}

double BreedData::putHere() const
{
    return d->put_here;
}

void BreedData::setPutHere(double putHere)
{
    d->put_here = putHere;
}

double BreedData::putElbowHere() const
{
    return d->put_elbow_here;
}

void BreedData::setPutElbowHere(double putElbowHere)
{
    d->put_elbow_here = putElbowHere;
}

double BreedData::putDepthHere() const
{
    return d->put_depth_here;
}

void BreedData::setPutDepthHere(double putDepthHere)
{
    d->put_depth_here = putDepthHere;
}

double BreedData::putChestHere() const
{
    return d->put_chest_here;
}

void BreedData::setPutChestHere(double putChestHere)
{
    d->put_chest_here = putChestHere;
}

double BreedData::putCircimferenceHere() const
{
    return d->put_circimference_here;
}

void BreedData::setPutCircimferenceHere(double putCircimferenceHere)
{
    d->put_circimference_here = putCircimferenceHere;
}

double BreedData::putHeadLengthHere() const
{
    return d->put_head_length_here;
}

void BreedData::setPutHeadLengthHere(double putHeadLengthHere)
{
    d->put_head_length_here = putHeadLengthHere;
}

double BreedData::putMuzzleHere() const
{
    return d->put_muzzle_here;
}

void BreedData::setPutMuzzleHere(double putMuzzleHere)
{
    d->put_muzzle_here = putMuzzleHere;
}

double BreedData::putSkullHere() const
{
    return d->put_skull_here;
}

void BreedData::setPutSkullHere(double putSkullHere)
{
    d->put_skull_here = putSkullHere;
}

double BreedData::putFoundingHere() const
{
    return d->put_founding_here;
}

void BreedData::setPutFoundingHere(double putFoundingHere)
{
    d->put_founding_here = putFoundingHere;
}

QString BreedData::createdAt() const
{
    return d->created_at;
}

BreedData &BreedData::operator=(const BreedData &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

BreedData BreedData::create(const QString &nameOfTheBreed, double putWeightHere, double putHieghtHere, double putHere, double putElbowHere, double putDepthHere, double putChestHere, double putCircimferenceHere, double putHeadLengthHere, double putMuzzleHere, double putSkullHere, double putFoundingHere)
{
    BreedDataObject obj;
    obj.name_of_the_breed = nameOfTheBreed;
    obj.put_weight_here = putWeightHere;
    obj.put_hieght_here = putHieghtHere;
    obj.put_here = putHere;
    obj.put_elbow_here = putElbowHere;
    obj.put_depth_here = putDepthHere;
    obj.put_chest_here = putChestHere;
    obj.put_circimference_here = putCircimferenceHere;
    obj.put_head_length_here = putHeadLengthHere;
    obj.put_muzzle_here = putMuzzleHere;
    obj.put_skull_here = putSkullHere;
    obj.put_founding_here = putFoundingHere;
    if (!obj.create()) {
        return BreedData();
    }
    return BreedData(obj);
}

BreedData BreedData::create(const QVariantMap &values)
{
    BreedData model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

BreedData BreedData::get(int id)
{
    TSqlORMapper<BreedDataObject> mapper;
    return BreedData(mapper.findByPrimaryKey(id));
}

int BreedData::count()
{
    TSqlORMapper<BreedDataObject> mapper;
    return mapper.findCount();
}

QList<BreedData> BreedData::getAll()
{
    return tfGetModelListByCriteria<BreedData, BreedDataObject>(TCriteria());
}

QJsonArray BreedData::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *BreedData::modelData()
{
    return d.data();
}

const TModelObject *BreedData::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const BreedData &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, BreedData &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}
