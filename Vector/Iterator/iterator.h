#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>

template <typename T>
class Iterator {
    template <typename>
    friend class Vector;

public:
    bool operator==(const Iterator& _it) const;
    bool operator!=(const Iterator& _it) const;
    Iterator& operator++();
    T& operator*() const;

private:
    T* m_object;
    Iterator(T* new_object) : m_object(new_object) {}
};

template <typename T>
bool Iterator<T>::operator==(const Iterator& _it) const {
    return m_object == _it.m_object;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& _it) const {
    return m_object != _it.m_object;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    m_object++;
    return *this;
}

template <typename T>
T& Iterator<T>::operator*() const {
    return *m_object;
}

#endif