#pragma once
#include <string>
#include <iostream>

using namespace std;

class Product
{
private:
	string name, article;
	int count;

public:
	Product();
	string get_name() const;
	int get_count() const;
	string get_article() const;
	void set(string new_name, string new_article, int new_count);
	void add(int c);
};

bool operator<(const Product& item1, const Product& item2);