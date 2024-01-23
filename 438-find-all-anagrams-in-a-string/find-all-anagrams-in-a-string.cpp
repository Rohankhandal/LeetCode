// using sliding window
class Solution {
public:
bool allZero(vector<int>counter)
{
    for(auto &it:counter)
    {
        if(it!=0)
        {
            return false;
        }
       
    }
     return true;
}
    vector<int> findAnagrams(string s, string p) {
        vector<int>counter(26,0); //bcz all character are small character
	    //count frequency of string pat
	    for(int i=0;i<p.size();i++)
	    {
	        counter[p[i]-'a']++;
	    }
        vector<int>ans;
	    int i=0;
	    int j=0;
	    int k=p.size();   //size of pat string
	    while(j<s.size())
	    {
	        counter[s[j]-'a']--;
	        if(j-i+1==k)
	        {
	            if(allZero(counter))   //if map is emtpy then increment the count 
	            {
	                ans.push_back(i);
	                
	            }
	            counter[s[i]-'a']++;   //increase the frequency of the char , which is out of the 
	           // window 
	            i++;
	        }
	        j++;
	        
	    }
	    return ans;
    }
};


//TLE 
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int i=0;
//         int len1=s.size();
//         int len2=p.size();
//         vector<int>ans;
//         //sort the string p 
//         sort(p.begin(),p.end());
//         while(i<len1)
//         {
//             string temp=s.substr(i,len2);
//             //sort the string temp
//             sort(temp.begin(),temp.end());
//             if(temp==p)
//             {
//                 ans.push_back(i);
//             }
//             i++;
//         }
//         return ans;
//     }
// };