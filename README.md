# 🚀 Mini Redis - In-Memory Key-Value Database (C++)

## 📌 Overview
Mini Redis is a high-performance, in-memory key-value database built in C++.  
It replicates core functionalities of Redis, including fast data access, LRU-based eviction, TTL expiry, and file-based persistence.

This project demonstrates strong understanding of **Data Structures, System Design, and Performance Optimization**, making it highly relevant for backend and software engineering roles.

---

## ✨ Features

- ⚡ **O(1) SET, GET, DELETE operations**
- 🧠 **LRU Cache (Least Recently Used Eviction)**
- ⏳ **TTL (Time-To-Live) based expiry**
- 💾 **File-based Persistence (data survives restart)**
- 🖥️ **Command Line Interface (CLI)**
- ✅ **Robust input validation & error handling**

---

## 🧠 System Design

### 🔹 Core Components

- **HashMap (`unordered_map`)**
  - Enables constant-time lookup of keys

- **Doubly Linked List**
  - Maintains order of usage
  - Supports efficient LRU eviction

- **TTL Mechanism**
  - Each key stores an expiry timestamp
  - Expired keys are removed during access

- **Persistence Layer**
  - Stores key-value data in `data.txt`
  - Reloads valid data on restart

---

## ⚙️ Architecture
User Command → Parser → Database → LRU Cache → Memory + File Storage

---

## 🛠️ Tech Stack

- **Language:** C++
- **Libraries:** STL (`unordered_map`, pointers, file streams)
- **Concepts:** Data Structures, OOP, System Design

---

## ▶️ How to Run

```bash
cd src
g++ main.cpp database.cpp lru.cpp -o app
.\app





#######################
Usage Example
SET name Dushant 3000
GET name        → Dushant
(wait 3 seconds)
GET name        → Key not found or expired
#######################
