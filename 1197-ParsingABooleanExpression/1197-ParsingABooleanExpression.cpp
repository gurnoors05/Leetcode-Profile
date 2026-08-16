// Last updated: 8/16/2026, 7:04:38 PM
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i=0;i<expression.size();i++){
                if(expression[i]==','){
                    continue;
                }
                if(expression[i]==')'){
                    vector<char> vec;
                    while(st.top()!='('){
                        char ch=st.top();
                        vec.push_back(ch);
                        st.pop();
                    }
                    st.pop();
                    char op=st.top();
                    st.pop();
                    char ans=solve(vec,op);
                    st.push(ans);
                }
                else{
                    st.push(expression[i]);
                }

        }
        return st.top()=='f'?false:true;
       
    }
     char solve(vector<char> &vec,char op){
            if(op=='!'){
                return vec[0]=='t'? 'f': 't';
            }
            if(op=='&'){
                for(char ch:vec){
                    if(ch=='f'){
                        return 'f';
                    }
                }
                    return 't';
            }
            if(op=='|'){
                for(char ch:vec){
                    if(ch=='t'){
                        return 't';
                    }
                }
                    return 'f';
            }
            return 't';
        }
};