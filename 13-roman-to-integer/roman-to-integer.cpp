class Solution {
public:
//Numbers are always in none-increasing order in ROMAN
    int romanToInt(string s) {
        unordered_map<char,int>mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
            
        };
        int value=0;
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size() && mp[s[i]] < mp[s[i+1]])  //if decresing found then subtract 
            //simply add last value in answer;
            {
                value-=mp[s[i]];
            }
            else
            {
                value+=mp[s[i]];
            }
        }
        return value;
    }
};