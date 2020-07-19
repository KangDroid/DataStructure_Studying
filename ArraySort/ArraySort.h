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
Type ArraySort<Type>::operator[](int idx) {
    if (idx < 0 || idx > length_array - 1) {
        return -10;
    }
    return this->array_pointer[idx];
}