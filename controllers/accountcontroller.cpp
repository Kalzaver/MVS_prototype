#include "accountcontroller.h"
#include "C:/treeFrogProject/myapp/models/objects/user.h"

void AccountController::form()
{
    userLogout();
    render();
}

void AccountController::login()
{
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    User user = User::authenticate(username, password);
    if (!user.isNull()) {
        userLogin(&user);
        redirect(QUrl("http://localhost:8800/Web/index"));
    }
    else {
        QString message = "Login failed";
        texport(message);
        render("form");
    }
}

void AccountController::logout()
{
    userLogout();
    redirect(urla("form"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AccountController)
