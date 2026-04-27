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
        QString message = "Поля логина и пароля обязаны быть заполненными";
        texport(message);
        render("registration");
        //return;
    }

    // Проверка существования пользователя
    User existing = User::getByIdentityKey(username);
    if (!existing.isNull()) {
        QString message_UN = "логин не подходит";
        texport(message_UN);
        render("registration");
        //return;
    }

    if (password.length() < 5) {
        QString message_PW1 = "пароль меньше 5 символов";
        texport(message_PW1);
        render("registration");
        //return;
    }

    if (password.length() < 5 && password2.isEmpty()) {
        QString message_PW1 = "пароль меньше 5 символов";
        QString message_PW2 = "пароль не был введён повторно";
        texport(message_PW2);
        texport(message_PW1);
        render("registration");
        //return;
    }

    if (password != password2) {
        QString message_PW2 = "пароли не совпадают";
        texport(message_PW2);
        render("registration");
        //return;
    }

    // Создание пользователя (пароль сохраняется как есть)
    User user = User::create(username, password);
    if (user.isNull()) {
        QString message = "ошибка в создании пользователя. Повторите попытку позже";
        texport(message);
        render("registration");
        //return;
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
        QString message = "Ошибка входа";
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
