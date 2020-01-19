class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() <= 1) return 0;
        vector<int> copy(data);
        int count = Helper(data, copy, 0, data.size()-1);
        return count ;
    }
    int Helper(vector<int>& data, vector<int>& copy, int start, int end){
        if(start == end) {
            copy[start] = data[start]; //这行感觉没啥用
            return 0;
        }
        int length = (end - start)/2;
        int left = Helper(copy, data, start, start+length);
        int right = Helper(copy, data, start+length+1, end);
        int i = start+length;
        int j = end;
        int IndexToCopy = end;
        int count = 0;
        while(i >= start && j >= start+length+1){
            if(data[i] > data[j]){
                copy[IndexToCopy--] = data[i--]; //IndexToCopy-- 输出的值是减之前的值
                count += j - start - length;
            }
            else{
                copy[IndexToCopy--] = data[j--];
            }
        }
        for(; i >= start; --i){
            copy[IndexToCopy--] = data[i];
        }
        for(; j >= start+length+1; --j){
            copy[IndexToCopy--] = data[j];
        }
        return count+left+right;
    }
};
