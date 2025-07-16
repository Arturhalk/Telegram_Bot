#pragma once
#include <pqxx/pqxx>
#include <memory>
#include <iostream>

class SendedPictureDBManager
{
public:
    SendedPictureDBManager();
    void GettingUserInformation();

private:
    std::unique_ptr<pqxx::connection> mConnection;
};