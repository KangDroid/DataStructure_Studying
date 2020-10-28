#include <iostream>

using namespace std;

template <typename Type>
class ArraySort {
private:
    Type* array_pointer;
    Type* duplicate_sort;
    size_t length_array;

public:
    ArraySort(size_t preserve);
    ArraySort();
    ~ArraySort();

    // Reserve
    void reserve(size_t amount = 10);

    // Getter
    size_t length();
    Type operator[](size_t idx);

    // Setter
    void setValue(size_t idx, Type t);

    // Sort Algorithm
    void selection_sort();
    void insertion_sort();
    void bubble_sort();

    // Merge(Not sort) Algorithm
    void merge(Type* first_half, Type* second_half, size_t first_length, size_t second_length);
    void _merge(Type* array, size_t start, size_t middle, size_t end);

    void merge_sort();
    void _merge_sort(Type* array, size_t start_point, size_t endpoint);

    // Sort Checker
    bool is_sorted();

    void print() {
        for (size_t i = 0; i < length_array; i++) {
            cout << array_pointer[i] << " ";
        }
        cout << endl;
    }
};

template<typename Type>
ArraySort<Type>::ArraySort(size_t preserve) {
    this->length_array = preserve;
    this->array_pointer = new Type[length_array];
    this->duplicate_sort = new Type[length_array];
}


template<typename Type>
void ArraySort<Type>::merge_sort() {
    _merge_sort(this->array_pointer, 0, this->length_array-1);
}

template<typename Type>
void ArraySort<Type>::_merge_sort(Type* array, size_t start_point, size_t endpoint) {
    if (start_point < endpoint) {
        size_t middle = (start_point+endpoint)/2;
        _merge_sort(array, start_point, middle);
        _merge_sort(array, middle+1, endpoint);
        _merge(array, start_point, middle, endpoint);
        // Merge array - start_posize_t ~ middle
        // Merge Array - middle+1 ~ endpoint
    }
}


template<typename Type>
ArraySort<Type>::ArraySort() : ArraySort(10) {
}

template<typename Type>
ArraySort<Type>::~ArraySort() {
    delete[] array_pointer;
    delete[] duplicate_sort;
}

template<typename Type>
void ArraySort<Type>::reserve(size_t amount) {
    size_t tmplength = this->length_array;
    this->length_array += amount;
    Type *tmp = new Type[length_array];
    for (size_t i = 0; i < tmplength; i++) {
        if (i < tmplength) {
            tmp[i] = array_pointer[i];
        }
    }

    // delete original one
    delete[] array_pointer;
    array_pointer = tmp;
    if (duplicate_sort != nullptr) {
        delete[] duplicate_sort;
    }
    duplicate_sort = new Type[length_array];
}

template<typename Type>
size_t ArraySort<Type>::length() {
    return this->length_array;
}

template<typename Type>
void ArraySort<Type>::setValue(size_t idx, Type t) {
    this->array_pointer[idx] = t;
}

template<typename Type>
void ArraySort<Type>::selection_sort() {
    for (size_t i = 0; i < length_array-1; i++) {
        size_t minidx = i;
        for (size_t j = i+1; j < length_array; j++) {
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
void ArraySort<Type>::insertion_sort() {
    size_t i, j;
    for (i = 1; i < length_array; i++) {
        size_t key = array_pointer[i];
        for (j = i-1; j >= 0; j--) {
            if (key < array_pointer[j]) {
                array_pointer[j+1] = array_pointer[j];
            } else {
                break;
            }
        }
        array_pointer[j+1] = key;
    }
}

template<typename Type>
void ArraySort<Type>::bubble_sort() {
    for (size_t i = 0; i < length_array; i++) {
        for (size_t j = 0; j < length_array; j++) {
            if (array_pointer[j] > array_pointer[i]) {
                // swap j and i
                Type tmp = array_pointer[j];
                array_pointer[j] = array_pointer[i];
                array_pointer[i] = tmp;
            }
        }
    }
}
template<typename Type>
void ArraySort<Type>::_merge(Type* array, size_t start, size_t middle, size_t end) {
    size_t first_idx = start, second_idx = middle+1, add_idx = start;
    while (first_idx <= middle && second_idx <= end) {
        if (array[first_idx] < array[second_idx]) {
            duplicate_sort[add_idx++] = array[first_idx++];
        } else {
            duplicate_sort[add_idx++] = array[second_idx++];
        }
    }

    if (first_idx <= middle) {
        while(first_idx <= middle) {
            duplicate_sort[add_idx++] = array[first_idx++];
        }
    } else if (second_idx <= end) {
        while(second_idx <= end) {
            duplicate_sort[add_idx++] = array[second_idx++];
        }
    }
    for (size_t i = start; i <= end; i++) {
        array[i] = duplicate_sort[i];
    }
}

template<typename Type>
void ArraySort<Type>::merge(Type* first_half, Type* second_half, size_t first_length, size_t second_length) {
    size_t first_iter = 0, second_iter = 0, merge_iter = 0;
    const size_t new_length = first_length + second_length;
    Type* tmp = new Type[new_length];
    while (second_iter < second_length && first_iter < first_length) {
        if (first_half[first_iter] < second_half[second_iter]) {
            tmp[merge_iter] = first_half[first_iter];
            merge_iter++; first_iter++;
        } else {
            tmp[merge_iter] = second_half[second_iter];
            merge_iter++; second_iter++;
        }
    }

    // Check whether anything finished
    if (first_iter == first_length && second_iter < second_length) {
        // Put everything on second - first finished
        while (second_iter < second_length) {
            tmp[merge_iter++] = second_half[second_iter++];
        }
    } else if (second_iter == second_length && first_iter < first_length) {
        // Put everything on first - second finished
        while (first_iter < first_length) {
            tmp[merge_iter++] = first_half[first_iter++];
        }
    } else {
        cout << "Something went wrong." << endl;
    }

    cout << "Combined one:" << endl;
    for (size_t i = 0; i < new_length; i++) {
        cout << tmp[i] << endl;
    }
    delete[] tmp;
}

template<typename Type>
bool ArraySort<Type>::is_sorted() {
    for (size_t i = 0; i < length_array-1; i++) {
        if (array_pointer[i] > array_pointer[i+1]) {
            return false;
        }
    }
    return true;
}

template<typename Type>
Type ArraySort<Type>::operator[](size_t idx) {
    if (idx < 0 || idx > length_array - 1) {
        return -10;
    }
    return this->array_pointer[idx];
}