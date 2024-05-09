class Solution {
public:
     static bool comp(int &a,int &b)
    {
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>q;
        for(auto &it:happiness)
        {
            q.push(it);
        }
        long long ans=q.top();
        q.pop();
        for(int i=1;i<k;i++)
        {
            ans+=(q.top()-i)>0?(q.top()-i):0;
            q.pop();
        }
        return ans;
        
    }
};

//TLE

// class Solution {
// public:
//      static bool comp(int &a,int &b)
//     {
//         return a>b;
//     }
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         sort(happiness.begin(),happiness.end(),comp);
//         long long ans=0;
        
//         for(int i=0;i<k;i++)
//         {
//             ans+=happiness[0];
//             happiness.erase(happiness.begin(),happiness.begin()+1);
//             // for(auto &it:happiness)
//             // {
//             //     cout<<it<<" ";
//             // }
//             // cout<<"print the Values"<<endl;
//             for(auto &it:happiness)
//             {
//                 if(it>0)
//                     it--;
//             }
//             // cout<<endl;
            
//         }
       
//         return ans;
        
//     }
// };