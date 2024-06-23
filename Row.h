#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Constants.h"
#include <fstream>
#include <sstream>

class Row
{
private:

    //container of columns' values
    //the indices in the cointeiner are euqual to the columns'c indices
    //each column from the table has an index
	Vector<MyString> row;
    size_t columnsCount;

public:
	Row() = default;
    Row(const Vector<MyString>& row, size_t columnsCount);

    const MyString& getValueByColumnIndex(size_t columnIndex) const;
    void setValue(size_t columnIndex, const MyString& value);

    void serialize(std::ostream& os);
    void deserialize(const char* rowFromFile);
};

