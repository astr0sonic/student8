#include "bracket.h"

bool checkBrackets(const std::string& s) {
    std::stack<char> st;
 
    char  m[128];
          m[')'] = '(';
          m[']'] = '[';
          m['}'] = '{';
          m['>'] = '<';
 
    for(const auto c : s)
    {   
        if (c=='(' || c=='[' || c=='{' || c=='<')
            st.push(c);
        else 
            if(c==')' || c==']' || c=='}' || c=='>')
            {
                if(st.empty() || st.top() != m[c])
                    return false;
                st.pop();
            }
    }
    return st.empty();
}
