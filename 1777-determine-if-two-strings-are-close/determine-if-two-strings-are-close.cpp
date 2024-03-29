class Solution {
public:

    bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        if(m!=n)
        return false;

        vector<int>freq1(26);
        vector<int>freq2(26);
        for(int i=0;i<m;i++)
        {
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
//point1 :- jo char word1 me ha, wo char word2 me bhi  hona chaiya
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=0 && freq1[i]!=0) continue;

            if(freq1[i]==0 && freq2[i]==0) continue;

            return false;
        }
//point2:- match the freq
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return freq1==freq2;
    }
};