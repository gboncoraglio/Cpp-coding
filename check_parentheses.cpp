bool isValid(string s) {
        stack<char> mystack; 
        for (int i = 0; i < s.length(); i++){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
                mystack.push(s[i]);
            }
            else {
                if (mystack.empty()) return false;
                
                
                char curr= mystack.top();
                mystack.pop();
                cout << curr << s[i];
                if (curr == '(' and s[i] != ')' ) return false;
                if (curr == '[' and s[i] != ']' ) return false;
                if (curr == '{' and s[i] != '}' ) return false;
            }
        }
        if (mystack.empty()) return true;
        return false;
    }
