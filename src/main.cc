#include <stdio.h>
#include <tgbot/tgbot.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <pqxx/pqxx>
// int main()
// {
//     TgBot::Bot bot("7779372699:AAEmijaJMUUgD7xcaXC0VSZqpUck9XDnhzU");
//     bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message)
//                               {
//                                 auto tmp = bot.getApi().sendMessage(message->chat->id, "Hi!");
//                                 std::chrono::seconds time(3); // or whatever
//                                 std::this_thread::sleep_for(time); });
//     bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
//                                  {
//         printf("User wrote %s\n", message->text.c_str());
//         if (StringTools::startsWith(message->text, "/start")) {return;}
//         bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text); });
//     try
//     {
//         printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//         TgBot::TgLongPoll longPoll(bot);
//         while (true)
//         {
//             printf("Long poll started\n");
//             longPoll.start();
//         }
//     }
//     catch (TgBot::TgException &e)
//     {
//         printf("error: %s\n", e.what());
//     }
//     return 0;
// }
int main()
{
    TgBot::Bot bot("7779372699:AAEmijaJMUUgD7xcaXC0VSZqpUck9XDnhzU");
    // try{
    //     pqxx::connection C("dbname = telegram user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");
    //     pqxx::work worker(C);
    //     pqxx::result response = worker.exec("SELECT * FROM info");
    //     for (size_t i = 0; i < response.size(); i++)
    //     {
    //         std::cout << "Id: " << response[i][0] << std::endl;
    //     }
    // } catch(std::exception const &e){
    //     std::cout << e.what() <<std::endl;
    // }
    auto timespan = std::chrono::hours(24);
    bot.getEvents().onCommand("start", [&bot, &timespan](TgBot::Message::Ptr message)
                              {

                                  bot.getApi().sendMessage(message->chat->id,"Сегодня вы:");
                                  bot.getApi().sendPhoto(message->chat->id, "");
                                });
    bot.getEvents().onAnyMessage([&bot, &timespan](TgBot::Message::Ptr message)
                                 {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {return;}
        if(timespan.count() == 0)
        {
            bot.getApi().sendMessage(message->chat->id, "Сегодня вы:");
            //bot.getApi().sendPhoto(message->chat->id, "");
        }
        else
        {
            bot.getApi().sendMessage(message->chat->id, "Пока ещё 24 часа не прошло");
        } });
    try
    {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true)
        {
            printf("Long poll started\n");
            longPoll.start();
            printf("Long poll ended\n");
        }
    }
    catch (TgBot::TgException &e)
    {
        printf("error: %s\n", e.what());
    }
    return 0;
}
/*Основная концепция проекта
Когда пользователь нажимает /start, то программа проверяет по базе данных PostgreSQL,
какое количество времени прошло с последнией отправки изображения(если прошло меньше 24 часов,
то программа пишет сообщение "Ещё не прошло 24 часа, попробуйте через(количество оставшегося времени)",
иначе отправляет изображение с животным и названием этого животного)*/

/*PostgreSQL
В таблице будем хранить id, previous photo и hours. По id  будем искать пользователя,
затем будем проверять прошло ли 24 часа, с момента отправки последнего фото с животным,
а затем искать изображение в локальной папке так, чтобы оно не повторялось с прошлым отосланым изображением*/