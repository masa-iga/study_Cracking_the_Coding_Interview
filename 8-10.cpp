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


class HashTable {
public:
  HashTable(uint32_t size) :
    size_(size) {
      CHECK(size != 0);
      table_ = new string[size];
    }
  ~HashTable() {
    delete[] table_;
  }

  void set(string key, string val);
  string get(string key);
  void remove(string key);

private:
  uint32_t size_;
  string *table_;
  uint32_t hashFunction(string key, uint32_t max);
};

struct Node {
  Node* next_;
  string d_;
};

void HashTable::set(string key, string val) {
  ;
}

string HashTable::get(string key) {
  return string("0");
}

uint32_t HashTable::hashFunction(string key, uint32_t max) {
  hash<string> str_hash;
  return ((uint32_t)str_hash(key)) % max;
}

/*************************************************
    Test code
*************************************************/

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
  hashTable->set("key1", "val1");
  STRCMP_EQUAL("val1", hashTable->get("key1").c_str());
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
