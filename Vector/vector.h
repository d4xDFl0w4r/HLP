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
    Vector(unsigned _size);
    Vector(T _value);
    Vector(unsigned _size, T _value);
    Vector(std::initializer_list<T> _initList);

    ~Vector();

    void setEnd();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    size_t size() const;

    void insert(const T& _value, const size_t& index);
    void push_back(const T& _value);

    void pop();
    void erase(const size_t& index);
    void clear();

    void sort(bool ascendingOrder);

    T operator[](size_t index) const;

private:
    T* m_array{};
    T* m_end;
    size_t m_size{};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vector);

//vector implementation


template <typename T>
Vector<T>::Vector() : m_array(nullptr), m_end(nullptr), m_size(0) {}

template <typename T>
Vector<T>::Vector(unsigned _size) : m_size(_size)
{
    m_array = new T[m_size];
    if (m_size)
    {
        T _temp;
        for (int i = 0; i < m_size; ++i)
        {
            m_array[i] = _temp;
        }
    }
    setEnd();
}

template <typename T>
Vector<T>::Vector(T _value) {
    m_array = new T[1];
    T _temp;
    m_array[0] = _temp;
    setEnd();
}

template <typename T>
Vector<T>::Vector(unsigned _size, T _value) : m_size(_size)
{
    m_array = new T[m_size];
    if (m_size)
    {
        m_array[0] = _value;
        T _temp;
        for (int i = 1; i < m_size; ++i)
        {
            m_array[i] = _temp;
        }
    }
    setEnd();
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> _initList) {
    m_size = _initList.size();
    m_array = new T[m_size];
    int i = 0;
    for (auto arg : _initList) {
        m_array[i++] = arg;
    }
    setEnd();
}

template <typename T>
Vector<T>::~Vector() {
    delete [] m_array;
    delete m_end;
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
void Vector<T>::insert(const T& _value, const size_t& index) {
    T* tmp_array = new T[m_size++];
    for (int i = 0; i < index; i++) { tmp_array[i] = m_array[i]; }
    tmp_array[index] = _value;
    for (int i = index + 1; i < m_size; i++) { tmp_array[i] = m_array[i - 1]; }
    delete[] m_array;
    m_array = tmp_array;
    setEnd();
}

template <typename T>
void Vector<T>::push_back(const T& _value) {
    if (m_size == 0) {
        m_array = new T[]{_value};
        m_size++;
        m_end = m_array;
    } else {
        T* tmp_array = new T[++m_size];
        memcpy(tmp_array, m_array, (m_size - 1) * sizeof(T));
        delete[] m_array;
        tmp_array[m_size - 1] = _value;
        m_array = tmp_array;
        setEnd();
    }
}

template <typename T>
void Vector<T>::pop() {
    if (m_size == 0) { return; }
    T* tmp_array = new T[m_size--];
    memcpy(tmp_array, m_array, m_size);
    delete[] m_array;
    m_array = tmp_array;
    setEnd();
}

template <typename T>
void Vector<T>::erase(const size_t& index) {
    T* tmp_array = new T[m_size--];
    size_t tmp_i = 0;
    for (int i = 0; i < m_size + 1; i++) {
        if (i == index) { continue; }
        tmp_array[tmp_i] = m_array[i++];
    }
    delete[] m_array;
    m_array = tmp_array;
    setEnd();
}

template <typename T>
void Vector<T>::clear() {
    delete[] m_array;
    this = new Vector();
}

template <typename T>
void Vector<T>::sort(bool ascendingOrder) {
    if (m_size < 2) {
        return;
    }
    if (ascendingOrder) {
        for (size_t i = 0; i < m_size - 1; i++) {
            if (m_array[i] > m_array[i + 1]) {
                T tmp = m_array[i];
                m_array[i] = m_array[i + 1];
                m_array[i + 1] = tmp;
            }
        }
    } else {
        for (size_t i = 0; i < m_size - 1; i++) {
            if (m_array[i] < m_array[i + 1]) {
                T tmp = m_array[i];
                m_array[i] = m_array[i + 1];
                m_array[i + 1] = tmp;
            }
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T> vec) {
    for (auto iter : vec) {
        out << iter;
    }
    out << "\n";
    return out;
};

template <typename T>
T Vector<T>::operator[](size_t index) const{
    try {
        return m_array[index];
    } catch (std::logic_error error) {
        throw error;
    }
}

#endif //VECTOR_H