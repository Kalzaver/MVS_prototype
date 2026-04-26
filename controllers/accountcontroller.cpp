#include "accountcontroller.h"
#include "C:/treeFrogProject/myapp/models/objects/user.h"

void AccountController::form()
{
    userLogout();
    render();
}

void AccountController::regist()
{
    // Если метод не POST – показываем форму регистрации
    if (httpRequest().method() != Tf::Post) {
        render("registration");
        return;
    }

    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");
    QString password2 = httpRequest().formItemValue("password2");

    // Валидация
    if (username.isEmpty() || password.isEmpty()) {
        QString message = "Login and password must not be empty";
        texport(message);
        render("registration");
        return;
    }

    // Проверка существования пользователя
    User existing = User::getByIdentityKey(username);
    if (!existing.isNull()) {
        QString message = "User already exists";
        texport(message);
        render("registration");
        return;
    }

    if (password != password2) {
        QString message = "passwords aren't the same";
        texport(message);
        render("registration");
        return;
    }

    // Создание пользователя (пароль сохраняется как есть)
    User user = User::create(username, password);
    if (user.isNull()) {
        QString message = "Failed to create user";
        texport(message);
        render("registration");
        return;
    }

    // Автоматический вход нового пользователя
    userLogin(&user);

    // Перенаправление на главную страницу (контроллер Web, действие index)
    redirect(QUrl("http://localhost:8800/Web/index"));
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
