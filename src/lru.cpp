#include "lru.h"

// Constructor
LRUCache::LRUCache(int cap) {
    capacity = cap;

    head = new Node("", "", -1);
    tail = new Node("", "", -1);

    head->next = tail;
    tail->prev = head;
}

// Remove node from DLL
void LRUCache::remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Insert node at front
void LRUCache::insert(Node* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

// SET operation with TTL
void LRUCache::set(string key, string value, long long ttl) {

    long long expiry = -1;

    if (ttl != -1) {
        long long now = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()
        ).count();

        expiry = now + ttl;
    }

    // Remove old key if exists
    if (mp.find(key) != mp.end()) {
        Node* node = mp[key];
        remove(node);
        mp.erase(key);
    }

    // Remove LRU if full
    if (mp.size() == capacity) {
        Node* lru = tail->prev;
        remove(lru);
        mp.erase(lru->key);
    }

    Node* newNode = new Node(key, value, expiry);
    insert(newNode);
    mp[key] = newNode;
}

// GET operation with expiry check
string LRUCache::get(string key) {
    if (mp.find(key) == mp.end()) return "NULL";

    Node* node = mp[key];

    long long now = chrono::duration_cast<chrono::milliseconds>(
        chrono::system_clock::now().time_since_epoch()
    ).count();

    // Check expiry
    if (node->expiry != -1 && now > node->expiry) {
        remove(node);
        mp.erase(key);
        return "NULL";
    }

    // Move to front (recently used)
    remove(node);
    insert(node);

    return node->value;
}

// DELETE operation
bool LRUCache::del(string key) {
    if (mp.find(key) != mp.end()) {
        Node* node = mp[key];
        remove(node);
        mp.erase(key);
        return true;
    }
    return false;
}
