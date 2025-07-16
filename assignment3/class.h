#pragma once

#include <cstddef>

template <typename T>
class myStack {
    public :
        myStack();
        myStack(size_t capacity);
        ~myStack();

        void push(const T& val);
        T& pop();

        T* getData() const;

        size_t size();
        void setCapacity(size_t val);
    private :
        size_t _top;
        size_t _capacity;
        T* _data;

        void resize();
};

#include "class.cpp"