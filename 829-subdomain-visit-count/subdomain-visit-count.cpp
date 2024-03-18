class Solution {
public:
unordered_map<string,int>mp;
void store(string str){
    int space=str.find(" ");
    // cout<<space<<endl;
    int freq=stoi(str.substr(0,space));
    str=str.substr(space+1);
    // cout<<str;
    int index=0;
    while(str.find(".")!=string::npos)
    {
        index=str.find(".");
        mp[str]+=freq;
        str=str.substr(index+1);
    }
    mp[str]+=freq;  //store last substring after .(dot)

}
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        for(auto &it:cpdomains)
        {
            store(it);
            cout<<endl<<endl;
        }
        for(auto &it:mp)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            string temp=to_string(it.second)+" "+it.first;
    
            ans.push_back(temp);
        }
        return ans;
    }
}; 