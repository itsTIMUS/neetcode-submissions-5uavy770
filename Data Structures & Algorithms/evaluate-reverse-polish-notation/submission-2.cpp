class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int v2 = st.top(); st.pop();
                int v1 = st.top(); st.pop();
                
                if (s == "+") st.push(v1 + v2);
                else if (s == "-") st.push(v1 - v2);
                else if (s == "*") st.push(v1 * v2);
                else if (s == "/") st.push(v1 / v2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
