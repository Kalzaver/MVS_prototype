#pragma once
#include <TGlobal>

class THttpRequest;
class TSession;


class T_MODEL_EXPORT UserService {
public:
    void index();
    void show(const QString &username);
    QString create(THttpRequest &request);
    void edit(TSession &session, const QString &username);
    int save(THttpRequest &request, TSession &session, const QString &username);
    bool remove(const QString &username);
};

