#include "list.h"

using namespace std;

//method initialization

template<typename T>
int container<T>::range = 0;

template <typename T>
ostream& operator<< (ostream& b, const container<T>& p) {
	b << p.value;
	return b;
}

template<typename T>
istream& operator>> (istream& b, container<T>& p) {
	b >> p.value;
	return b;
}

template<typename T>
container<T>& container<T>:: operator =(T n_value) { 
	value = n_value;
	return *this;
}

template<typename T>
container<T>& container<T>::operator =(container& n_value) { 
	value = n_value.value;
	return *this; 
}

template<typename T>
container<T>::container() :value(0), head(NULL), next(NULL), pointer(NULL) {}

template<typename T>
container<T>::container(T n_value) :value(n_value), head(NULL), next(NULL), pointer(NULL) {}

template<typename T>
container<T>::~container() { 
	delete next; 
}

template<typename T>
void container<T>::Insert(T n_value) {
	if (head == NULL) {
		head = pointer = new container;
		pointer->head = head;
		pointer->value = n_value;
	}
	else {
		range++;
		pointer->next = new container;
		pointer->next->head = pointer->head;//every node has pointer to the start of container
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
	if (i < 0) {
		cout << "ERROR: wrong index!" << endl;
		throw x_wrong_index();
	}
	if (i > range) {
		cout << "ERROR: index out of range!" << endl;
		throw x_out_of_range();
	}
	container* pointer = head;
	for (int j = 0; j < i; j++) {
		pointer = pointer->next;
	}
	return *pointer;
}

//test of implemented functions
int main() try{
	container<int> box;
	for (int i = 10; i < 15; i++) {
		box.Insert(i);
	}
	box.read_all();
	cout << endl << box[1] << endl << box[3] << endl;
	cin >> box[0];
	cout << endl;
	box.read_all();
	cout << endl << box[0] << endl << box[2] << endl;
	box[0] = box[1]= 1555;
	cout << box[0]<<endl;
	cout << box[1] << endl;
	cout << endl<<endl;
	int x = 0;
	while (x != 1) {
		cin >> x;
		cout << box[x] << endl;
	}
	box.read_all();
	return 0;
}
catch (x_out_of_range) {
}
catch (x_wrong_index) {
}