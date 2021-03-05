#include <iostream>

using namespace std;

int * Array;
int Iter, Amount;
bool check = false;

void Heapify() {
	check = true;
	for (int i = Amount/2; i >= 0; i--) {
		if (Array[2 * i + 1] > Array[2 * i + 2]) {
			if (Array[i] < Array[2 * i + 1] && (2 * i + 1) < Iter) {
				swap(Array[i], Array[2 * i + 1]); check = false;
			}
		} else {
			if (Array[i] < Array[2 * i + 2] && (2 * i + 2) < Iter) {
				swap(Array[i], Array[2 * i + 2]); check = false;
			}
		}
	}
}

int main() {
	cin >> Amount; 
	Iter = Amount - 1;
	Array = new int[Amount];
	for (int i = 0; i < Amount; i++) {
		cin >> Array[i];
	}
	while (Iter >= 0) {
		check = false; while (!check) {
			Heapify();
			for (int i = 0; i < Amount; i++) {
				cout << Array[i] << " ";
			}
			cout << endl;
		}
		swap(Array[0], Array[Iter]); Iter--;
	}
}