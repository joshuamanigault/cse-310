#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct node {
    string key;
    node* next;
};

struct hashMap {
    int size;
    int count;
    node** arr;
};

// hash table functions
hashMap* createHashMap(int k);
void insert(hashMap* map, string key);

// output functions
void printFirstFiveSlots(hashMap* map);
void printSlotLengths(hashMap* map);
double calculateStandardDeviation(hashMap* map);

// custom hash function
int hash_function(string text, int k);

#endif