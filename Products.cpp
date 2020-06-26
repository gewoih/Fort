#include "Products.h"
#include <fstream>

ostream& operator<<(ostream& stream, const Product& item)
{
	stream << "======================================" << endl;
	stream << item.get_article() << "|" << item.get_name() << " (" << item.get_count() << " ��.)" << endl;
	stream << "======================================" << endl;

	return stream;
}

istream& operator>>(istream& stream, Product& item)
{
	string name, article;
	int count;

	cout << "������� ��� ������: ";
	stream >> name;

	cout << "������� ������� ������: ";
	stream >> article;

	cout << "������� ���������� ������: ";
	stream >> count;

	item.set(name, article, count);

	return stream;
}

void Products::print() const
{
	if (products.size() == 0)
		cout << "� ������ ������ �� ������ ��� �������." << endl;
	else
	{
		for (const auto& item : products)
			cout << item << endl;
	}
}

void Products::print(string article)
{
	auto p = find(article);
	if (p != products.end())
		cout << *p << endl;
	else
		cout << "������ � ����� ��������� �� ����������." << endl;
}

void Products::create(string name, string article, int count)
{
	products.insert(Product(name, article, count));
}

void Products::add()
{
	Product new_product;
	cin >> new_product;

	if (find(new_product.get_article()) != products.end())
		cout << "����� � ����� �������� ��� ����������.";
	else
	{
		products.insert(new_product);
		system("cls");
		cout << "����� ������� ��������." << endl << endl;
	}
}

void Products::fill()
{
	string article, new_name, new_article;
	int count, new_count;

	cout << "������� ������� ������: ";
	cin >> article;

	auto p = find(article);
	if (p != products.end())
	{
		cout << "������� ���������� ������: ";
		cin >> count;

		new_name = (*p).get_name();
		new_article = (*p).get_article();
		new_count = (*p).get_count() + count;

		Product new_product;
		new_product.set(new_name, new_article, new_count);

		products.erase(p);
		products.insert(new_product);

		system("cls");
		cout << "����� ������� ��������." << endl << endl;
	}
	else
		cout << "������ � ����� ��������� �� ����������." << endl;
}

void Products::remove()
{
	string article;

	cout << "������� ������� ������ ��� ��������: ";
	cin >> article;

	if (find(article) != products.end())
		products.erase(find(article));
	else
		cout << "������ � ����� ��������� �� ����������." << endl;
}

void Products::find() const
{
	string article;
	
	cout << "������� ������� ������: ";
	cin >> article;

	if (find(article) != products.end())
	{
		system("cls");
		cout << "��������� �������:" << endl << *(find(article));
	}
	else
		cout << "������ � ����� ��������� �� ����������." << endl;
}

void Products::save() const
{
	if (products.size())
	{

		ofstream save;

		save.open("data.bin");

		for (const auto& item : products)
			save << item.get_article() << " " << item.get_name() << " " << item.get_count();

		save.close();

		cout << "������ ������� ���������." << endl << endl;
	}
	else
		cout << "������ ���������." << endl;
}

void Products::open()
{
	ifstream read("data.bin");
	if (read.is_open())
	{
		string name, article;
		int count;

		while (read)
		{
			getline(read, article, ' ');
			getline(read, name, ' ');
			read >> count;

			create(name, article, count);
		}

		cout << "������ ������� ���������." << endl << endl;
	}
}

set<Product>::iterator Products::find(string article) const
{
	set<Product>::iterator p = products.end();

	for (auto i = products.begin(); i != products.end(); i++)
	{
		if ((*i).get_article() == article)
		{
			p = i;
			break;
		}
	}
	return p;
}