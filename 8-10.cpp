/*
  Question:
    Design and implement a hash table which uses chaining (linked lists) to handle collisions.
  
  Approach:
    1. Handle ambiguity
    2. Define core objects
    3. Analyize relationships
    4. Investigate actions
*/



/*
  Collision resolution in hash table
    1. Separate chaining
    2. Open addressing
    3. ...
*/    



//#define TEST_CHAINING (1)

#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <functional>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
using namespace std;


template <class T, class U>
struct Node {
  Node* next_ = NULL;
  T key_;
  U val_;
  Node() {};
  Node(T key, U val);
  bool equivalent(Node<T, U> node);
  bool equivalent(T key);
};

template <class T, class U>
Node<T, U>::Node(T key, U val)
: key_(key),
  val_(val)
{
  cout << __func__ << " : New node created. ("
    << key << ", " << val << ") @ " << this
    << endl;
}

template <class T, class U>
bool Node<T, U>::equivalent(Node<T, U> node) {
  return (node.key == key_);
}

template <class T, class U>
bool Node<T, U>::equivalent(T key) {
  return (key == key_);
}

template <class T, class U>
class HashTable {
public:
  HashTable(uint32_t size);
  ~HashTable();

  void put(T key, U val);
  U get(T key);
  void remove(T key);

private:
  const uint32_t size_;
  Node<T, U> **table_;
  uint32_t hashFunc(T key, uint32_t max);
};


template <class T, class U>
HashTable<T, U>::HashTable(uint32_t size)
: size_(size)
{
    CHECK(size > 0);
    table_ = new Node<T, U>*[size];
}

template <class T, class U>
HashTable<T, U>::~HashTable() {
  for (uint32_t i = 0; i < size_; i++) {
    Node<T, U> *node = table_[i];
    while (node != NULL) {
      Node<T, U> *next = node->next_;
      delete node;
      node = next;
    }
  }
  delete[] table_;
}

template <class T, class U>
void HashTable<T, U>::put(T key, U val) {
  const uint32_t idx = hashFunc(key, size_);
  CHECK(0 <= idx && idx < size_);
  printf("%s : table_[%d] = %p\n", __func__, idx, table_[idx]);
  if (table_[idx] == NULL) {
    table_[idx] = new Node<T, U>(key, val);
    return ;
  }
  /* Look for items with same key and replace if found.
   * Add the key if not found */
  Node<T, U> *pNode = table_[idx];
  while (pNode->equivalent(key) || pNode->next_ != NULL) {
    pNode = pNode->next_;
  }
  if (pNode->equivalent(key)) {
    pNode->val_ = val;
    // Replace, or remove and add it at the tail of the linked list
    return ;
  }

  pNode->next_ = new Node<T, U>(key, val);
}

template <class T, class U>
U HashTable<T, U>::get(T key) {
  const uint32_t idx = hashFunc(key, size_);
  Node<T, U> *pNode = table_[idx];
  cout << __func__ << " : idx = " << idx << endl;
  while (pNode != NULL && !pNode->equivalent(key)) {
    pNode = pNode->next_;
  }

  if (pNode != NULL)
    return pNode->val_;

  cout << __func__
    << " : Warn that cannot find the corresponding value from hash table (key = "
    << key << ")" << endl;

  return NULL;
}

template <class T, class U>
void HashTable<T, U>::remove(T key) {
  ;
}

template <class T, class U>
uint32_t HashTable<T, U>::hashFunc(T key, uint32_t max) {
#if TEST_CHAINING
  return 1;
#else
  hash<T> hash;
  return ((uint32_t)hash(key)) % max;
#endif //TEST_CHAINING
}

/*******************************
    Test code
*******************************/

TEST_GROUP(FirstTestGroup)
{
    HashTable<string, string> *hashTable;
    const uint32_t size = 1000;
    TEST_SETUP() {
        hashTable = new HashTable<string, string>(size);
    }
    TEST_TEARDOWN() {
        delete hashTable;
    }
};

TEST(FirstTestGroup, GeneralPattern) {
  cout << "---   FirstTestGroup   ---" << endl;

  const string key0("key0");
  const string val0("val0");
  hashTable->put(key0, val0);
  STRCMP_EQUAL(val0.c_str(), hashTable->get(key0).c_str());

  const string key1("key1");
  const string val1("val1");
  hashTable->put(key1, val1);
  STRCMP_EQUAL(val1.c_str(), hashTable->get(key1).c_str());

  const string key2("key2");
  const string val2("val2");
  hashTable->put(key2, val2);
  STRCMP_EQUAL(val2.c_str(), hashTable->get(key2).c_str());
  STRCMP_EQUAL(val0.c_str(), hashTable->get(key0).c_str());
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
