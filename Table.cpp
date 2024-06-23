#include "Table.h"

Table::Table(const MyString& name) : name(name) {

}

Table::Table(const MyString& name, size_t colsCount, const Vector<MyString>& namesOfColumns, const Vector<MyString>& typesOfColumns) :
	name(name), colsCount(colsCount), namesOfColumns(namesOfColumns), typesOfColumns(typesOfColumns) {

}

void Table::addRow(const Vector<MyString>& colsNamesFromUser, const Vector<MyString>& cellsValuesFromUser)
{
	//if cols do not exist -> error
	size_t colsCountFromUser = colsNamesFromUser.getSize();
	Vector<MyString> row;
	for (size_t i = 0; i < colsCount; i++)
	{
		row.pushBack(nullObj);
	}
	for (size_t i = 0; i < colsCountFromUser; i++)
	{
		int index = getColumnIndex(colsNamesFromUser[i]);
		row.pushAt(cellsValuesFromUser[index], index);
	}
	Row rowToAdd(row, colsCount);
	rows.pushBack(rowToAdd);
	rowsCount++;
}

void Table::deleteRow(size_t rowIndex)
{
	rows.popAt(rowIndex);
}

void Table::updateRowCell(size_t rowIdx, size_t colIdx, const MyString& newValue)
{
	rows[rowIdx].setValue(colIdx, newValue);
}

void Table::serialize() {
	MyString fileName = name + ".ss145";
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open()) {
		throw std::logic_error("Could not open file!");
	}

	initTableFile(ofs);

	for (int i = 0; i < rowsCount; i++)
	{
		rows[i].serialize(ofs);
		if (i != rowsCount - 1)
		{
			ofs << std::endl;
		}
	}
}

void Table::deserialize() {
	MyString fileName = name + ".ss145";
	std::ifstream ifs(std::strcat((char*)name.c_str(), ".ss145"));
	if (!ifs.is_open()) {
		throw std::logic_error("Could not open file!");
	}

	populateColumnsTypes(ifs);
	populateColumnsNames(ifs);

	char rowStr[BUFFER_SIZE];
	while (!ifs.eof())
	{
		ifs.getline(rowStr, BUFFER_SIZE, '\n');
		Row emptyRow;
		emptyRow.setColumnsCount(colsCount);
		rows.pushBack(emptyRow);

		rows[rowsCount++].deserialize(rowStr);
	}
}

void Table::print() const
{
	printNames();

	for (size_t i = 0; i < rowsCount; i++)
	{
		std::cout << std::endl;
		rows[i].print();
	}
}

void Table::initTableFile(std::ostream& os)
{

	for (size_t i = 0; i < colsCount; i++)
	{
		os << typesOfColumns[i];
		if (i != colsCount - 1)
		{
			os << SEPARATOR;
		}
	}

	os << std::endl;

	for (size_t i = 0; i < colsCount; i++)
	{
		os << namesOfColumns[i];
		if (i != colsCount - 1)
		{
			os << SEPARATOR;
		}
	}

	os << std::endl;

}

void Table::populateColumnsNames(std::istream& is)
{
	char rowStr[BUFFER_SIZE];
	is.getline(rowStr, BUFFER_SIZE, '\n');
	std::stringstream ss(rowStr);

	for (size_t i = 0; i < colsCount; i++)
	{
		char currColumnNameValue[BUFFER_SIZE];
		ss.getline(currColumnNameValue, BUFFER_SIZE, SEPARATOR);
		namesOfColumns.pushBack(currColumnNameValue);
	}
}

void Table::populateColumnsTypes(std::istream& is)
{
	char rowStr[BUFFER_SIZE];
	is.getline(rowStr, BUFFER_SIZE, '\n');
	std::stringstream ss(rowStr);

	for (size_t i = 0; i < colsCount; i++)
	{
		char currColumnTypeValue[BUFFER_SIZE];
		ss.getline(currColumnTypeValue, BUFFER_SIZE, SEPARATOR);
		typesOfColumns.pushBack(currColumnTypeValue);
	}
}

void Table::printTypes() const {
	for (size_t i = 0; i < colsCount; i++)
	{
		std::cout << "| ";
		std::cout << typesOfColumns[i];
		if (i != colsCount - 1)
		{
			std::cout << " | ";
		}
		std::cout << " |";
	}
}

void Table::printNames() const {
	for (size_t i = 0; i < colsCount; i++)
	{
		std::cout << "| ";
		std::cout << namesOfColumns[i];
		if (i != colsCount - 1)
		{
			std::cout << " | ";
		}
		std::cout << " |";
	}
}

int Table::getColumnIndex(const MyString& colName) const
{
	if (colsCount < 1) {
		throw std::logic_error("No cols bro");
	}

	for (int i = 0; i < colsCount; i++)
	{
		if (strcmp(namesOfColumns[i].c_str(), colName.c_str()) == 0)
			return i;
	}
}

bool Table::isCondtionMet(const MyString& cellValue, const MyString& conditionValue, const MyString& comparisonOperator) const {
	if (comparisonOperator == "==") {
		return cellValue == conditionValue;
	}
	else if (comparisonOperator == "!=") {
		return cellValue != conditionValue;
	}
	else if (comparisonOperator == ">") {
		return cellValue > conditionValue;
	}
	else if (comparisonOperator == "<") {
		return cellValue < conditionValue;
	}
	else if (comparisonOperator == ">=") {
		return cellValue >= conditionValue;
	}
	else if (comparisonOperator == "<=") {
		return cellValue <= conditionValue;
	}
}

//v[][0] = cellValue;
//v[][1] = conditionValue;
//v[][3] = comparisonOperator;
//bool areConditionsMet(const Vector<Vector<MyString>>& conditions, const MyString& logicalOperator = "") {
//	
//}

const Vector<Pair<int, int>>& Table::searchForValueByColumnAndPredicate(const MyString& columnName, const MyString& conditionValue, const MyString& comparisonOperator) const {
	Vector<Pair<int, int>> indicesPairs;

	int columnIndex = getColumnIndex(columnName);
	for (size_t i = 0; i < rowsCount; i++)
	{
		if (isCondtionMet(rows[i].getValueByColumnIndex(columnIndex), conditionValue, comparisonOperator)) {
			Pair<int, int> indicesPair(i, columnIndex);
			indicesPairs.pushBack(indicesPair);
		}
	}

	return indicesPairs;
}
