class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int left=0,right=skill.size()-1;
        int temp=skill[left]+skill[right];
        long long ans=0;
        while(left<=right)
        {
            int sum=skill[left]+skill[right];
            if(temp!=sum)
            {
                return -1;
            }
            temp=sum;
            ans+=(skill[left]*skill[right]);
            left++;
            right--;
        }
        return ans;
    }
};