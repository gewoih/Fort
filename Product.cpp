#include "Product.h"

Product::Product()
{
	name = "";
	count = 0;
	article = 0;
}

Product::Product(string new_name, int new_count, int new_article)
{
	name = new_name;
	count = new_count;
	article = new_article;
}

string Product::get_name() const
{
	return name;
}

int Product::get_count() const
{
	return count;
}

int Product::get_article() const
{
	return article;
}
