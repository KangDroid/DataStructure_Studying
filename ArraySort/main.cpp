#include <iostream>
#include "ArraySort.h"

using namespace std;

template<class Type>
ostream& operator<<(ostream& os, ArraySort<Type>& tmp) {
    cout << "[ ";
    for (int i = 0; i < tmp.length(); i++) {
        if (i == tmp.length() - 1) {
            cout << tmp[i] << " ";
        } else {
            cout << tmp[i] << ", ";
        }
        
    }
    cout << "]";
    return os;
}

int main(void) {
    srand(time(NULL));
    ArraySort<int> as(50);

    // Selection Sort;
    cout << "Selection Sort Test" << endl;
    for (int i = 0; i < as.length(); i++) {
        as.setValue(i, rand() % 100);
    }
    as.selection_sort();

    if (as.is_sorted()) {
        cout << "This array looks like sorted" << endl;
    } else {
        cout << "This array is not sorted" << endl;
    }
    cout << as << endl;

    // Insertion Sort
    cout << "Insertion Sort Test" << endl;
    for (int i = 0; i < as.length(); i++) {
        as.setValue(i, rand() % 100);
    }
    as.insertion_sort();

    if (as.is_sorted()) {
        cout << "This array looks like sorted" << endl;
    } else {
        cout << "This array is not sorted" << endl;
    }
    cout << as << endl;

    // Bubble Sort
    cout << "Bubble Sort Test" << endl;
    for (int i = 0; i < as.length(); i++) {
        as.setValue(i, rand() % 100);
    }
    as.bubble_sort();

    if (as.is_sorted()) {
        cout << "This array looks like sorted" << endl;
    } else {
        cout << "This array is not sorted" << endl;
    }
    cout << as << endl;

    // reserve test
    cout << "Reserve Test" << endl;
    as.reserve(100);
    cout << as << endl;

    // Merge Algorithm test 
    int tmp[2] = {5, 6};
    int tmp_two[2] = {1, 2};
    as.merge(tmp, tmp_two, 2, 2);
    return 0;
}