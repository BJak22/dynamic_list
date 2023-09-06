#include "list.h"

using namespace std;

//test
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