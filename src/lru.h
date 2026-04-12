#ifndef LRU_H
#define LRU_H

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string key, value;
    long long expiry;
    Node* prev;
    Node* next;

    Node(string k, string v, long long exp) {
        key = k;
        value = v;
        expiry = exp;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<string, Node*> mp;

public:
    Node* head;   // moved to public
    Node* tail;   // moved to public

    LRUCache(int cap);

    void set(string key, string value, long long ttl = -1);
    string get(string key);
    bool del(string key);

    void remove(Node* node);
    void insert(Node* node);
};

#endif
