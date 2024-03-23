// "abcdefghijklmnopqrstuvwxy??"   => answer is =abcdefghijklmnopqrstuvwxyaz(lexcographiclly sorted)
//"abcdefghijklmnopqrstuvwxy??cb??" =>"abcdefghijklmnopqrstuvwxy za cb de" =>sorted " abcdefghijklmnopqrstuvwxy ad cb ez" 

// Best approach
// class Solution {
// public:
//     string minimizeStringValue(string s) {
//         vector<int>hs(26,0);  //count the frequency
//         vector<char>as;  //store character inplace of '?'
//         for(auto x:s){
//             if(x!='?')hs[x-'a']++;
//         }

//         for(int x=0;x<s.length();x++){
//             if(s[x]=='?'){
//                 int mn=hs[0];
//                 int i=0;
//                 for(int x=0;x<26;x++){  //get the minimum frequency element from hash table
//                     if(hs[x]<mn){mn=hs[x];i=x;}
//                 }
//                 as.push_back('a'+i);   //insert in the 'as' array
//                 // s[x]='a'+i;
//                 hs[i]++;
//             }
//         }
//         int i=0;
//         sort(as.begin(),as.end());  //sort for lexicographically 
//         for(int x=0;x<s.length();x++){  //inplace of '?' put character from 'as'
//             if(s[x]=='?')s[x]=as[i++];
//         }
//         return s;
//     }
// };


class Solution {
public:
    string minimizeStringValue(string s) {
        string ans="";

        unordered_map<char,int>freq;  //it store 26 char so T.c:-O(1)
        multiset<pair<int,char>>ms;   //it store 26 char so T.c:-O(1)
         //sort insert in base of firstly int ,then base on char

        for(auto c:s)
        {
            freq[c]++;
        }

        for(char c='a'; c<='z';c++)
        {
            ms.insert({freq[c],c});
        }

        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='?')
            {
                pair<int,char>p=*ms.begin();
                ms.erase(p);

                freq[p.second]++;  //increase the frequency by 1
                ans.push_back(p.second);  //store in ans
                ms.insert({freq[p.second],p.second});  //insert it again
            }
            else{
                ans.push_back(c);
            }
        }
        string fans="",temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='?')
            {
                temp.push_back(ans[i]);
            }
        }

        //sort it
        sort(temp.begin(),temp.end());
        int k=0;  //for temp vector
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                fans.push_back(temp[k++]);
            }
            else
            {
                fans.push_back(ans[i]);
            }
        }
        return fans;

    }
};