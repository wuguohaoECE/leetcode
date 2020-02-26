URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-url-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

从后往前替换，不需要额外空间
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int i = S.length()-1;
        int j = length-1;
        while(j >= 0){
            if(S[j] == ' '){
                S[i--] = '0';
                S[i--] = '2';
                S[i--] = '%';
                j--;
            }
            else{
                S[i--] = S[j--];
            }
        }
        return S.substr(i+1);
    }
};
