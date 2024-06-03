#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

#include "Iterator/iterator.h"

template <typename T>
class Vector {
public:
    typedef Iterator<T> iterator;
    typedef Iterator<T> const_iterator;

    Vector();
    Vector(unsigned size);
    Vector(T value);
    Vector(unsigned size, T value);
    Vector(std::initializer_list<T> initList);

    ~Vector();

    void setEnd();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    size_t size() const;

    void insert(const T& value, const size_t& index);
    void push_back(const T& value);

    void pop();
    void erase(const size_t& index);
    void erase(const size_t& begin, const size_t& end);
    void clear();

    T& operator[](size_t index);

private:
    T* m_array{};
    T* m_end;
    size_t m_size{};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vector);

template <typename T>
Vector<T>::Vector() : m_array(nullptr), m_end(nullptr), m_size(0) {}

template <typename T>
Vector<T>::Vector(unsigned size) : m_size(size)
{
    try {
        m_array = new T[m_size];
    } catch (const std::bad_alloc& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Not enough memory" << std::endl;
        m_size = 0;
    }
    
    if (m_size)
    {
        T temp;
        for (int i = 0; i < m_size; ++i)
        {
            m_array[i] = temp;
        }
    }
    setEnd();
}

template <typename T>
Vector<T>::Vector(T value) {
    m_array = new T[1];
    T temp;
    m_array[0] = temp;
    setEnd();
}

template <typename T>
Vector<T>::Vector(unsigned size, T value) : m_size(size)
{
    try {
        m_array = new T[m_size];
    } catch (const std::bad_alloc& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Not enough memory" << std::endl;
        m_size = 0;
    }

    if (m_size)
    {
        m_array[0] = value;
        T temp;
        for (int i = 1; i < m_size; ++i)
        {
            m_array[i] = temp;
        }
    }
    setEnd();
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList) {
    m_size = initList.size();
    try {
        m_array = new T[m_size];
    } catch (const std::bad_alloc& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Not enough memory" << std::endl;
        m_size = 0;
    }
    int i = 0;
    for (auto arg : initList) {
        m_array[i++] = arg;
    }
    setEnd();
}

template <typename T>
Vector<T>::~Vector() {
    m_array = nullptr;
    m_end = nullptr;
    m_size = 0;
}

template <typename T>
void Vector<T>::setEnd() { m_end = m_array + m_size; }

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() { return iterator(m_array); }

template <typename T>
typename Vector<T>::iterator Vector<T>::end() { return iterator(m_end); }

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const { return const_iterator(m_array); }

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const { return const_iterator(m_end); }

template <typename T>
size_t Vector<T>::size() const { return m_size; }

template <typename T>
void Vector<T>::insert(const T& value, const size_t& index) {
    T* buff_array;
    try {
        buff_array = new T[++m_size];
    } catch (const std::bad_alloc& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Not enough memory" << std::endl;
    }
    
    for (int i = 0; i < index; i++) { buff_array[i] = m_array[i]; }
    buff_array[index] = value;
    for (int i = index + 1; i < m_size; i++) { buff_array[i] = m_array[i - 1]; }
    delete[] m_array;
    m_array = buff_array;
    setEnd();
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (m_size == 0) {
        m_array = new T[]{ value };
        m_size++;
        m_end = m_array;
    }
    else {
        T* buff_array;
        try {
            buff_array = new T[++m_size];
        } catch (const std::bad_alloc& err) {
            std::cerr << "Error type: " << err.what() << std::endl;
            std::cerr << "Not enough memory" << std::endl;
        }
    
        for (int i = 0; i < m_size - 1; i++) {
            buff_array[i] = m_array[i];
        }
        delete[] m_array;
        buff_array[m_size - 1] = value;
        m_array = buff_array;
        setEnd();
    }
}

template <typename T>
void Vector<T>::pop() {
    if (m_size == 0) { return; }
    T* buff_array = new T[m_size--];
    memcpy(buff_array, m_array, m_size);
    delete[] m_array;
    m_array = buff_array;
    setEnd();
}

template <typename T>
void Vector<T>::erase(const size_t& index) {
    if (
        index < 0 ||
        index > m_size - 1
    ) { return; }

    T* buff_array = new T[--m_size];
    size_t buff_i = 0;
    for (int i = 0; i < m_size + 1; i++) {
        if (i == index) { continue; }
        buff_array[buff_i++] = m_array[i];
    }
    delete[] m_array;
    m_array = buff_array;
    setEnd();
}

template <typename T>
void Vector<T>::erase(const size_t& begin, const size_t& end) {
    if (
        begin < 0 ||
        begin > m_size - 1 ||
        end < 0 ||
        end > m_size - 1 ||
        begin > end
    ) { return; }

    T* buff_array = new T[--m_size];
    size_t buff_i = 0;
    for (int i = 0; i < m_size + 1; i++) {
        if (i >= begin && i <= end) { continue; }
        buff_array[buff_i++] = m_array[i];
    }
    delete[] m_array;
    m_array = buff_array;
    setEnd();
}

template <typename T>
void Vector<T>::clear() {
    if (m_size == 0) { return; }
    delete[] m_array;
    m_end = nullptr;
    m_size = 0;
    this = new Vector();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vec) {
    for (auto iter : vec) {
        out << iter;
    }
    out << "\n";
    return out;
};

template <typename T>
T& Vector<T>::operator[](size_t index) {
    try {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("out_of_range");
        }
        return m_array[index];
    } catch (const std::out_of_range& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Index must be in range [0; " << m_size - 1 << "]" << std::endl;
        return m_array[0];
    }
}

#endif