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
    T* m_class;
    Iterator(T* _p) : m_class(_p) {}
};



//iterator implementation

template <typename T>
bool Iterator<T>::operator==(const Iterator& _it) const {
    return m_class == _it.m_class;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& _it) const {
    return m_class != _it.m_class;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    m_class++;
    return *this;
}

template <typename T>
T& Iterator<T>::operator*() const {
    return *m_class;
}

#endif //ITERATOR_H