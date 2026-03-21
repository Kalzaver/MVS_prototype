#include "breeddataservice.h"
#include "objects/breeddata.h"
#include <TreeFrogModel>


void BreedDataService::index()
{
    auto breedDataList = BreedData::getAll();
    texport(breedDataList);
}

void BreedDataService::show(int id)
{
    auto breedData = BreedData::get(id);
    texport(breedData);
}

int BreedDataService::create(THttpRequest &request)
{
    auto breedData = request.formItems("breedData");
    auto model = BreedData::create(breedData);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        texport(breedData);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void BreedDataService::edit(TSession& session, int id)
{
    auto model = BreedData::get(id);
    if (!model.isNull()) {
        auto breedData = model.toVariantMap();
        texport(breedData);
    }
}

int BreedDataService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = BreedData::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto breedData = request.formItems("breedData");
    model.setProperties(breedData);
    if (!model.save()) {
        texport(breedData);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool BreedDataService::remove(int id)
{
    auto breedData = BreedData::get(id);
    return breedData.remove();
}

