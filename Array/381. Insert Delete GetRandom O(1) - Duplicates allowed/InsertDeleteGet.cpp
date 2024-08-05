class RandomizedCollection {
public:
    vector<int> v;
    int ind = 0;
    unordered_map<int, set<int>> m; 
    RandomizedCollection() {
        ind = 0;
        v.clear();
        m.clear();
    }
    
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size() - 1);

        if(m[val].size() == 1){ // means item is not present already
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        auto it = m.find(val);//finding value at map
        if(it!=m.end()){// if we got the value at map
            auto pos = *it->second.begin();//finding the position second means set 
            it->second.erase(it->second.begin());//so whatever at the beginning of the set we simply removing it

            v[pos] = v.back();//swap in vector
            m[v.back()].insert(pos);//updating the postion in map
            m[v.back()].erase(v.size()-1);// then erasing the deleted element

            v.pop_back();

            if(it->second.size() == 0){//if size in set is 0 then erase than element from the map
                m.erase(it);
            }
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */