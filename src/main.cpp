#include <bits/stdc++.h>
#include "database.h"
using namespace std;

int main() {
    Database db(2); // capacity = 2

    // Load previous data from file
    db.loadFromFile();

    string command;

    cout << "Mini Redis Started (type EXIT to stop)\n";

    while (true) {
        getline(cin, command);

        if (command.empty()) continue;

        stringstream ss(command);
        string op, key, value;

        ss >> op;

        //  SET
        if (op == "SET") {
            if (!(ss >> key >> value)) {
                cout << "Invalid SET command. Usage: SET key value [ttl]" << endl;
                continue;
            }

            long long ttl;
            if (ss >> ttl) {
                db.set(key, value, ttl);
            } else {
                db.set(key, value);
            }

            //  Save to file after update
            db.saveToFile();

            cout << "Added successfully" << endl;
        }

        // GET
        else if (op == "GET") {
            ss >> key;

            string result = db.get(key);

            if (result == "NULL")
                cout << "Key not found or expired" << endl;
            else
                cout << result << endl;
        }

        // DELETE
        else if (op == "DEL") {
            ss >> key;

            if (db.del(key)) {
                db.saveToFile(); // Save after delete
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Key not found" << endl;
            }
        }

        // EXIT
        else if (op == "EXIT") {
            cout << "Exiting Mini Redis...\n";
            break;
        }

        //INVALID COMMAND
        else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
