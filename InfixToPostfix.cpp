Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-


bool priorityGreater(char op, stack<char>& st){
    switch (op) {
        case '(':
            return true;
        case '^':
            return st.top()== '^' ? false : true;
        case '*':
        case '/':
            return st.top() == '(' ? true : st.top() == '^' ? false : true;
        default : 
            return st.top() == '(' ? true : false;
    }
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s) {
  // Your code here
  string res = "";
  stack<char> st;
  for(char c:s){
      if (c == '(' || c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
          // check for priority
          while(!st.empty() && !priorityGreater(c, st)) {
             res+= st.top();
             st.pop();
          }
           st.push(c);
      } else if(c==')'){
          while(st.top()!='('){
              res+= st.top();
              st.pop();
          }
          st.pop();
      }
      else res += c;
  }
  while(st.empty() == false) {
      res+= st.top();
      st.pop();
  }
  return res;
}
