cmake_minimum_required(VERSION 3.16)

project(data LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем путь к исходникам
include_directories(..)

# Добавляем исходники, которые нужно тестировать
add_executable(data
    tst_data.cpp
    ../datavalidator.cpp
)

add_test(NAME data COMMAND data)

target_link_libraries(data PRIVATE Qt${QT_VERSION_MAJOR}::Test)
