#include <iostream>
#include "Bot.h"
#include <filesystem>
#include "db.h"

using namespace std;

int main()
{
    AnimalPictureService service;
    //service.Start();
    SendedPictureDBManager DB;
    service.Start();
    //DB.CheckingUserInDB(a);
    return 0;
}