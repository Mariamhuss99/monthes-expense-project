#include <iostream>
#include "month_expenses.h"
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
#include <Windows.h>
#include <mciapi.h>
string category;
map< int, map < string, vector<month_expenses>>> outer_map;
int checked_month;
int main()
{
	system("color d0");
	int w;
	string choice_operation;
	month_expenses my_expenses;
	cout << "*****WELCOME TO MONTH'S EXPANSES PROGROM <3******" << endl;
	my_expenses.Add_store(outer_map);
	do
	{
		cout << "choose which operation do you want:" << endl;
		cout << "1 for search\n" << "2 for delete\n" << "3 for edit\n" << "4 for display\n" << "5 for CHECK IF IT PERFECT MONTH OR NOT \n" << "*the perfect month has no remain\n";
		cin >> w;
		if (w == 1)
		{
			//system("color d0");
			my_expenses.search(outer_map);
		}
		if (w == 2)
		{
			my_expenses.delet(outer_map);
		}
		if (w == 3)
		{
			my_expenses.Edit(outer_map);
		}
		if (w == 4)
		{
			my_expenses.display(outer_map);
		}
		if (w == 5)
		{
			my_expenses.REMAIN(outer_map);
		}
		cout << "do you want to do any operation again? press y/YES if yes\n";
		cin >> choice_operation;
	} while (choice_operation == "YES" || choice_operation == "yes" || choice_operation == "y" || choice_operation == "Y");

	system("pause");
	return 0;
}
