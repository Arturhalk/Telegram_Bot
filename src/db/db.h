#pragma once
#include <pqxx/pqxx>
#include <memory>
#include <iostream>
#include <tgbot/tgbot.h>

class SendedPictureDBManager
{
public:
    SendedPictureDBManager();
    
    bool CheckingUserInDB(const size_t user_id);

    pqxx::result GettingDateAndPicture(const size_t user_id);

private:
    std::unique_ptr<pqxx::connection> mConnection;
};
//, TgBot::Message::Ptr message