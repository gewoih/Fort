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
	void print(string article);

	void add();
	void fill();
	void remove();
	void find() const;
	set<Product>::iterator find(string article) const;
};

