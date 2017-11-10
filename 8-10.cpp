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
  string d_;
};

class HashTable {
public:
  HashTable(uint32_t size)
  : size_(size)
  {
    CHECK(size > 0);
#if 0
    table_ = new string[size];
#endif
    table_ = new Node*[size];
  }
  ~HashTable() {
    delete[] table_;
  }

  void set(string key, string val);
  string get(string key);
  void remove(string key);

private:
  const uint32_t size_;
#if 0
  string *table_;
#endif
  Node **table_;
  uint32_t hashFunction(string key, uint32_t max);
};

void HashTable::set(string key, string val) {
  const uint32_t idx = hashFunction(key, size_);
  CHECK(0 <= idx && idx < size_);
#if 0
  table_[idx] = val;
#endif
  Node *pNode = table_[idx];
  while (pNode != NULL) {
    pNode = pNode->next_;
  }
}

string HashTable::get(string key) {
  const uint32_t idx = hashFunction(key, size_);
#if 0
  return table_[idx];
#endif
  Node *pNode = table_[idx];
  while (pNode != NULL && pNode->d_ != key) {
    pNode = pNode->next_;
  }
  const string none = "";
  if (pNode != NULL)
    return table_[idx]->d_;
  else
    return none;
}

uint32_t HashTable::hashFunction(string key, uint32_t max) {
  hash<string> str_hash;
  return ((uint32_t)str_hash(key)) % max;
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

  const string key0("key1");
  const string exp0("val1");
  hashTable->set(key0, exp0);
  STRCMP_EQUAL(exp0.c_str(), hashTable->get(key0).c_str());

  const string key1("123bs");
  const string exp1("2323");
  hashTable->set(key1, exp1);
  STRCMP_EQUAL(exp1.c_str(), hashTable->get(key1).c_str());

  const string key2(key0);
  const string exp2("aAz");
  hashTable->set(key2, exp2);
  STRCMP_EQUAL(exp2.c_str(), hashTable->get(key2).c_str());
  STRCMP_EQUAL(exp0.c_str(), hashTable->get(key0).c_str());
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
