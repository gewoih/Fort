#include <iostream>
#include <fstream>
#include "Products.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");

	Products list_of_products;

	list_of_products.open();

	for (int menu;;)
	{
		cout << "1. Просмотр списка товаров" << endl;
		cout << "2. Добавление нового товара" << endl;
		cout << "3. Пополнение существующего товара" << endl;
		cout << "4. Удаление товара" << endl;
		cout << "5. Поиск по артикулу" << endl;
		cout << "6. Выход из программы" << endl;

		cin >> menu;

		system("cls");
		switch (menu)
		{
			case 1:
			{
				list_of_products.print();
				break;
			}
			case 2:
			{
				list_of_products.add();
				break;
			}
			case 3:
			{
				list_of_products.fill();
				break;
			}
			case 4:
			{
				list_of_products.remove();
				break;
			}
			case 5:
			{
				list_of_products.find();
				break;
			}
			case 6:
			{
				return 0;
			}
		}
	}
}