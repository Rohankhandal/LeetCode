class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        if(k>=n)
        {
            return 1;
        }
        for(int i=1;i<n;i++)  //number of operations
        {
            int d=k*i; //start index after remove k character from start
            bool flag=true;

            for(int j=d;j<n;j++)
            {
                if(word[j]!=word[j-d])
                {
                    flag=false;
                    break;
                }
                
            }
            if(flag){
                    return i;
                }
        }
        return n;
    }
};