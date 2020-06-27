#pragma once
#include "Product.h"
#include <set>
#include <iostream>
#include <string>

using namespace std;

class Products
{
private:
	set<Product> products;

public:
	void print() const;
	void print(string article) const;
	void create(string name, string article, int count);

	void add();
	void fill();
	void remove();
	void find() const;
	void save() const;
	void open();
	set<Product>::iterator find(string article) const;
};

