#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT BreedDataObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    QString name_of_the_breed;
    double put_weight_here {0};
    double put_hieght_here {0};
    double put_here {0};
    double put_elbow_here {0};
    double put_depth_here {0};
    double put_chest_here {0};
    double put_circimference_here {0};
    double put_head_length_here {0};
    double put_muzzle_here {0};
    double put_skull_here {0};
    double put_founding_here {0};
    QString created_at;

    enum PropertyIndex {
        Id = 0,
        NameOfTheBreed,
        PutWeightHere,
        PutHieghtHere,
        PutHere,
        PutElbowHere,
        PutDepthHere,
        PutChestHere,
        PutCircimferenceHere,
        PutHeadLengthHere,
        PutMuzzleHere,
        PutSkullHere,
        PutFoundingHere,
        CreatedAt,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("breed_data"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name_of_the_breed READ getname_of_the_breed WRITE setname_of_the_breed)
    T_DEFINE_PROPERTY(QString, name_of_the_breed)
    Q_PROPERTY(double put_weight_here READ getput_weight_here WRITE setput_weight_here)
    T_DEFINE_PROPERTY(double, put_weight_here)
    Q_PROPERTY(double put_hieght_here READ getput_hieght_here WRITE setput_hieght_here)
    T_DEFINE_PROPERTY(double, put_hieght_here)
    Q_PROPERTY(double put_here READ getput_here WRITE setput_here)
    T_DEFINE_PROPERTY(double, put_here)
    Q_PROPERTY(double put_elbow_here READ getput_elbow_here WRITE setput_elbow_here)
    T_DEFINE_PROPERTY(double, put_elbow_here)
    Q_PROPERTY(double put_depth_here READ getput_depth_here WRITE setput_depth_here)
    T_DEFINE_PROPERTY(double, put_depth_here)
    Q_PROPERTY(double put_chest_here READ getput_chest_here WRITE setput_chest_here)
    T_DEFINE_PROPERTY(double, put_chest_here)
    Q_PROPERTY(double put_circimference_here READ getput_circimference_here WRITE setput_circimference_here)
    T_DEFINE_PROPERTY(double, put_circimference_here)
    Q_PROPERTY(double put_head_length_here READ getput_head_length_here WRITE setput_head_length_here)
    T_DEFINE_PROPERTY(double, put_head_length_here)
    Q_PROPERTY(double put_muzzle_here READ getput_muzzle_here WRITE setput_muzzle_here)
    T_DEFINE_PROPERTY(double, put_muzzle_here)
    Q_PROPERTY(double put_skull_here READ getput_skull_here WRITE setput_skull_here)
    T_DEFINE_PROPERTY(double, put_skull_here)
    Q_PROPERTY(double put_founding_here READ getput_founding_here WRITE setput_founding_here)
    T_DEFINE_PROPERTY(double, put_founding_here)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
};

