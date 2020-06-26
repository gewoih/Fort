#include "Product.h"

Product::Product()
{
	name = "";
	article = "";
	count = 0;
}

Product::Product(string new_name, string new_article, int new_count)
{
	name = new_name;
	article = new_article;
	count = new_count;
}

string Product::get_name() const
{
	return name;
}

int Product::get_count() const
{
	return count;
}

string Product::get_article() const
{
	return article;
}

void Product::set(string new_name, string new_article, int new_count)
{
	name = new_name;
	article = new_article;
	count = new_count;
}

bool operator<(const Product& item1, const Product& item2)
{
	return item1.get_article() < item2.get_article();
}