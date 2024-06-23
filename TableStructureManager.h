#pragma once
#include "MyString.h"
#include "ColumnType.h"

class TableStructureManager {
public:
	virtual void createTable() = 0;
	virtual void deleteTable() = 0;

	virtual void addColumn(const MyString& name, ColumnType type) = 0;
	virtual void renameColumn(const MyString& oldName, const MyString& newName) = 0;
	virtual void deleteColumn(const MyString& Name) = 0;
};