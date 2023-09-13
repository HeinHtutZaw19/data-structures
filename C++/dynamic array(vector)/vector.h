
/**
 * @file vector.h
 * @brief Class template of dynamically allocated array
 */


#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <ostream>


/**
 * @brief Class template of dynamically allocated array
 */
template<typename T>
class Vector {
    private:
        T *arr; ///< Points to the address where the data is stored
        int cap; ///< The storage size of the vector
        int cur; ///< The current number of elements in the vector

    public:
        /**
         * @brief Default constructor
         */
        Vector();

        /**
         * @brief Destructor
         */
        ~Vector();

        /**
         * @brief Insertion of an element at the back of existing elements
         *
         * @param data Element to insert
         */
        void pushBack(T data);

        /**
         * @brief Removes the last element of the array
         */
        void popBack();

        /**
         * @brief Cleans up the array
         */
        void clear();

        /**
         * @brief Deletes the element of the array at specified index
         *
         * @param i Array index
         */
        void remove(int i);

        /**
         * @brief Gets the number of elements in the array
         *
         * @return Current number of elements
         */
        int size() const;

        /**
         * @brief Gets the storage size of the array
         *
         * @return Array storage size
         */
        int capacity() const;

        /**
         * @brief Random access to the contents of the array
         *
         * @param i Array index
         *
         * @return Reference to the element of specified index
         */
        T& operator[](int i);

        /**
         * @brief Random access to the contents of the array
         *
         * @param i Array index
         *
         * @return Reference to the element of specified index
         */
        T const& operator[](int i) const;
};

/**
 * @brief Shows the contents of the array to the output stream
 *
 * @param ostr Output stream object
 * @param vec The Vector class to print
 *
 * @return Reference to the output stream
 */
template<typename T>
std::ostream& operator<<(std::ostream &ostr, const Vector<T> &vec);


#include "vector.tpp"

#endif // VECTOR_H_INCLUDED
