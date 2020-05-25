class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        string str_num= to_string(x);        
        int start = 0;
        int end = str_num.length()-1;
        
        while (start <= end) {
            if (str_num[start] != str_num[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
