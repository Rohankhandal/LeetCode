// using constraints
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>vec(2001,0);
        for(int &x:arr)
        {
            vec[x+1000]++;
        }

        sort(vec.begin(),vec.end());

        for(int i=0;i<2001;i++)
        {
            if(vec[i]!=0&&vec[i]==vec[i-1])
            return false;
        }
        return true;
    }
};


//using unordered_set
// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int,int>mp;
//         for(auto it:arr)
//         {
//              mp[it]++;
//         }
//        unordered_set<int>st;
//        for(auto &it:mp)
//        {
//            int freq=it.second;
//            if(st.find(freq)!=st.end())
//            {
//                return false;
//            }
//            st.insert(freq);
//        }
//        return true;
//     }
// };

// Method-1
// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int,int>mp;
//         for(auto it:arr)
//         {
//              mp[it]++;
//         }
//        set<int>st;
//        for(auto it:mp)
//        {
//            st.insert(it.second);
//        }
//        return st.size()==mp.size()?true:false;
//     }
// };