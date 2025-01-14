class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            int start = 0,flag= 1, k;
            for (int j = 0; j < words[i].size(); ++j)
            {
                k= s.find(words[i][j],start);
                if (k == -1) 
                {
                    flag = 0;
                    break;
                }
                start = k+1;
            }
            count += flag;
        }
        return count;
    }
};