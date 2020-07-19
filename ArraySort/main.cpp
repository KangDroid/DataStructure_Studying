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
    ArraySort<int> as;
    cout << as << endl;
    return 0;
}