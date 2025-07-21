#include "db.h"

SendedPictureDBManager::SendedPictureDBManager()
{
    try
    {
        mConnection = std::make_unique<pqxx::connection>("dbname = telegram user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");
    }
    catch (pqxx::broken_connection &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Не удалось подключиться к базе данных" << std::endl;
        return;
    }
    std::cout << "Успешное подключение к серверу: " << mConnection->dbname() << std::endl;
}

pqxx::result SendedPictureDBManager::GettingDateAndPicture(const size_t user_id)
{
    try
    {
        pqxx::work worker(*mConnection);
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
}

bool SendedPictureDBManager::CheckingUserInDB(const size_t user_id)
{
    pqxx::work worker(*mConnection);

    pqxx::result res = worker.exec_params("SELECT id FROM info WHERE id = $1", user_id);

    if (res.empty())
    {
        return 0;
    }
    return 1;
}
// реализизовать взаимодействие бд через этот класс
// что такое unicptr и тд
/*
    try
    {
    }
    catch (std::exception const &e)//изменить тип исключения
    {
        std::cout << e.what() << std::endl;
    }
*/