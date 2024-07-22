/*
Learning: Convert char to string. String in c++ has constructor - 1 argument takes length of string and 2 argument is the char. char will filled eq number of length
string s(1,'a');
cout<<s;
o/p: a

string s(3,'a');
cout<<s;
o/p: aaa
*/

// Input: ab*c+ 
// Output: ((a*b)+c)

string postToInfix(string exp) {
    // As it is postfix no need for priority
    stack<string> st;
    for(char c:exp){
        if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
          // Tell interviewer that t2 + t1 take O(t2.len + t1.len) time. string addition takes time in some languages
            st.push('(' + t2 + c + t1 + ')');
        } else {
            string s(1,c);
            st.push(s);
        }
    }
    return st.top();
}

/*
Basic logic is whenever encounter with operator --> Pop out top two elements from stack put the operater b/w these and wrap them around ().
*/
