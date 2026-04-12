#ifndef DATABASE_H
#define DATABASE_H

#include "lru.h"

class Database {
private:
    LRUCache cache;

public:
    Database(int capacity);

    void set(string key, string value, long long ttl = -1);
    string get(string key);
    bool del(string key);

    //  NEW
    void saveToFile();
    void loadFromFile();
};

#endif
