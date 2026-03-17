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
    QString rj_jsonPath;

    QString m_scriptPath;

    QString m_scriptPathCopy;

    QString m_configPath;


public slots:
    
    bool loadConfig();
    void index();
    void changePage();
    void mainReport();
    void copyScriptForSection(const QString& section);
    void replaceScriptForSection(const QString& section);
    bool loadConfigForSection(const QString& section);
    //void ReqBreed();
    //void ReqTitul();
    //void Reesrt();
    void submitForm();
    void submitReport();
    bool preFilter();
    void copyScript();
    void replaceScript();
};

