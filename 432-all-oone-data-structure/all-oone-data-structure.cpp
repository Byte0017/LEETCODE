class AllOne {
public:
    unordered_map<string, int> mp;  // Maps key to its count
    map<int, set<string>> freqMap;  // Maps count to a set of keys with that count

    AllOne() {
        
    }

    void inc(string key) {
        int count = mp[key];
        mp[key]++;  // Increment the count of the key

        if (count > 0) {
            // Remove the key from the old count set
            freqMap[count].erase(key);
            if (freqMap[count].empty()) {
                freqMap.erase(count);  // Clean up empty sets
            }
        }

        // Add the key to the new count set
        freqMap[mp[key]].insert(key);
    }

    void dec(string key) {
        if (mp[key] == 0) return;  // Key doesn't exist

        int count = mp[key];
        // Remove the key from the current count set
        freqMap[count].erase(key);
        if (freqMap[count].empty()) {
            freqMap.erase(count);  // Clean up empty sets
        }

        mp[key]--;  // Decrement the count of the key

        if (mp[key] == 0) {
            // Remove the key from the map if its count reaches 0
            mp.erase(key);
        } else {
            // Add the key to the new count set
            freqMap[mp[key]].insert(key);
        }
    }

    string getMaxKey() {
        if (freqMap.empty()) return "";  // Return empty string if no keys are present
        auto it = freqMap.rbegin();  // Get the last element (max count)
        return *(it->second.begin());  // Return any key with the max count
    }

    string getMinKey() {
        if (freqMap.empty()) return "";  // Return empty string if no keys are present
        auto it = freqMap.begin();  // Get the first element (min count)
        return *(it->second.begin());  // Return any key with the min count
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
