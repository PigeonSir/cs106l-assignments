#include <stdexcept>

template <typename T>
myStack<T>::myStack()
{
    _top = -1;
    _capacity = 4;
    _data = new T[_capacity];
}

template <typename T>
myStack<T>::myStack(size_t capacity)
{
    _top = -1;
    _capacity = capacity;
    _data = new T[_capacity];
}


template <typename T>
myStack<T>::~myStack()
{
    delete[] _data;
}

template <typename T>
void myStack<T>::resize()
{
  auto newData = new T[_capacity * 2];
  for (size_t i = 0; i <= _top; i++)
  {
    newData[i] = _data[i];
  }

  delete[] _data;
  _capacity *= 2;
  _data = newData;
}

template <typename T>
T& myStack<T>::pop()
{
    T& ret = _data[_top];
    --_top;
    return ret;
}

template <typename T>
void myStack<T>::push(const T& val)
{
    if (_top == _capacity)
        resize();
    _data[++_top] = val;
}

template <typename T>
T* myStack<T>::getData() const {
    return _data;
}

template <typename T>
size_t myStack<T>::size() {
    return _top + 1;
}

template <typename T>
void myStack<T>::setCapacity(size_t val) {
    if (val > _capacity)
        _capacity = val;
}