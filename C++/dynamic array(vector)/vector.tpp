
/**
 * @file vector.tpp
 * @brief Class template of dynamically allocated array
 */


#include <cassert>


template<typename T>
Vector<T>::Vector() {
    arr = new T[1];
    cap = 1;
    cur = 0;
}


template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
}


template<typename T>
void Vector<T>::pushBack(T data) {
    /*
     * the capacity of the vector doubles every time storage is full and
     * updates the data.
     */
    if(cur == cap){
        T* new_arr = new T[2*cap];
        for(int i=0; i<cap; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cap *= 2;
    }
    arr[cur++] = data;
}


template<typename T>
void Vector<T>::popBack() {
    cur--;
}


template<typename T>
void Vector<T>::clear() {
    cur = 0;
}


template<typename T>
void Vector<T>::remove(int i) {
    assert(i>=0 && i<cur);
    for(int j=i; j<cur-2; j++) {
        arr[j]=arr[j+1];
    }
    cur--;
}


template<typename T>
int Vector<T>::size() const {
    return cur;
}


template<typename T>
int Vector<T>::capacity() const {
    return cap;
}


template<typename T>
T& Vector<T>::operator[](int i) {
    assert(i>=0 && i<cur);
    return arr[i];
}


template<typename T>
T const& Vector<T>::operator[](int i) const {
    assert(i>=0 && i<cur);
    return arr[i];
}


template<typename T>
std::ostream& operator<<(std::ostream &ostr, const Vector<T> &vec) {
    ostr << '[';

    for(int i=0; i<vec.size(); i++) {
        ostr << vec[i] << " ";
    }
    ostr << "\b]";
    return ostr;
}
