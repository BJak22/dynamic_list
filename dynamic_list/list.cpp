#include <iostream>
#pragma once

using namespace std;

template<typename T>
class container {
	container* next;
	container* head;
	container* pointer;
	T value;
public:
	void Insert(T n_value);
	void read_all();
	container& operator[](int i);
	friend ostream& operator<< (ostream& b, const container& p) {
		return b << p.value;
	}
	friend istream& operator>> (istream& b,
		container& p) {
		return b >> p.value;
	}
	container& operator =(T n_value) { value = n_value; return *this; }
	container& operator =(container& n_value) { value = n_value.value; return *this; }
	container() :value(0), head(NULL), next(NULL), pointer(NULL) {}
	container(T n_value):value(n_value), head(NULL), next(NULL), pointer(NULL) {}
	~container() { delete next; }
};

template<typename T>
void container<T>::Insert(T n_value){
	if (head == NULL) {
		head = pointer = new container;
		pointer->head = head;
		pointer->value = n_value;
	}
	else {
		pointer->next = new container;
		pointer->next->head = pointer->head;
		pointer = pointer->next;
		pointer->value = n_value;
	}
	pointer->next = NULL;
}

template <typename T>
void container<T>::read_all() {
	container* temp_pointer = head;;
	while (temp_pointer != NULL) {
		cout << temp_pointer->value << endl;
		temp_pointer = temp_pointer->next;
	}
}

template <typename T>
container<T>& container<T>::operator[](int i) {
	container* pointer = head;
	for (int j = 0; j < i; j++) {
		pointer = pointer->next;
	}
	return *pointer;
}

int main() {
	container<int> box;
	for (int i = 10; i < 15; i++) {
		box.Insert(i);
	}
	box.read_all();
	cout << endl << box[1] << endl << box[3] << endl;
	cin >> box[0];
	cout << endl;
	box.read_all();
	cout << endl << box[0] << endl << box[3] << endl;
	box[0] = box[1]= 1555;
	cout << box[0]<<endl;
	cout << box[1] << endl;
	cout << endl<<endl;
	box.read_all();
	return 0;
}