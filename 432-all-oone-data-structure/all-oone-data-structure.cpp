class AllOne {
public:
    unordered_map<string, int> mp;  
    map<int, set<string>> freqMap;

    AllOne() {
        
    }

    void inc(string key) {
        int count = mp[key];
        mp[key]++;

        if (count > 0) {
            freqMap[count].erase(key);
            if (freqMap[count].empty()) {
                freqMap.erase(count); 
            }
        }
        freqMap[mp[key]].insert(key);
    }

    void dec(string key) {
        if (mp[key] == 0) return;
        int count = mp[key];
        freqMap[count].erase(key);
        if (freqMap[count].empty()) {
            freqMap.erase(count);
        }
        mp[key]--;

        if (mp[key] == 0) {
            mp.erase(key);
        } else {
            freqMap[mp[key]].insert(key);
        }
    }

    string getMaxKey() {
        if (freqMap.empty()) return ""; 
        auto it = freqMap.rbegin(); 
        return *(it->second.begin());
    }

    string getMinKey() {
        if (freqMap.empty()) return ""; 
        auto it = freqMap.begin();
        return *(it->second.begin());
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
