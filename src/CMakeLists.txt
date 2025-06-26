cmake_minimum_required(VERSION 3.10.2)
project(Bot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpqxx -lpq")
set(Boost_USE_MULTITHREADED ON)

# find_library(PQXX_LIB pqxx)
# find_library(PQ_LIB pq)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
# include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
# if (CURL_FOUND)
#     include_directories(${CURL_INCLUDE_DIRS})
#     add_definitions(-DHAVE_CURL)
# endif()
find_path(PQXX_INCLUDE_DIR pqxx)
find_library(PQXX_LIBRARY pqxx)
find_library(PQ_LIBRARY pq)

# if(NOT PQXX_INCLUDE_DIR OR NOT PQXX_LIBRARY OR NOT PQ_LIBRARY)
#     message(FATAL_ERROR "Не удалось найти библиотеки PostgreSQL (libpqxx и libpq)")
# endif()

# message("пути ${PQXX_INCLUDE_DIR} ${PQXX_LIBRARY} ${PQ_LIBRARY}")

add_executable(Bot main.cc)

target_link_libraries(Bot /usr/local/lib/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${PQXX_LIBRARY} ${PQ_LIBRARY})
