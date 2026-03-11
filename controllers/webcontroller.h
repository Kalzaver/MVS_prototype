#pragma once

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WebController : public ApplicationController
{
    Q_OBJECT
public:
    WebController() : ApplicationController() { }

public slots:
    void replaceScript();
    void copyScript();
    void index();
    void changePage();
    void mainReport();
    //void ReqBreed();
    //void ReqTitul();
    //void Reesrt();
    void submitForm();
    bool preFilter();
};

