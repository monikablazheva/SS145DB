#include <iostream>
#include "Table.h"

int main()
{
    //Test create table test (field1 int, field2 real)
    //-------------------------------------------------------------

    MyString tableName = "test";

    MyString colName1 = "field1";
    MyString colName2 = "field2";
    Vector<MyString> colsNames;
    colsNames.pushBack(colName1);
    colsNames.pushBack(colName2);

    MyString colType1 = "int";
    MyString colType2 = "real";
    Vector<MyString> colsTypes;
    colsTypes.pushBack(colType1);
    colsTypes.pushBack(colType2);

    Table table(tableName, 2, colsNames, colsTypes);
    table.serialize();

    //--------------------------------------------------------------

    MyString cell00 = "1";
    MyString cell01 = "1.0";
    Vector<MyString> cells;
    cells.pushBack(cell00);
    cells.pushBack(cell01);
    table.addRow(colsNames, cells);
    table.serialize();
}