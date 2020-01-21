class Solution {
public:
     void reverse(string& str, int begin, int end){
        while(begin < end){
            swap(str[begin], str[end]);
            ++begin;--end;
        }
    }    
    string ReverseSentence(string str) {
        reverse(str, 0, str.length()-1);
        cout << str << endl;
        int i = 0; int j = 0;
        while(i != -1 && j != -1 && j != str.length()){
            i = j;
            i = str.find_first_not_of(" ", i);
            j = str.find(" ", i);
            if(i != -1 && j == -1){
                j = str.length();
            }
            reverse(str, i, j-1);
        }
        return str;
    }
};
