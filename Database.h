#pragma once
#include <stdexcept>
#include "UniquePointer.hpp"
#include "MyString.h"

class Database
{
private:
    MyString dbPath;
    static UniquePointer<Database> instance;

	Database(const MyString& dbPath);
    //~Database() = default;

public:
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    static Database& getInstance(const MyString& dbPath = nullptr);
};

