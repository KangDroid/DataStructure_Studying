#include <iostream>

using namespace std;

template <typename Type>
class ArraySort {
private:
    Type* array_pointer;
    int length_array;

public:
    ArraySort(int preserve);
    ArraySort();
    ~ArraySort();

    // Getter
    int length();
    Type operator[](int idx);

    // Setter
    void setValue(int idx, Type t);

    // Sort Algorithm
    void selection_sort();

    // Sort Checker
    bool is_sorted();
};

template<typename Type>
ArraySort<Type>::ArraySort(int preserve) {
    this->length_array = preserve;
    this->array_pointer = new Type[length_array];
}

template<typename Type>
ArraySort<Type>::ArraySort() : ArraySort(10) {
}

template<typename Type>
ArraySort<Type>::~ArraySort() {
    delete[] array_pointer;
}

template<typename Type>
int ArraySort<Type>::length() {
    return this->length_array;
}

template<typename Type>
void ArraySort<Type>::setValue(int idx, Type t) {
    this->array_pointer[idx] = t;
}

template<typename Type>
void ArraySort<Type>::selection_sort() {
    for (int i = 0; i < length_array-1; i++) {
        int minidx = i;
        for (int j = i+1; j < length_array; j++) {
            if (array_pointer[j] < array_pointer[minidx]) {
                minidx = j;
            }
        }
        // i and minidx
        Type tmp = array_pointer[i];
        array_pointer[i] = array_pointer[minidx];
        array_pointer[minidx] = tmp;
    }    
}

template<typename Type>
bool ArraySort<Type>::is_sorted() {
    for (int i = 0; i < length_array-1; i++) {
        if (array_pointer[i] > array_pointer[i+1]) {
            return false;
        }
    }
    return true;
}

template<typename Type>
Type ArraySort<Type>::operator[](int idx) {
    if (idx < 0 || idx > length_array - 1) {
        return -10;
    }
    return this->array_pointer[idx];
}