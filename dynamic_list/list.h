#include<iostream>
#pragma once

using namespace std;

template<typename T>
class container {
	static int range;
	container* next;
	static container* head;
	container* pointer;
	T value;
public:
	void Insert(T n_value);
	void read_all();
	container& operator[](int i);
	friend ostream& operator<< <>(ostream& b, const container& p);
	friend istream& operator>> <>(istream& b, container& p);
	container& operator =(T n_value);
	container& operator =(container& n_value);
	container();
	container(T n_value);
	~container();
};

//exception handling
class x_out_of_range {};
class x_wrong_index {};