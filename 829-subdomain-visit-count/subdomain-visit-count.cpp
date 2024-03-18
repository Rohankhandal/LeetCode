class Solution {
public:
    pair<int,string>convert(string s)
    {
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                return {num,s.substr(i+1)};
            }
            else
            {
                num*=10;
                num+=(int)(s[i]-'0');
            }
        }
        return {0,""};
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int>mp;
        for(auto i:cpdomains)
        {
            pair<int,string>val=convert(i);  //split the frequency and the string
            int n=val.second.size();
            for(int j=n-1;j>=0;j--)
            {
                if(val.second[j]=='.')
                {
                    string name=val.second.substr(j+1);
                    mp[name]+=val.first;
                }
            }
            mp[val.second]+=val.first;
        }
        vector<string>ans;
        for(auto &it:mp)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            string new_str=to_string(it.second)+" "+it.first;
    
            ans.push_back(new_str);
        }
        return ans;
    }
}; 


//MY SOlution:-

// class Solution {
// public:
// unordered_map<string,int>mp;
// void store(string str){
//     int space=str.find(" ");
//     // cout<<space<<endl;
//     int freq=stoi(str.substr(0,space));  //extract frequency from string 
//     str=str.substr(space+1);  //get substring after frquency
//     // cout<<str;
//     int index=0;
//     while(str.find(".")!=string::npos)
//     {
//         index=str.find(".");
//         mp[str]+=freq;   //now, store every sustring after .(dot) with frequency in map
//         str=str.substr(index+1);  //now again extract the substring after the .(dot)
//     }
//     mp[str]+=freq;  //store last substring after .(dot)

// }
//     vector<string> subdomainVisits(vector<string>& cpdomains) {
//         vector<string>ans;
//         for(auto &it:cpdomains)
//         {
//             store(it);
//             cout<<endl<<endl;
//         }
//         for(auto &it:mp)
//         {
//             // cout<<it.first<<" "<<it.second<<endl;
//             string temp=to_string(it.second)+" "+it.first;
    
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// }; 