class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<mapping.size();i++)
        {
            mp[i]=mapping[i];
        }
        vector<int>arr=nums;
        for(int i=0;i<arr.size();i++)
        {
            int temp=arr[i];
            string str="";
            if(temp==0) str=to_string(mp[0]);
            while(temp)
            {
                int rem=temp%10;
                str=to_string(mp[rem])+str;
                temp/=10;
            }
            arr[i]=stoi(str);
            cout<<arr[i]<<endl;
        }
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=arr[i];
        }
        unordered_map<int,int>index;
        for(int i=0;i<nums.size();i++)
        {
            index[nums[i]]=i;
        }
        auto lambda=[&map,&index](int &a,int &b)
        {
            if(map[a]==map[b])
            {
                index[a]<index[b];
            }
            return map[a]<map[b];
        };
        sort(nums.begin(),nums.end(),lambda);
        return nums;
    }
};