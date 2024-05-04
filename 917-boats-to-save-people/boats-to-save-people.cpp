class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boat=0;
        int currSum=0;
        int l=0,r=people.size()-1;
        while(l<r)
        {
            currSum=people[l]+people[r];
            if(currSum<=limit)
            {
                boat++;
                l++;
                r--;
            }
            else
            {
                boat++;  //rightmost people go alone
                r--;
            }
        }
        if(l==r) boat++; //middle person go alone
        return boat;
    }
};