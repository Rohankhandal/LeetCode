typedef long long ll;
class Solution { 
public: 
    // static bool cmp(const pair<int, int>& a, const pair<int, int>& b) { 
    //         return a.first < b.first || (a.first == b.first && a.second < b.second); 
    //     }; 
    
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) { 
        ll sum=0,n=nums.size();
        vector<ll>ans;
        set<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.insert({nums[i],i});   //OR use set<pair<int,int>>s so that no need to sort
            sum+=nums[i];          //calcualte the sum of nums , for not sum again 
            //and again the unmarked nums element(and reduce time compxity) 
        }

        // sort(v.begin(),v.end(),cmp);  


        for(auto q:queries)
        {
            int id=q[0], ki=q[1];

            sum-=nums[id];   //reduce the sum whose index is id;
            nums[id]=0;   //mark the element by 0(bcz 0 is not present in the nums) , 
            //so that no need to use another space 

            while(v.size() && ki)
            {
                auto it = v.begin();
                auto [el, i] = *it;

                v.erase(it); // erase using iterator
                if(nums[i])          //if nums[i] is unmarked 
                {
                    sum-=nums[i];
                    nums[i]=0  ;   //marked the element 
                    ki--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
 
    } 
}; 





// long method

// class Solution { 
// public: 
//     static bool cmp(const pair<int, int>& a, const pair<int, int>& b) { 
//             return a.first < b.first || (a.first == b.first && a.second < b.second); 
//         }; 
    
//     vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) { 
//         long long totalSum = 0; 
//         for (int num : nums) { 
//             totalSum += num; 
//         } 
 
//         unordered_set<int> marked; 
//         vector<long long> answer; 
//         vector<pair<int, int>> numSort;   //value,index
//         for (int i = 0; i < nums.size(); ++i) { 
//             numSort.push_back({nums[i], i}); 
//         } 
 
//         sort(numSort.begin(), numSort.end(),cmp);
 
//         int nextUnmarked = 0; 
 
//         for (auto&it : queries) { 
//             int index = it[0]; 
//             int k = it[1]; 
 
            
//             if (marked.find(index) == marked.end()) { 
//                 marked.insert(index); 
//                 totalSum -= nums[index]; 
//             } 
 
//             while (k > 0 && nextUnmarked < nums.size()) { 
//                 while (nextUnmarked < nums.size() && marked.find(numSort[nextUnmarked].second) != marked.end()) { 
//                     nextUnmarked++; 
//                 } 
 
//                 if (nextUnmarked < nums.size()) { 
//                     marked.insert(numSort[nextUnmarked].second); 
//                     totalSum -= numSort[nextUnmarked].first; 
//                     nextUnmarked++; 
//                     k--; 
//                 } 
//             } 
 
//             answer.push_back(totalSum); 
//     } 
 
//     return answer; 
 
//     } 
// }; 