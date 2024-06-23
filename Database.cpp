#include "Database.h"

UniquePointer<Database> Database::instance = nullptr;

Database::Database(const MyString& dbPath) : dbPath(dbPath) {

}

//Database& Database::getInstance(const MyString& dbPath = nullptr) {
//    if (instance == nullptr) {
//        if (dbPath == nullptr) {
//            throw std::runtime_error("Database path must be provided for the first initialization.");
//        }
//        instance = UniquePointer<Database>(new Database(dbPath));
//    }
//    return *instance;
//}