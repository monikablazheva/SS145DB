#include "Row.h"

Row::Row(const Vector<MyString>& row, size_t columnsCount) : row(row), columnsCount(columnsCount) {

}

const MyString& Row::getValueByColumnIndex(size_t columnIndex) const {

    return row[columnIndex];
}

void Row::setValue(size_t columnIndex, const MyString& value) {
    row[columnIndex] = value;
}

void Row::setColumnsCount(size_t columnsCount)
{
    this->columnsCount = columnsCount;
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

    while (!ss.eof())
    {
        char currColumnValue[BUFFER_SIZE];
        ss.getline(currColumnValue, BUFFER_SIZE, SEPARATOR);
        row.pushBack(currColumnValue);
    }
}

void Row::print() const {
    for (int i = 0; i < columnsCount; i++)
    {
        std::cout << "| ";
        std::cout << row[i];
        if (i != columnsCount - 1)
        {
            std::cout << " | ";
        }
        std::cout << " |";
    }
}

void Row::addCell(const MyString& cell)
{
    row.pushBack(cell);
    columnsCount++;
}

void Row::addCellAt(const MyString& cell, size_t index)
{
    row.pushAt(cell, index);
    columnsCount++;
}

void Row::deleteValueFromCell()
{
    setValue(columnsCount - 1, nullObj);
}

void Row::deleteValueFromCellAt(size_t index)
{
    setValue(index, nullObj);
}

void Row::removeCell()
{
    row.popBack();
    columnsCount--;
}

void Row::removeCellAt(size_t index)
{
    row.popAt(index);
    columnsCount--;
}