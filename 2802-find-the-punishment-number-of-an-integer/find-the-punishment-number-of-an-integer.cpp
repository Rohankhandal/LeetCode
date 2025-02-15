class Solution {
public:
    bool isValidPartition(string &str,int target,int currSum,int idx)
    {
        int n=str.size();
        if(idx>=n)
        {
            return currSum==target;
        }
        int val=0;

        for(int i=idx;i<n;i++)
        {
            val=val*10+(str[i]-'0');
            // if(val>target) return false;
            if(isValidPartition(str,target,currSum+val,i+1)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
         int totalSum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (isValidPartition(squareStr, i,0,0)) {
                totalSum += square;
            }
        }
        return totalSum;
    }
};