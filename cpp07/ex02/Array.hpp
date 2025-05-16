#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cmath>

#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _size;
    public:
        Array() : _array(new T[0]), _size(0) {}
        Array(unsigned int n) : _array(new T[n]), _size(n) {}
        Array(Array const &src) : _array(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = src._array[i];
            }
        }
        ~Array() {
            delete[] _array;
        }
        Array &operator=(Array const &other) {
            if (this != &other) {
                delete[] _array;
                _array = new T[other._size];
                _size = other._size;
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = other._array[i];
                }
            }
            return *this;
        }
        T &operator[](unsigned int i) {
            if (i >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _array[i];
        }
        unsigned int size() const {
            return _size;
        }
};

#endif