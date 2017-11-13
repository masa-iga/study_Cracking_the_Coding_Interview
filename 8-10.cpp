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



/*
  Interface:
    map<string, int> hash;
    hash[key] = 10;
    int a = hash[key];
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


struct Node {
  Node* next_ = NULL;
  string key_;
  string val_;
  Node() {};
  Node(string key, string val)
  : key_(key),
    val_(val)
  { };
};

class HashTable {
public:
  HashTable(uint32_t size)
  : size_(size)
  {
    CHECK(size > 0);
    table_ = new Node*[size];
  }
  ~HashTable() {
    for (uint32_t i = 0; i < size_; i++) {
      Node *node = table_[i];
      while (node != NULL) {
        Node *next = node->next_;
        delete node;
        node = next;
      }
    }
    delete[] table_;
  }

  void set(string key, string val);
  string get(string key);
  void remove(string key);

private:
  const uint32_t size_;
  Node **table_;
  uint32_t hashFunction(string key, uint32_t max);
};

void HashTable::set(string key, string val) {
  const uint32_t idx = hashFunction(key, size_);
  CHECK(0 <= idx && idx < size_);
  printf("%s : table_[%d] = %p\n",
    __func__, idx, table_[idx]);
  if (table_[idx] == NULL) {
    table_[idx] = new Node(key, val);
    printf("%s : allocate Node(%s, %s) @ %p\n",
      __func__, key.c_str(), val.c_str(), table_[idx]);
    return ;
  }
  Node *pNode = table_[idx];
  while (pNode->next_ != NULL) {
    pNode = pNode->next_;
  }
  pNode->next_ = new Node(key, val);
  cout << __func__ << " : pNode = " << pNode << endl;
  cout << __func__ << " : (key, val) = (" << key << ", " << val << ")" << endl;
}

string HashTable::get(string key) {
  const uint32_t idx = hashFunction(key, size_);
  cout << __func__ << " : idx = " << idx << endl;
  Node *pNode = table_[idx];
  while (pNode != NULL && pNode->key_ != key) {
    cout << __func__ << " : (key, val) = (" << pNode->key_ << ", " << pNode->val_ << ")" << endl;
    pNode = pNode->next_;
  }
  cout << __func__ << " : pNode = " << pNode << endl;
  const string none = "";
  if (pNode == NULL)
    return none;
  else
    return pNode->val_;
}

uint32_t HashTable::hashFunction(string key, uint32_t max) {
#if TEST_CHAINING
  return 1;
#else
  hash<string> str_hash;
  return ((uint32_t)str_hash(key)) % max;
#endif //TEST_CHAINING
}

/*******************************
    Test code
*******************************/

TEST_GROUP(FirstTestGroup)
{
    HashTable *hashTable;
    const uint32_t size = 1000;
    TEST_SETUP() {
        hashTable = new HashTable(size);
    }
    TEST_TEARDOWN() {
        delete hashTable;
    }
};

TEST(FirstTestGroup, GeneralPattern) {
  cout << "---   FirstTestGroup   ---" << endl;

  const string key0("key0");
  const string val0("val0");
  hashTable->set(key0, val0);
  STRCMP_EQUAL(val0.c_str(), hashTable->get(key0).c_str());

  const string key1("key1");
  const string val1("val1");
  hashTable->set(key1, val1);
  STRCMP_EQUAL(val1.c_str(), hashTable->get(key1).c_str());

  const string key2("key2");
  const string val2("val2");
  hashTable->set(key2, val2);
  STRCMP_EQUAL(val2.c_str(), hashTable->get(key2).c_str());
  STRCMP_EQUAL(val0.c_str(), hashTable->get(key0).c_str());
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
