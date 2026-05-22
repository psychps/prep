class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        for (char c : s){
            if(c =='(' || c =='{' || c =='['){
                st.push(c);
            }
            else if(!st.empty() && st.top()==m[c]){
                st.pop();
            }
            else return false;

        }
        if (st.empty()){
            return true;
        }
        else return false;
    }
};