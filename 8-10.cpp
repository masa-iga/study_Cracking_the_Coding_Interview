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
#include <functional>
using namespace std;

class hashTable {
public:
  hashTable(uint32_t size) :
    size_(size) {
    	table_ = new string[size];
    }
  ~hashTable() { delete[] table_; }
  
  void set(string key, string val);
  string get(string key);
  void remove(string key);

private:
  uint32_t size_;
  string *table_;
  uint32_t hashFunction(string key, uint32_t max);
};

uint32_t hashFunction(string key, uint32_t max) {
	hash<string> str_hash;
	return ((uint32_t)str_hash(key)) % max;
}

struct Node {
	Node* next_;
	string d_;
};


int main() {
	return 0;
}
