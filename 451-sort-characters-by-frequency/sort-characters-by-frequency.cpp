//Without using map 
typedef pair<char,int>P;
class Solution {
public:

    string frequencySort(string s) {
        //only a-z,A-Z  ,so we make array of 123 size bcz
        // z ASCII value is 122
        vector<P>vec(123);

        for(char &ch:s)
        {
            int freq=vec[ch].second;
            vec[ch]={ch,freq+1};
        }

        //comparator fucntion
        auto lambda=[&](P &p1, P &p2)
        {
            return p1.second>p2.second;
        };   //IMP NOTICE PART

        sort(vec.begin(),vec.end(),lambda);

        string result="";
        for(int i=0;i<=122;i++)
        {
            if(vec[i].second>0)
            {
                char ch=vec[i].first;
                int freq=vec[i].second;
                string temp=string(freq,ch);   //IMP

                result+=temp;
            }
        }
        return result;
    }
};
// T.C:-O(NlogN)
// S.C:-O(2N)
// class Solution {
// public:
// static bool comparator(pair<int,int> &a  , pair<int,int> & b){
//       return a.first > b.first ;
//     }
//     string frequencySort(string s) {
//         vector<pair<int,int>>vec;
//         unordered_map<char,int>mp;
//         for(auto &ch:s)
//         {
//             mp[ch]++;
//         }
//         //store frequency in vector
//         for(auto &it:mp)
//         {
//             char ch=it.first;
//             int freq=it.second;
//             vec.push_back({freq,ch});
//         }
//         sort(vec.begin(),vec.end(),comparator);  //sort the vector in descending order
//         string ans="";
// // for(auto &it:vec)
// // {
// //     cout<<it.first<<" "<<(char)it.second<<endl;
// // }
//         for(auto &it:vec)
//         {
//             while(it.first)
//             {
//                 ans+=it.second;
//                 it.first--;
//             }
            
//         }
//         return ans;
//     }
// };