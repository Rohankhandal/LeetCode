class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<char> st;
        stack<int> m;
        for(int i = 0; i < s.size() ; i++){
            if(isdigit(s[i])){
                string t = "";
                t.push_back(s[i]);
                for(int j = i+1 ; j < s.size();j++){  //if there are mutiple number in a sequence like 100[a];
                    if(isdigit(s[j])){
                        t.push_back(s[j]);
                    }
                    else{
                        i = j - 1;
                        break;
                    }
                }
                int num = stoi(t);  //convert string int number
                m.push(num);
            }
            else if(s[i] == ']'){
                int rep = m.top();
                m.pop();
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end()); 

                string str = temp;
                for(int j = 1; j < rep; j++){
                    str += temp;
                }

                if(!st.empty()){
                    for(int k = 0; k < str.size(); k++){
                        st.push(str[k]);
                    }
                }
                else{
                    ans += str;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string te = "";
        while(!st.empty()){  //add remaining answer in te
            te += st.top();
            st.pop();
        }
        reverse(te.begin(),te.end());  

        ans += te;  //actual answer
        return ans;
    }
};