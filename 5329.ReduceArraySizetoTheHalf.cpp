class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map <int, int> CountMap;
        for(auto it = arr.begin(); it != arr.end(); ++it){
            if(CountMap.count(*it)){
                ++CountMap[*it];
            }
            else{
                CountMap[*it] = 1;
            }
        }
        map<int, int> SortMap;
        for(auto it = CountMap.begin(); it != CountMap.end(); ++it){
            if(SortMap.count(it->second)){
                ++SortMap[it->second];
            }
            else{
                SortMap[it->second] = 1;
            }
        }
        int size = (arr.size()+1)/2;
        int ans = 0;
        for(auto it = SortMap.rbegin(); it != SortMap.rend(); ++it){
            if(it->first * it->second < size){
                ans += it->second;
                size -= it->first * it->second;
            }
            else{
                if(size % it->first != 0) ++ans;
                ans += size/it->first;
                return ans;
            }
        }
        return ans;
        
    }
};
