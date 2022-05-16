#include <string>
#include <iostream>
#include <map>
#include "month_expenses.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <Windows.h>
#include <mciapi.h>
month_expenses::month_expenses()
{
	price = 0;
	Amount_money_spent = 0;
	remain = 0;
	totals = 0;
	totalr = 0;
	totalm = 0;
	totalp = 0;

}
void month_expenses::input_list()
{
	cout << "enter the item name " << endl;
	cin >> item_name;
	cout << "enter the price of the item " << endl;
	cin >> price;
	cout << " enter the amont of money spent" << endl;
	cin >> Amount_money_spent;
	remain = price - Amount_money_spent;
	cout << remain << endl;
}

void month_expenses::Add_store(map < int, map < string, vector<month_expenses> >>& outer_map)
{
	month_expenses my_expenses;
	while (true)
	{
		int checked_month;
		string add_month_choice;
		cout << "DO YOU WANT TO ADD MONTH EXPENSE ? " << endl;
		cin >> add_month_choice;
		if (add_month_choice == "YES" || add_month_choice == "yes" || add_month_choice == "Y" || add_month_choice == "y")
		{
			cout << "ENTER THE DATE " << endl;
			cin >> day >> month >> year;
			checked_month = month;
			map < string, vector<month_expenses>> inner_map;
			while (true)
			{
				string add_category_choice;
				cout << "DO YOU WANT TO ADD A CATEGORY ? " << endl;
				cin >> add_category_choice;
				if (add_category_choice == "YES" || add_category_choice == "yes" || add_category_choice == "Y" || add_category_choice == "y")
				{
					cout << " ENTER THE CATEGORY PLEASE  " << endl;
					cin >> category;
					my_expenses.input_list();
					inner_map[category].push_back(my_expenses);

				}
				else
					break;
			}

			outer_map.insert({ checked_month, inner_map });
		}
		else
			break;
	}
}
void month_expenses::search(map < int, map < string, vector<month_expenses> >>& outer_map)
{
	string CHOOSE_CATEGORY;
	char FOR_REPEAT;
	int CHOOSE_MONTH;
	int CHOOSE_THE_WAY;
	map< int, map < string, vector<month_expenses>>>::iterator OUTERMAPITERATOT;
	map <string, vector<month_expenses>>::iterator INNERMAPITERATOR;
	vector<month_expenses>::iterator VECTORITERATOR;

	cout << "choose the way to search : " << endl;
	cout << "1-by month\n" << "2-by category per month\n";
	cin >> CHOOSE_THE_WAY;

	if (CHOOSE_THE_WAY == 1)
	{

		do
		{
			int COUNTERFOREXSISTMONTH1 = 0;
			cout << "enter the month:\n";
			cin >> CHOOSE_MONTH;
			for (OUTERMAPITERATOT = outer_map.begin(); OUTERMAPITERATOT != outer_map.end(); OUTERMAPITERATOT++)
			{
				if (OUTERMAPITERATOT->first == CHOOSE_MONTH)
				{
					COUNTERFOREXSISTMONTH1++;
					for (auto INNERMAPITERATOR = OUTERMAPITERATOT->second.begin(); INNERMAPITERATOR != OUTERMAPITERATOT->second.end(); INNERMAPITERATOR++)
					{
						int i = 0;
						cout << "the category :" << INNERMAPITERATOR->first << "\n" << "the items are:\n";
						for (auto VECTORITERATOR = INNERMAPITERATOR->second.begin(); VECTORITERATOR != INNERMAPITERATOR->second.end(); VECTORITERATOR++)
						{

							i++;
							cout << i << ")" << VECTORITERATOR->item_name << "\n";
							cout << "the price:" << VECTORITERATOR->price << "\n";
							cout << "the amount of money spent:" << VECTORITERATOR->Amount_money_spent << "\n";
							cout << "the remain:" << VECTORITERATOR->remain << "\n";
							cout << "**\n";

						}
					}


				}
			}
			if (COUNTERFOREXSISTMONTH1 == 0)
			{
				cout << "month not found\n";
			}
			cout << "do you want to search again by month? press y if yes\n";
			cin >> FOR_REPEAT;
		} while (FOR_REPEAT == 'y' || FOR_REPEAT == 'Y' || FOR_REPEAT == 'YES' || FOR_REPEAT == 'yes');

	}

	else if (CHOOSE_THE_WAY == 2)
	{
		do
		{
			int COUNTERFOREXSISTMONTH2 = 0, COUNTERFOREXSISTCATEG = 0;
			cout << "enter the month:\n";
			cin >> CHOOSE_MONTH;
			for (OUTERMAPITERATOT = outer_map.begin(); OUTERMAPITERATOT != outer_map.end(); OUTERMAPITERATOT++)
			{
				if (OUTERMAPITERATOT->first == CHOOSE_MONTH)
				{
					COUNTERFOREXSISTMONTH2++;
					cout << "enter the category :\n";
					cin >> CHOOSE_CATEGORY;
					for (INNERMAPITERATOR = OUTERMAPITERATOT->second.begin(); INNERMAPITERATOR != OUTERMAPITERATOT->second.end(); INNERMAPITERATOR++)
					{

						if (INNERMAPITERATOR->first == CHOOSE_CATEGORY)
						{
							COUNTERFOREXSISTCATEG++;
							int i = 0;
							cout << "the category :" << INNERMAPITERATOR->first << "\n" << "the items are:\n";
							for (VECTORITERATOR = INNERMAPITERATOR->second.begin(); VECTORITERATOR != INNERMAPITERATOR->second.end(); VECTORITERATOR++)
							{

								i++;
								cout << i << ")" << VECTORITERATOR->item_name << "\n";
								cout << "the price:" << VECTORITERATOR->price << "\n";
								cout << "the amount of money spent:" << VECTORITERATOR->Amount_money_spent << "\n";
								cout << "the remain:" << VECTORITERATOR->remain << "\n";
								cout << "**\n";

							}
						}


					}
					if (COUNTERFOREXSISTCATEG == 0)
					{
						cout << "category not found\n";
					}

				}

			}
			if (COUNTERFOREXSISTMONTH2 == 0)
			{
				cout << "month not found\n";
			}

			cout << "do you want to search again by category? WRITE Y/YES if yes\n";
			cin >> FOR_REPEAT;
		} while (FOR_REPEAT == 'y' || FOR_REPEAT == 'Y' || FOR_REPEAT == 'YES' || FOR_REPEAT == 'yes');
	}
}
void month_expenses::delet(map < int, map < string, vector<month_expenses> >>& outer_map) {

	int h;
	string s;
	map< int, map < string, vector<month_expenses>>>::iterator itt;
	map <string, vector<month_expenses>>::iterator itts;
	vector<month_expenses>::iterator itto;
	int ch;
	cout << "do you want do delete any of expenses";
	cin >> ch;
	if (ch == 1) {

		cout << "enter month you want to delete at";
		cin >> h;



		for (itt = outer_map.begin(); itt != outer_map.end(); itt++)

		{
			if (itt->first == h) {


				for (auto itts = itt->second.begin(); itts != itt->second.end(); itts++)
				{


					cout << "the category :" << itts->first << "\n";
					cout << "enter the item you want to delete";
					cin >> s;

					for (auto itto = itts->second.begin(); itto != itts->second.end(); itto++)
					{

						if (s == itto->item_name)
						{
							itts->second.erase(itto);
							break;
						}
						else
						{

							cout << itto->item_name << "\n";
							cout << "the price:" << itto->price << "\n";
							cout << "the amount of money spent:" << itto->Amount_money_spent << "\n";
							cout << "the remain:" << itto->remain << "\n";
							cout << "**\n";
						}
					}
				}
			}
		}
	}
}
void month_expenses::Edit(map < int, map < string, vector<month_expenses> >>& outer_map)
{

	map< int, map < string, vector<month_expenses>>>::iterator itt;
	map <string, vector<month_expenses>>::iterator itts;
	vector<month_expenses>::iterator itto;
	while (true)
	{
		int edit_month;
		string edit_month_choice;
		string c;
		cout << "Do you want to edit in month expenses ? " << endl;
		cin >> edit_month_choice;
		if (edit_month_choice == "YES")
		{
			cout << "enter which month do you want to edit in " << endl;
			cin >> edit_month;
			cout << "enter the category " << endl;
			cin >> c;

			for (itt = outer_map.begin(); itt != outer_map.end(); itt++)
			{

				if (itt->first == edit_month)
				{

					for (auto itts = itt->second.begin(); itts != itt->second.end(); itts++)
					{

						if (c == itts->first)
						{
							cout << "what do you want to edit at category ?..for item name press (1),for price (2),for money spent(3) for the date (4)" << endl;
							int choice;
							cin >> choice;
							if (choice == 1)
							{

								cout << "the item name you want to edit" << endl;
								cin >> oldname;
								item_name = oldname;
								cout << "enter the new name" << endl;
								cin >> newname;
								for (auto itto = itts->second.begin(); itto != itts->second.end(); itto++)
								{
									itto->newname = newname;
									itto->oldname = oldname;
									if (itto->item_name == itto->oldname) {
										itto->item_name = itto->newname;
									}
									cout << "the new name is" << " " << itto->newname << endl;
									cout << "the price:" << itto->price << endl;
									cout << "the amount of money spent:" << itto->Amount_money_spent << endl;
									cout << "the remain:" << itto->remain << endl;
									cout << "**\n";

								}

							}
							else if (choice == 2)
							{
								cout << "enter the price you want to edit" << endl;
								cin >> oldprice;
								price = oldprice;
								cout << "enter the new price" << endl;
								cin >> newprice;
								for (auto itto = itts->second.begin(); itto != itts->second.end(); itto++)
								{
									itto->newprice = newprice;
									itto->oldprice = oldprice;
									if (itto->price == itto->oldprice) {
										itto->price = itto->newprice;
									}
									cout << "the new price is" << " " << itto->price << endl;
									cout << "the item name:" << itto->item_name << endl;
									cout << "the amount of money spent:" << itto->Amount_money_spent << endl;
									itto->newremain = itto->price - itto->Amount_money_spent;

									cout << "the new remain is:" << itto->remain << endl;
									cout << itto->newremain << endl;
									cout << "**\n";

								}


							}
							else if (choice == 3)
							{
								cout << "enter the amount money spent you want to edit" << endl;
								cin >> oldAmount_money_spent;
								Amount_money_spent = oldAmount_money_spent;
								cout << "enter the new Amount of money" << endl;
								cin >> newAmount_money_spent;
								for (auto itto = itts->second.begin(); itto != itts->second.end(); itto++)
								{
									itto->newAmount_money_spent = newAmount_money_spent;
									itto->oldAmount_money_spent = oldAmount_money_spent;
									if (itto->Amount_money_spent == itto->oldAmount_money_spent) {
										itto->Amount_money_spent = itto->newAmount_money_spent;
									}


									cout << "the new Amount money spent is" << " " << itto->Amount_money_spent << endl;
									itto->newremain = itto->price - itto->Amount_money_spent;
									cout << "the price:" << itto->price << endl;
									cout << "the item name:" << itto->item_name << endl;
									itto->newremain = itto->price - itto->Amount_money_spent;
									cout << "the new remain is:" << endl;
									cout << itto->newremain << endl;
									cout << "**\n";

								}

							}
							else if (choice == 4)
							{
								cout << "the date you want to edit" << endl;
								cin >> oldday >> oldmonth >> oldyear;
								cout << "enter the new date" << endl;
								cin >> newday >> newmonth >> newyear;
								outer_map[newmonth] = outer_map[oldmonth];
							}
						}
						else if (c != itts->first)
						{
							cout << "not found\n";
						}
					}
				}
			}
		}

		else
			break;
	}

}

void month_expenses::display(map < int, map < string, vector<month_expenses> >>& outer_map) {

	map< int, map < string, vector<month_expenses>>>::iterator ittt;
	map <string, vector<month_expenses>>::iterator ittts;
	vector<month_expenses>::iterator ittto;
	while (true)
	{

		int choice, the_needed_month;
		string the_needed_category;
		cout << "choose the way to display  : \n" << " 1 for money spent for specific month" << "\n" << "2 for total remaining " << "\n" << "3 for total money spent+remaining" << "\n" << "4 for the total amount of money spent per month per category " << endl;
		cin >> choice;
		if (choice == 1)
		{
			double totalS = 0;
			cout << "ENTER THE MONTH DO YOU WANT TO DISPLAY THE TOTAL MONEY SPENT" << endl;
			cin >> the_needed_month;
			for (ittt = outer_map.begin(); ittt != outer_map.end(); ittt++)
			{
				if (ittt->first == the_needed_month) {

					for (auto ittts = ittt->second.begin(); ittts != ittt->second.end(); ittts++)
					{

						for (auto ittto = ittts->second.begin(); ittto != ittts->second.end(); ittto++)
						{
							totalS += ittto->Amount_money_spent;
						}
					}
				}
			}
			cout << "total amount of money spent per month " << "    " << totalS << endl;
		}
		if (choice == 2)

		{
			double totalR = 0;

			for (ittt = outer_map.begin(); ittt != outer_map.end(); ittt++)

			{
				for (auto ittts = ittt->second.begin(); ittts != ittt->second.end(); ittts++)
				{

					for (auto ittto = ittts->second.begin(); ittto != ittts->second.end(); ittto++)
					{

						totalR += ittto->remain;
					}
				}
			}
			cout << "total amount of money remain  " << "    " << totalR << endl;
			/*if (totalR == 0) {
			cout << "   *** your month is PERFECT (: without any remaning ***      " << endl;
			PlaySound(TEXT("Audience_Applause-Matthiew11-1206899159.wav"), NULL, SND_FILENAME);


			}
			else if (totalR != 0)
			{
			cout << "   *** your month is NOT PERFECT ): YOU HAVE REMAIN ***      " << endl;
			PlaySound(TEXT("poker-chips-daniel_simon.wav"), NULL, SND_FILENAME);

			}*/
		}


		if (choice == 3)
		{

			double totalSR = 0;
			for (ittt = outer_map.begin(); ittt != outer_map.end(); ittt++)
			{

				for (auto ittts = ittt->second.begin(); ittts != ittt->second.end(); ittts++)
				{

					for (auto ittto = ittts->second.begin(); ittto != ittts->second.end(); ittto++)
					{
						totals += ittto->Amount_money_spent;
						totalr += ittto->remain;

					}
				}
			}

			totalSR = totalr + totals;
			cout << "total amount of money remain+spent per month " << "    " << totalSR << endl;


		}

		if (choice == 4)
		{
			double totalS = 0;
			cout << "ENTER THE MONTH DO YOU WANT TO DISPLAY THE TOTAL MONEY SPENT" << endl;
			cin >> the_needed_month;
			cout << "ENTER THE NEEDED CATEGORY DO YOU WANT FROM THAT MONTH" << endl;
			cin >> the_needed_category;
			for (ittt = outer_map.begin(); ittt != outer_map.end(); ittt++)
			{
				if (ittt->first == the_needed_month) {

					for (auto ittts = ittt->second.begin(); ittts != ittt->second.end(); ittts++)
					{
						if (ittts->first == the_needed_category)

						for (auto ittto = ittts->second.begin(); ittto != ittts->second.end(); ittto++)
						{
							totalS += ittto->Amount_money_spent;
						}
					}
				}
			}
			cout << "total amount of money spent per month " << "    " << totalS << endl;
		}
		else
			break;
	}
}
void month_expenses::REMAIN(map < int, map < string, vector<month_expenses> >>& outer_map)
{
	map< int, map < string, vector<month_expenses>>>::iterator ittt11;
	map <string, vector<month_expenses>>::iterator ittts11;
	vector<month_expenses>::iterator ittto11;

	int the_needed_month;
	cout << "ENTER THE MONTH DO YOU WANT TO CHECK IF IT PERFECT MONTH OR NOT " << endl;
	cin >> the_needed_month;
	for (ittt11 = outer_map.begin(); ittt11 != outer_map.end(); ittt11++)
	{
		if (ittt11->first == the_needed_month) {

			for (auto ittts11 = ittt11->second.begin(); ittts11 != ittt11->second.end(); ittts11++)
			{

				for (auto ittto11 = ittts11->second.begin(); ittto11 != ittts11->second.end(); ittto11++)
				{
					totalr += ittto11->remain;
				}
			}
		}
	}
	cout << "total amount of money remain  " << "    " << totalr << endl;
	if (totalr == 0) {
		cout << "   *** your month is PERFECT (: without any remaning ***      " << endl;
		PlaySound(TEXT("applause-01.wav"), NULL, SND_FILENAME);

	}
	else if (totalr != 0)
	{
		cout << "   *** your month is NOT PERFECT ): YOU HAVE REMAIN ***      " << endl;
		PlaySound(TEXT("poker-chips-daniel_simon.wav"), NULL, SND_FILENAME);

	}
}

month_expenses::~month_expenses()
{
}
