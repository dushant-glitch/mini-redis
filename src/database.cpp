#include "database.h"
#include <fstream>

// Constructor
Database::Database(int capacity) : cache(capacity) {}

// SET
void Database::set(string key, string value, long long ttl) {
    cache.set(key, value, ttl);
}

// GET
string Database::get(string key) {
    return cache.get(key);
}

// DELETE
bool Database::del(string key) {
    return cache.del(key);
}

// SAVE DATA TO FILE
void Database::saveToFile() {
    ofstream file("data.txt");

    Node* curr = cache.head->next;

    while (curr != cache.tail) {
        file << curr->key << " " << curr->value << " " << curr->expiry << endl;
        curr = curr->next;
    }

    file.close();
}

// LOAD DATA FROM FILE
void Database::loadFromFile() {
    ifstream file("data.txt");

    string key, value;
    long long expiry;

    while (file >> key >> value >> expiry) {

        long long now = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()
        ).count();

        // skip expired
        if (expiry != -1 && now > expiry) continue;

        long long ttl = (expiry == -1) ? -1 : (expiry - now);

        cache.set(key, value, ttl);
    }

    file.close();
}
