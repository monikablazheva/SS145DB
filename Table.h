#pragma once
#include "Row.h"

#pragma warning(disable : 4996)

class Table
{
private:
	//Table with the values of the rows
	Vector<Row> rows;

	//The names of the columns in the table
	Vector<MyString> namesOfColumns;

	//The types of the columns in the table
	Vector<MyString> typesOfColumns;
	
	MyString name;
	size_t colsCount = 0;
	size_t rowsCount = 0;
	
public:
	Table() = default;
	Table(const MyString& name, size_t colsCount, const Vector<MyString>& namesOfColumns, const Vector<MyString>& typesOfColumns);
	void addRow(const Vector<MyString>& colsNames, const Vector<MyString>& cellsValues);
	void deleteRow(size_t rowIndex);
	void updateRow(size_t rowIndex);
	void serialize();
	void deserialize();

private:
	void initTableFile(std::ostream& os);
	int getColumnIndex(const MyString& colName) const;
};

