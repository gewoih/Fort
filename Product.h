#pragma once
#include <string>
#include <iostream>

using namespace std;

class Product
{
private:
	string name;
	int count, article;

public:
	Product();
	Product(string name, int count, int article);
	string get_name() const;
	int get_count() const;
	int get_article() const;
};

