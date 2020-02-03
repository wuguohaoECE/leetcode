//时间O(m+n) 空间O(1) 从后往前
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, curr = nums1.size()-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[curr] = nums1[i];
                --i;
            }
            else{
                nums1[curr] = nums2[j];
                --j;
            }
            //cout << nums1[curr] << endl;
            --curr;
        }
        while(i >= 0){
            nums1[curr] = nums1[i];
            //cout << nums1[curr] << endl;
            --i;
            --curr;
        }
        while(j >= 0){
            nums1[curr] = nums2[j];
            --j;
            --curr;
        }
        ++curr;
        for(int i = 0; i < m+n; ++i){
            nums1[i] = nums1[curr];
            ++curr;
        }
    }
};
