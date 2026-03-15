#pragma once

#include "applicationcontroller.h"
#include <QSettings>

class T_CONTROLLER_EXPORT WebController : public ApplicationController
{
    Q_OBJECT
public:
    WebController() : ApplicationController() { }

private:
    QString m_pythonPath;
    QString m_templatePath;
    QString m_copyPath;
    QString m_jsonPath;
    QString m_scriptPath;
    QString m_scriptPathCopy;

public slots:
    
    bool loadConfig();
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

