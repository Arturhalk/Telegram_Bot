#pragma once
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <filesystem>
#include <vector>

class AnimalPictureService
{
public:
    void Start();
    size_t GetUserID(TgBot::Message::Ptr message);
    AnimalPictureService();
    void TgLongPoll();
private:
    std::unique_ptr<TgBot::Bot> mBot;
};
/*Основная концепция проекта
Когда пользователь нажимает /start, то программа проверяет по базе данных PostgreSQL,
какое количество времени прошло с последнией отправки изображения(если прошло меньше 24 часов,
то программа пишет сообщение "Ещё не прошло 24 часа, попробуйте через(количество оставшегося времени)",
иначе отправляет изображение с животным и названием этого животного)*/

/*PostgreSQL
В таблице будем хранить id, previous photo и hours. По id  будем искать пользователя,
затем будем проверять прошло ли 24 часа, с момента отправки последнего фото с животным,
а затем искать изображение в локальной папке так, чтобы оно не повторялось с прошлым отосланым изображением*/
