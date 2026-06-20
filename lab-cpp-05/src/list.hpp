#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <algorithm>

template <typename T>
class List
{
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize()
    {
        capacity *= 2;

        T* temp = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
    }

public:
    List()
        : size(0),
          capacity(10)
    {
        data = new T[capacity];
    }

    ~List()
    {
        delete[] data;
    }

    void add(const T& value)
    {
        if (size >= capacity) {
            resize();
        }

        data[size++] = value;
    }

    void remove(size_t index)
    {
        if (index >= size) {
            return;
        }

        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    int findIndex(const T& value) const
    {
        for (size_t i = 0; i < size; i++) {

            if (data[i] == value) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }

    void sort()
    {
        std::sort(data, data + size);
    }

    T getMin() const
    {
        T min = data[0];

        for (size_t i = 1; i < size; i++) {

            if (data[i] < min) {
                min = data[i];
            }
        }

        return min;
    }

    void print() const
    {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }

    size_t getSize() const
    {
        return size;
    }

    T operator[](size_t index) const
    {
        return data[index];
    }
};

#endif
