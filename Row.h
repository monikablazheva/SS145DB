#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Constants.h"
#include <fstream>
#include <sstream>
#include <iomanip> // For std::setw

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
    void setColumnsCount(size_t columnsCount);

    void addCell(const MyString& cell);
    void addCellAt(const MyString& cell, size_t index);

    void deleteValueFromCell();
    void deleteValueFromCellAt(size_t index);

    void removeCell();
    void removeCellAt(size_t index);

    void serialize(std::ostream& os);
    void deserialize(const char* rowFromFile);

    void print() const;
};

