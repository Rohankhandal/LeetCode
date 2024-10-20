class Solution {
public:
    char parseOR(vector<char>&temp)
    {
        int n=temp.size();
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='t')
            {
                return 't';
            }
        }
        return 'f';
    }

     char parseAND(vector<char>&temp)
    {
        int n=temp.size();
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='f')
            {
                return 'f';
            }
        }
        return 't';
    }
     char parseNOT(vector<char>&temp)
    {
        int n=temp.size();
        if(temp[0]=='t') return 'f';
        else return 't';
    }
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char>st;

        for(int i=0;i<n;i++)
        {
            if(expression[i]==')'){
                vector<char>temp;
                while(!st.empty())
                {
                    char ch=st.top(); st.pop();
                    if(ch=='(') break;
                    else temp.push_back(ch);
                }

                //check which operation we have to apply
                char ch=st.top(); st.pop();
                if(ch=='|')
                {
                    char res=parseOR(temp);
                    st.push(res);
                }
                else if(ch=='&')
                {
                     char res=parseAND(temp);
                    st.push(res);
                }
                else if(ch=='!')
                {
                   char res=parseNOT(temp);
                    st.push(res); 
                }
            }
            else st.push(expression[i]);
        }
        char ch=st.top();
        cout<<ch<<endl;
        return (ch=='t')?true:false;
    }
};