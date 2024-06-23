#include "Row.h"

Row::Row(const Vector<MyString>& row, size_t columnsCount) : row(row), columnsCount(columnsCount) {

}

const MyString& Row::getValueByColumnIndex(size_t columnIndex) const {

    return row[columnIndex];
}

void Row::setValue(size_t columnIndex, const MyString& value) {
    row[columnIndex] = value;
}

void Row::serialize(std::ostream& of) {
    for (int i = 0; i < columnsCount; i++)
    {
        std::cout << row[i];
        of << row[i];
        if (i != columnsCount - 1)
        {
            of << SEPARATOR;
        }
    }
}

void Row::deserialize(const char* rowFromFile) {
    std::stringstream ss(rowFromFile);

    size_t currentColumnCount = 0;
    while (!ss.eof())
    {
        char currColumnValue[BUFFER_SIZE];
        ss.getline(currColumnValue, BUFFER_SIZE, SEPARATOR);
        row[currentColumnCount++] = currColumnValue;
    }
}