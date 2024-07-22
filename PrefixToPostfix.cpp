string preToPost(string pre_exp) {
    stack<string> st;
    // start from right side in prefix
    for(int i=pre_exp.size()-1;i>=0;i--){
        char c = pre_exp[i];
        if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(t1 + t2 + c);
        } else {
            string s(1,c);
            st.push(s);
        }
    }
    return st.top();
}
