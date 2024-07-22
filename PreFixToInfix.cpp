string preToInfix(string pre_exp) {
    // Write your code here
    // Just opp of postfix to infix
    stack<string> st;
    // Step1: start from right side instead of left
    for(int i=pre_exp.size()-1;i>=0;i--){
        char c = pre_exp[i];
        if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push('(' + t1 + c + t2 + ')');
        } else {
            string s(1,c);
            st.push(s);
        }
    }
    
    return st.top();
}
