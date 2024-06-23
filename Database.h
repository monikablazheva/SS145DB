#pragma once
#include <stdexcept>
#include "UniquePointer.hpp"
#include "MyString.h"
#include "Vector.hpp"
#include "Table.h"

class Database
{
private:
    Vector<Table*> tables;
    MyString dbPath;
    static UniquePointer<Database> instance;

	Database(const MyString& dbPath);
    //~Database() = default;

public:
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    static Database& getInstance(const MyString& dbPath = nullptr);
    void addTable(Table& tableRef);
};

