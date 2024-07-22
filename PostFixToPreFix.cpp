/*
Logic: Whenever encounter with operator (+,- etc)
let say top t2 element of stack are t1 and t2. pop these 2 element from stack.
push new element to stack  ---->  (operator + t2 + t1)
*/

string postToPre(string post_exp) {
    // Write your code here
    stack<string> st;
    for(char c:post_exp) {
       if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
        string t1 = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();
        st.push(c + t2 + t1);
       } else {
           string s(1, c);
           st.push(s);
       }
    }
    return st.top();
}
