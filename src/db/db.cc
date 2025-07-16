#include "db.h"

void SendedPictureDBManager::GettingUserInformation()
{
    
}

SendedPictureDBManager::SendedPictureDBManager()
{
    try
    {
        mConnection = std::make_unique<pqxx::connection>("dbname = telegram user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");
    }
    catch (pqxx::broken_connection &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (mConnection->is_open())
    {
        std::cout << "Успешное подключение к " << mConnection->dbname() << std::endl;
    }
    else
    {
        std::cout << "Не удалось подключиться к базе данных" << std::endl;
    }
}

// реализизовать взаимодействие бд через этот класс
// что такое unicptr и тд
//