#include "Products.h"

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

void Products::print(string article)
{
	auto p = find(article);
	if (p != products.end())
		cout << *p << endl;
	else
		cout << "Товара с таким артикулом не существует." << endl;
}

void Products::add()
{
	Product new_product;
	cin >> new_product;

	if (find(new_product.get_article()) != products.end())
		cout << "Товар с таким артуклом уже существует.";
	else
	{
		products.insert(new_product);
		system("cls");
		cout << "Товар успешно добавлен." << endl << endl;
	}
}

void Products::fill()
{
	string article, new_name, new_article;
	int count, new_count;

	cout << "Введите артикул товара: ";
	cin >> article;

	auto p = find(article);
	if (p != products.end())
	{
		cout << "Введите количество товара: ";
		cin >> count;

		new_name = (*p).get_name();
		new_article = (*p).get_article();
		new_count = (*p).get_count() + count;

		Product new_product;
		new_product.set(new_name, new_article, new_count);

		products.erase(p);
		products.insert(new_product);

		system("cls");
		cout << "Товар успешно пополнен." << endl << endl;
	}
	else
		cout << "Товара с таким артикулом не существует." << endl;
}

void Products::remove()
{
	string article;

	cout << "Введите артикул товара для удаления: ";
	cin >> article;

	products.erase(find(article));
}

void Products::find() const
{
	string article;
	
	cout << "Введите артикул товара: ";
	cin >> article;

	for (auto item : products)
	{
		if (item.get_article() == article)
		{
			cout << item;
			break;
		}
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