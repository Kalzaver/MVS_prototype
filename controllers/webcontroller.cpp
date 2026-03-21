#include "webcontroller.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>

void WebController::index()
{
    // write code
	QString title = "Вы в главном меню"; // Или данные из БД
	texport(title); // Экспортируем переменную в View
	render();
}

void WebController::changePage()
{
    // Пример: получаем параметр из запроса (если передавали через GET)
    QString newTitle = httpRequest().queryItemValue("title");
    if (newTitle.isEmpty())
        newTitle = "Заполнение документа по племенному смотру";

    texport(newTitle);   // передаём в шаблон
    render("change");    // явно указываем имя шаблона (change.erb)
}

void WebController::mainReport()
{
    QString newTitle = httpRequest().queryItemValue("title");
    if (newTitle.isEmpty())
        newTitle = "Заполнение отчёта главного судьи";

    texport(newTitle);

    loadConfigForSection("TemplateReport");
    QString pathValue = m_scriptPath;

    if (pathValue.isEmpty())
        newTitle = "тут пусто";

    texport(pathValue);
    render("reportpage");
}

void WebController::copyScriptForSection(const QString& section)
{
    loadConfigForSection(section);

    if (QFile::exists(m_copyPath))
        QFile::remove(m_copyPath);

    QFile::copy(m_templatePath, m_copyPath);
}

void WebController::replaceScriptForSection(const QString& section)
{
    loadConfigForSection(section);

    QStringList args;
    args << m_scriptPath << m_configPath << section;

    QProcess::startDetached(m_pythonPath, args);
}

bool WebController::loadConfigForSection(const QString& section)
{
    QSettings settings("C:/treeFrogProject/myapp/config.ini", QSettings::IniFormat);

    m_pythonPath = settings.value("gen/python_path").toString();
    m_configPath = "C:/treeFrogProject/myapp/config.ini";
    m_templatePath = settings.value(section + "/template").toString();
    m_copyPath = settings.value(section + "/copy").toString();
    m_jsonPath = settings.value(section + "/json").toString();
    m_scriptPath = settings.value(section + "/script").toString();
    m_scriptPathCopy = settings.value(section + "/script_copy").toString();

    return true;
}

void WebController::submitForm()
{
    if (httpRequest().method() != Tf::Post) 
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    QString section = "TemplateBreed";
    copyScriptForSection(section);

    QVariantMap data = httpRequest().formItems();

    QMap<QString, QPair<QString, QString>> biteGroups;
    biteGroups["bite_scissor"] = qMakePair(QString("111"), QString("010"));
    biteGroups["bite_direct"] = qMakePair(QString("121"), QString("020"));
    biteGroups["bite_straight"] = qMakePair(QString("131"), QString("030"));
    biteGroups["bite_toomuch"] = qMakePair(QString("141"), QString("040"));
    biteGroups["bite_less"] = qMakePair(QString("151"), QString("050"));
    biteGroups["bite_crossed"] = qMakePair(QString("161"), QString("060"));
    biteGroups["bite_onrow"] = qMakePair(QString("171"), QString("070"));
    biteGroups["bite_meat"] = qMakePair(QString("181"), QString("080"));

    for (auto it = biteGroups.begin(); it != biteGroups.end(); ++it) 
    {
        QString groupName = it.key();
        QString keyYes = it.value().first;
        QString keyNo = it.value().second;

        if (data.contains(groupName)) 
        {
            QString selected = data[groupName].toString(); // "yes" или "no"
            if (selected == "yes") 
            {
                data[keyYes] = "+";
                data[keyNo] = " ";  // пробел (можно заменить на пустую строку, если нужно)
            }
            else 
            { // "no"
                data[keyYes] = " ";
                data[keyNo] = "+";
            }
            data.remove(groupName); // убираем служебный ключ
        }
        else 
        {
            // Если группа не была отправлена (пользователь ничего не выбрал) – ставим пробелы по умолчанию
            data[keyYes] = " ";
            data[keyNo] = " ";
        }
    }

    QStringList noiseOptions = { "aaa", "bbb", "ccc", "ddd" };
    QString selectedNoise = data.value("noiseReaction").toString();
    for (const QString& opt : noiseOptions) 
        data[opt] = (opt == selectedNoise) ? "+" : "-";
    
    data.remove("noiseReaction");

    QStringList noise2 = { "eee", "fff", "ggg", "hhh", "iii" };
    QString selected2 = data.value("noise2").toString();
    for (const QString& opt : noise2) 
        data[opt] = (opt == selected2) ? "+" : "-";
  
    data.remove("noise2");

    QStringList teethObsv1 = { "jjj", "kkk", "lll", "mmm", "nnn", "ooo" };
    QString selected3 = data.value("teethObsv1").toString();
    for (const QString& opt : teethObsv1) 
        data[opt] = (opt == selected3) ? "+" : "-";
    
    data.remove("teethObsv1");

    QStringList teethObsv2 = { "ppp", "qqq", "rrr", "sss", "ttt", "uuu" };
    QString selected4 = data.value("teethObsv2").toString();
    for (const QString& opt : teethObsv2) 
        data[opt] = (opt == selected4) ? "+" : "-";
        
    data.remove("teethObsv2");

    QStringList showtime = { "vvv", "www", "xxx", "yyy", "zzz" };
    QString selected5 = data.value("showtime").toString();
    for (const QString& opt : showtime) 
        data[opt] = (opt == selected5) ? "+" : "-";
    
    data.remove("showtime");

    QJsonDocument doc = QJsonDocument::fromVariant(data);
    QFile file(m_jsonPath);
    if (file.open(QIODevice::WriteOnly)) 
    {
        file.write(doc.toJson());
        file.close();
    }

    replaceScriptForSection(section);

    redirect(urla("index"));
}

void WebController::submitReport()
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    QString section = "TemplateReport";

    loadConfigForSection(section);
    copyScriptForSection(section);

    QVariantMap data = httpRequest().formItems();
    QJsonDocument doc = QJsonDocument::fromVariant(data);

    QFile file(m_jsonPath);

    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
        qDebug() << "JSON сохранён в:" << m_jsonPath;
    }
    else {
        qWarning() << "Не удалось открыть файл для записи JSON:" << m_jsonPath;
        qWarning() << "Ошибка:" << file.errorString();
    }

    replaceScriptForSection(section);
    
    redirect(urla("index"));
}

bool WebController::preFilter()
{
    return true;
}

//void WebController::copyScript()
//{
//    // Удаляем старую копию, если существует
//    if (QFile::exists(m_copyPath))
//        QFile::remove(m_copyPath);
//
//    // Копируем файл синхронно
//    if (!QFile::copy(m_templatePath, m_copyPath))
//    {
//        qWarning() << "Не удалось скопировать файл:" << m_templatePath;
//    }
//    else
//    {
//        qDebug() << "Файл скопирован успешно:" << m_copyPath;
//    }
//}

//void WebController::replaceScript()
//{
//    QString python = "C:/Users/lukan/AppData/Local/Programs/Python/Python312/python.exe";
//    QString script = "C:/treeFrogProject/myapp/wordtempl/textEdit_v2.py";
//    QProcess::startDetached(python, { script });
//}

// Don't remove below this line
T_DEFINE_CONTROLLER(WebController)
