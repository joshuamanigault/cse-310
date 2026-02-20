#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hashMap* createHashMap(int k) {
    hashMap* map = new hashMap;
    map->size = k;
    map->count = 0;
    map->arr = new node*[k];
    for (int i = 0; i < k; i++) {
        map->arr[i] = nullptr;
    }
    return map;
}

void insert(hashMap* map, string key) {
    int index = hash_function(key, map->size);
    node* newNode = new node;
    newNode->key = key;
    newNode->next = map->arr[index];
    map->arr[index] = newNode;
    map->count++;
    return;
}

void printFirstFiveSlots(hashMap* map) {
    for (int i = 0; i < 5 && i < map->size; i++) {
        cout << "Slot " << i << ": ";
        node* current = map->arr[i];
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
    return;
}

void printSlotLengths(hashMap* map) {
    for (int i = 0; i < map->size; i++) {
        int length = 0;
        node* current = map->arr[i];
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << length << endl;
    }

    return;
}

double calculateStandardDeviation(hashMap* map) {
    int K = map->size;
    double mean = double(map->count)/ K;
    double variance = 0.0;

    for (int i = 0; i < K; i++) {
        int length = 0;
        node* current = map->arr[i];
        while (current != nullptr) {
            length++;
            current= current->next;
        }
        variance += pow(length - mean, 2);
    }

    variance /= K;
    return sqrt(variance);
}

int hash_function(string text, int k) {
    int sum = 0;
    
    for (char c : text) {
        sum += c;
    }

    return sum % k;
}