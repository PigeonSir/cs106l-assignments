#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << "User(name=" << user._name << ", friends=[";
  for (int i = 0; i < user._size; i++) {
    if (i != 0)
      os << ", ";
    os << user._friends[i];
  }
  os << "])";
  return os;
}

User::~User(void){
  delete [] _friends;
}

User::User(const User& other) {
  _name = other._name;
  _size = other._size;
  _capacity = other._capacity;
  _friends = new std::string[_capacity];
  for (int i = 0; i < _size; i++)
    _friends[i] = other._friends[i];
}

User& User::operator=(const User& other) {
  if (this == &other)
    return *this;
  delete [] this->_friends;
  this->_name = other._name;
  this->_size = other._size;
  this->_capacity = other._capacity;
  this->_friends = new std::string[this->_capacity];
  for (int i = 0; i < _size; i++)
    this->_friends[i] = other._friends[i];
  return *this;
}