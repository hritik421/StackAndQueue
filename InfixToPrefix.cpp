/*
# 3 steps logic
1. Reverse the string & swap the parenthesis i.e., open to close and close to open
2. Iterate over reversed string and performed the logic to convert to postfix notation
3. Reverse of postfix notation will give the prefix notation.

Note: Instead of reversing in step1 we can iterate over string from righ to left.
*/

Pseudo code:

string infixToPrefix(string s){
  stack<char> st;
  string res = "";
  for(char c:s){
    if(c==')' || c=='^' || c=='*' || c=='/' || c=='+' || c=='-'){
      while(!st.empty() && !priorityGreater(c,st)){
        res=+st.top();
        st.pop();
      }
      st.push(c);
    } else if(c=='('){
      while(st.top() != ')'){
        res+=st.top();
        st.pop();
      }
      st.pop();
    } else res+= c;
  }
  return reverse(res);
}
