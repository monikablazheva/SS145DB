#include "Table.h"

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

	char rowStr[BUFFER_SIZE];
	while (!ifs.eof())
	{
		ifs.getline(rowStr, BUFFER_SIZE, '\n');
		rows[rowsCount++].deserialize(rowStr);
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
