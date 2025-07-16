cmake_minimum_required(VERSION 3.10.2)
project(TgBot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpqxx -lpq")
set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

find_path(PQXX_INCLUDE_DIR pqxx)
find_library(PQXX_LIBRARY pqxx)
find_library(PQ_LIBRARY pq)

add_executable(Bot main.cc Bot.h Bot.cc db/db.h db/db.cc)

target_include_directories(Bot PRIVATE db)

target_link_libraries(Bot /usr/local/lib/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${PQXX_LIBRARY} ${PQ_LIBRARY})
