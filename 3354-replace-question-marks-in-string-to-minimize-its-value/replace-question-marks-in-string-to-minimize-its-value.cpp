// "abcdefghijklmnopqrstuvwxy??"   => answer is =abcdefghijklmnopqrstuvwxyaz(lexcographiclly sorted)
//"abcdefghijklmnopqrstuvwxy??cb??" =>"abcdefghijklmnopqrstuvwxy za cb de" =>sorted " abcdefghijklmnopqrstuvwxy ad cb ez" 
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int>hs(26,0);  //count the frequency
        vector<char>as;  //store character inplace of '?'
        for(auto x:s){
            if(x!='?')hs[x-'a']++;
        }

        for(int x=0;x<s.length();x++){
            if(s[x]=='?'){
                int mn=hs[0];
                int i=0;
                for(int x=0;x<26;x++){  //get the minimum frequency element from hash table
                    if(hs[x]<mn){mn=hs[x];i=x;}
                }
                as.push_back('a'+i);   //insert in the 'as' array
                // s[x]='a'+i;
                hs[i]++;
            }
        }
        int i=0;
        sort(as.begin(),as.end());  //sort for lexicographically 
        for(int x=0;x<s.length();x++){  //inplace of '?' put character from 'as'
            if(s[x]=='?')s[x]=as[i++];
        }
        return s;
    }
};