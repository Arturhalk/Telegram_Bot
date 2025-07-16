#include "Bot.h"

void AnimalPictureService::Start() {}

AnimalPictureService::AnimalPictureService()
{
    try
    {
        mBot = std::make_unique<TgBot::Bot>("7779372699:AAEmijaJMUUgD7xcaXC0VSZqpUck9XDnhzU");
    }
    catch (TgBot::TgException &e)
    {
        std::cout << e.what() << std::endl;    
    }
    if (mBot->getApi().getMe())
    {
        std::cout << "Успешное подключение Тг-бота!" << std::endl;
    }
    else
    {
        std::cout << "Боту не удалось подключиться" << std::endl;
    }
} 

// std::filesystem::path RecordingPictures()
// {
//     std::vector<std::filesystem::path> pictures;
//     try
//     {
//         std::string path = "../pictures_with_animals";

//         for (const auto &entry : std::filesystem::directory_iterator(path))
//             pictures.push_back(entry.path());
//         // for (const auto &filePath : pictures)
//         // {
//         //     std::cout << filePath << std::endl;
//         // }
//     }
//     catch (std::exception const &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return pictures[1];
// }

// std::filesystem::path RandomPictureSelection(std::vector<std::filesystem::path> &pictures) {}

// void BotTG()
// {

//     bot.getEvents().onCommand("start", [&bot, &C](TgBot::Message::Ptr message)
//                               {
//         // bot.getApi().sendPhoto(message->chat->id, TgBot::InputFile::fromFile(RecordingPictures(), RecordingPictures().filename()));
//         auto user_id = message->chat->id;
//         try
//         {
//             pqxx::work worker(C);

//             pqxx::result res = worker.exec_params("SELECT id FROM info WHERE id = $1", user_id);

//             if (res.empty())
//             {
//             }
//             else
//             {
//                 auto picture_and_date = worker.exec_params("SELECT previous_photo,last_sending FROM info WHERE id = $1", user_id);
//             }
//             worker.commit();
//         }
//         catch (std::exception const &e)
//         {
//             std::cout << e.what() << std::endl;
//         });

//         bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
//                                      {
//         printf("User wrote %s\n", message->text.c_str());
//         if (StringTools::startsWith(message->text, "/start")) {return;} });
//         try
//         {
//             printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//             TgBot::TgLongPoll longPoll(bot);
//             while (true)
//             {
//                 printf("Long poll started\n");
//                 longPoll.start();
//                 printf("Long poll ended\n");
//             }
//         }
//         catch (TgBot::TgException &e)
//         {
//             printf("error: %s\n", e.what());
//         }
// }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// std::filesystem::path RecordingPictures()
// {
//     std::vector<std::filesystem::path> pictures;
//     try
//     {
//         std::string path = "../pictures_with_animals";

//         for (const auto &entry : std::filesystem::directory_iterator(path))
//             pictures.push_back(entry.path());
//         // for (const auto &filePath : pictures)
//         // {
//         //     std::cout << filePath << std::endl;
//         // }
//     }
//     catch (std::exception const &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return pictures[1];
// }

// std::filesystem::path RandomPictureSelection(std::vector<std::filesystem::path> &pictures) {}

// void BotTG()
// {
//     TgBot::Bot bot("7779372699:AAEmijaJMUUgD7xcaXC0VSZqpUck9XDnhzU");

//     pqxx::connection C("dbname = telegram user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");

//     if (C.is_open())
//     {
//         std::cout << "Успешное подключение к " << C.dbname() << std::endl;
//     }
//     else
//     {
//         std::cout << "Не удалось подключиться к базе данных" << std::endl;
//         return;
//     }

//     bot.getEvents().onCommand("start", [&bot, &C](TgBot::Message::Ptr message)
//                               {
//         // bot.getApi().sendPhoto(message->chat->id, TgBot::InputFile::fromFile(RecordingPictures(), RecordingPictures().filename()));
//         auto user_id = message->chat->id;
//         try
//         {
//             pqxx::work worker(C);

//             pqxx::result res = worker.exec_params("SELECT id FROM info WHERE id = $1", user_id);

//             if (res.empty())
//             {
//             }
//             else
//             {
//                 auto picture_and_date = worker.exec_params("SELECT previous_photo,last_sending FROM info WHERE id = $1", user_id);
//             }
//             worker.commit();
//         }
//         catch (std::exception const &e)
//         {
//             std::cout << e.what() << std::endl;
//         });

//         bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
//                                      {
//         printf("User wrote %s\n", message->text.c_str());
//         if (StringTools::startsWith(message->text, "/start")) {return;} });
//         try
//         {
//             printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//             TgBot::TgLongPoll longPoll(bot);
//             while (true)
//             {
//                 printf("Long poll started\n");
//                 longPoll.start();
//                 printf("Long poll ended\n");
//             }
//         }
//         catch (TgBot::TgException &e)
//         {
//             printf("error: %s\n", e.what());
//         }
// }