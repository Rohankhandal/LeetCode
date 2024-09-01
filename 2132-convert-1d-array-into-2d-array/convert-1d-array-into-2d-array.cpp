class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        
        int size=original.size();
        if(m*n!=size) return {}; 
        
        int count=0;
        while(count<size)
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(original[count]);
                count++;        
            }
            ans.push_back(temp);
        }
       
        return ans;
    }
};