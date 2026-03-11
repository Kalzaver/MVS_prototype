#include "breedmodel.h"
#include <QJsonDocument>
#include <TWebApplication>

BreedModel::BreedModel(QObject* parent) : QObject(parent) {
    // Резервируем место под 88 колонок
    for (int i = 0; i < 88; ++i) m_headers << QString("col_%1").arg(i);
}

void BreedModel::initModel() {
    // Массив заголовков (ключей JSON)
    m_headers[0] = "NamePutOfTheClubHere";
    m_headers[1] = "NameOfTheBreed";
    m_headers[2] = "NameOfTheDog";
    m_headers[3] = "NumberFromRKFBase";
    m_headers[4] = "PuthTheChipHere";
    m_headers[5] = "HereIsYourFather";
    m_headers[6] = "HereIsYourMother";
    m_headers[7] = "hoIsTheBreeder";
    m_headers[8] = "WhoIsTheOwner";
    m_headers[9] = "PutYourCurrentAdress";
    m_headers[10] = "PutWeightHere";
    m_headers[11] = "PutHieghtHere";
    m_headers[12] = "PutHere";
    m_headers[13] = "PutElbowHere";
    m_headers[14] = "PutDepthHere";
    m_headers[15] = "PutChestHere";
    m_headers[16] = "PutCircimferenceHere";
    m_headers[17] = "PutHeadLengthHere";
    m_headers[18] = "PutMuzzleHere";
    m_headers[19] = "PutSkullHere";
    m_headers[20] = "PutfoundingHere";
    m_headers[21] = "SomeKindOfComments1";
    m_headers[22] = "SomeKindOfComments2";
    m_headers[23] = "SomeKindOfComments3";
    m_headers[24] = "SomeKindOfComments4";
    m_headers[25] = "SomeKindOfComments5";
    m_headers[26] = "SomeKindOfComments6";
    m_headers[27] = "howManyTeethWereMissed";
    m_headers[28] = "000";
    m_headers[29] = "isThereAreDoubleTeeth";
    m_headers[30] = "111";
    m_headers[31] = "010";
    m_headers[32] = "121";
    m_headers[33] = "020";
    m_headers[34] = "131";
    m_headers[35] = "030";
    m_headers[36] = "141";
    m_headers[37] = "040";
    m_headers[38] = "151";
    m_headers[39] = "050";
    m_headers[40] = "161";
    m_headers[41] = "060";
    m_headers[42] = "070";
    m_headers[43] = "171";
    m_headers[44] = "070";
    m_headers[45] = "181";
    m_headers[46] = "080";
    m_headers[47] = "HereYourNotes";
    m_headers[48] = "commentNeck";
    m_headers[49] = "commentBack";
    m_headers[50] = "commentCroup";
    m_headers[51] = "commentTail";
    m_headers[52] = "commentChect";
    m_headers[53] = "commentShoulders";
    m_headers[54] = "commentAngu";
    m_headers[55] = "commentFurr";
    m_headers[56] = "commentColor";
    m_headers[57] = "commentMoves";
    m_headers[58] = "commentBehave";
    m_headers[59] = "aaa";
    m_headers[60] = "bbb";
    m_headers[61] = "ccc";
    m_headers[62] = "ddd";
    m_headers[63] = "eee";
    m_headers[64] = "fff";
    m_headers[65] = "ggg";
    m_headers[66] = "hhh";
    m_headers[67] = "iii";
    m_headers[68] = "jjj";
    m_headers[69] = "kkk";
    m_headers[70] = "lll";
    m_headers[71] = "mmm";
    m_headers[72] = "nnn";
    m_headers[73] = "ooo";
    m_headers[74] = "ppp";
    m_headers[75] = "qqq";
    m_headers[76] = "rrr";
    m_headers[77] = "sss";
    m_headers[78] = "ttt";
    m_headers[79] = "uuu";
    m_headers[80] = "vvv";
    m_headers[81] = "www";
    m_headers[82] = "xxx";
    m_headers[83] = "yyy";
    m_headers[84] = "zzz";
    m_headers[85] = "isthereanyspecificqualitieshere";
    m_headers[86] = "isthereanyspecificfaultshere";
    m_headers[87] = "isthereanyrecomendstionshere";

    // Установка значений по умолчанию (вместо setData)
    for (int i = 30; i <= 46; ++i) setField(i, " - ");
    for (int i = 58; i <= 83; ++i) setField(i, " - ");
}

void BreedModel::setField(int column, const QVariant& value) {
    if (column >= 0 && column < m_headers.size()) {
        m_values.insert(m_headers[column], QJsonValue::fromVariant(value));
    }
}

QVariant BreedModel::getField(int column) const
{
    if (column >= 0 && column < m_headers.size()) {
        return m_values.value(m_headers[column]);
    }
    return QVariant();
}

QByteArray BreedModel::toJson() const {
    QJsonDocument doc(m_values);
    return doc.toJson();
}
