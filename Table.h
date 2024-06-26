#pragma once
#include "Row.h"
#include "Pair.hpp"

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
	Table(const MyString& name);
	Table(const MyString& name, size_t colsCount, const Vector<MyString>& namesOfColumns, const Vector<MyString>& typesOfColumns);
	void addRow(const Vector<MyString>& colsNames, const Vector<MyString>& cellsValues);
	void deleteRow(size_t rowIndex);
	void updateRowCell(size_t rowIdx, size_t colIdx, const MyString& newValue);
	const Vector<Pair<int, int>>& searchForValueByColumnAndPredicate(const MyString& columnName, const MyString& conditionValue, const MyString& comparisonOperator) const;

	void serialize();
	void deserialize();
	void print() const;

private:
	void initTableFile(std::ostream& os);
	void populateColumnsNames(std::istream& is);
	void populateColumnsTypes(std::istream& is);
	void printTypes() const;
	void printNames() const;


	int getColumnIndex(const MyString& colName) const;
	bool isCondtionMet(const MyString& cellValue, const MyString& conditionValue, const MyString& comparisonOperator) const;

};

