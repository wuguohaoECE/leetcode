bool compare(string a, string b){
        string ab = a+b;
        string ba = b+a;
        if(stoi(ab) < stoi(ba)) return true;
        return false;
    }
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> numbersStr;
        for(size_t i = 0; i < numbers.size(); ++i){
            numbersStr.push_back(to_string(numbers[i]));
        }
        sort(numbersStr.begin(), numbersStr.end(), compare);
        string output;
        for(size_t i = 0; i < numbersStr.size(); ++i){
            output.append(numbersStr[i]);
        }
        return output;
    }
};
