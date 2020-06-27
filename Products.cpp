#include "Products.h"
#include <fstream>

ostream& operator<<(ostream& stream, const Product& item)
{
	stream << "======================================" << endl;
	stream << item.get_article() << "|" << item.get_name() << " (" << item.get_count() << " шт.)" << endl;
	stream << "======================================" << endl;

	return stream;
}

istream& operator>>(istream& stream, Product& item)
{
	string name, article;
	int count;

	cout << "Введите имя товара: ";
	stream >> name;

	cout << "Введите артикул товара: ";
	stream >> article;

	cout << "Введите количество товара: ";
	stream >> count;

	item.set(name, article, count);

	return stream;
}

void Products::print() const
{
	if (products.size() == 0)
		cout << "В данный момент на складе нет товаров." << endl;
	else
	{
		for (const auto& item : products)
			cout << item << endl;
	}
}

void Products::print(string article) const
{
	auto p = find(article);
	if (p != products.end())
		cout << *p << endl;
	else
		cout << "Товара с таким артикулом не существует." << endl;
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
		cout << "Товар с таким артикулом уже существует." << endl;
	else
	{
		products.insert(new_product);
		system("cls");
		cout << "Товар успешно добавлен." << endl << endl;

		save();
	}
}

void Products::fill()
{
	string article, new_name;
	int count, new_count;

	cout << "Введите артикул товара: ";
	cin >> article;

	auto p = find(article);
	if (p != products.end())
	{
		cout << "Введите количество товара: ";
		cin >> count;

		Product new_product;
		new_product.set(p->get_name(), article, p->get_count() + count);

		products.erase(p);
		products.insert(new_product);

		system("cls");
		cout << "Товар успешно пополнен." << endl << endl;

		save();
	}
	else
		cout << "Товара с таким артикулом не существует." << endl;
}

void Products::remove()
{
	string article;

	cout << "Введите артикул товара для удаления: ";
	cin >> article;

	if (find(article) != products.end())
	{
		products.erase(find(article));
		save();
	}
	else
		cout << "Товара с таким артикулом не существует." << endl;
}

void Products::find() const
{
	string article;
	
	cout << "Введите артикул товара: ";
	cin >> article;

	if (find(article) != products.end())
	{
		system("cls");
		cout << "Найденная позиция:" << endl << *(find(article));
	}
	else
		cout << "Товара с таким артикулом не существует." << endl;
}

void Products::save() const
{
	ofstream save;

	save.open("data.bin");

	for (const auto& item : products)
		save << item.get_article() << " " << item.get_name() << " " << item.get_count();

	save.close();
	cout << "Данные успешно сохранены." << endl << endl;
}

void Products::open()
{
	ifstream read("data.bin");
	if (read.is_open() && read.peek() != EOF)
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

		cout << "Данные успешно загружены." << endl << endl;
	}
}

set<Product>::iterator Products::find(string article) const
{
	set<Product>::iterator p;

	p = find_if(products.begin(), products.end(), 
		[&](const Product item) 
		{
			return item.get_article() == article;
		});

	return p;
}