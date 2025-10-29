#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int data[size];
    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    int minValue = data[0];
    int maxValue = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }

    cout << "Minimum value: " << minValue << endl;
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}

