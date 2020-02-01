class LRUCache {
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator > map;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(map.count(key)) {
            int value = (*map[key]).second;
            cache.erase(map[key]);
            cache.push_front({key, value});
            map[key] = cache.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            cache.erase(map[key]);
            map.erase(key);
        }
        if(cache.size() == size){
            map.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
