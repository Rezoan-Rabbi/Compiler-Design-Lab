#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    int numbers[size];
    int sum = 0;

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
        sum = sum + numbers[i];
    }

    float average = (float)sum / size;
    cout << "Average value: " << average << endl;

    return 0;
}

