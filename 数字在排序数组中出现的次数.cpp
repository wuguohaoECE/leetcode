class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        if(data.size() == 1 && data[0] == k) return 1;
        if(data.size() == 1) return 0;
        int left = data[0]==k? 0 : FindLeft(data, 0, data.size()-1, k);
        int right = data[data.size()-1]==k ? data.size()-1 : FindRight(data, 0, data.size()-1,k);
        if(left == -1 || right == -1) return 0;
        return right-left+1;
    }
    int FindLeft(vector<int> data, int begin, int end, int k){
        if(end - begin == 1){
            if(data[end] == k){
                if(data[begin] < k) return end;
                if(data[begin] == k) return begin;
            }
            return -1;
        }
        int mid = (begin + end)/2;
        if(data[mid] >= k) return FindLeft(data, begin, mid, k);
        return FindLeft(data, mid, end, k);
    }
    int FindRight(vector<int> data, int begin, int end, int k){
        if(end - begin == 1){
            if(data[begin] == k){
                if(data[end] >= k) return begin;
                if(data[end] == k) return end;
            }
            return -1;
        }
        int mid = (begin + end)/2;
        if(data[mid] > k) return FindRight(data, begin, mid, k);
        return FindRight(data, mid, end, k);
    }
};
