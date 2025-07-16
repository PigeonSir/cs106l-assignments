/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>
#include "class.h"

void sandbox() {
  myStack<int> intStack;
  intStack.push(10);
  intStack.push(20);
  intStack.push(30);
  std::cout << "there are" << intStack.size() << " elements in intStack" << std::endl;
  int a = intStack.pop(), b = intStack.pop(), c = intStack.pop();
  std::cout << "poping...\n" << " a : " << a << " b : " << b << " c : " << c << std::endl; 
}