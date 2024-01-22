class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int i = 0;
        string str = s2.substr(i,m); // creating substring of the length of s1
        // This initialization is needed to enter into the loop
        sort(s1.begin(),s1.end()); //sort s1
        while(str.length()==m) // break the loop when there are not 
        // enough elements in the substring of the length of our 
        // given s1 string
        {
            str = s2.substr(i,m); //starting from initial substring of length s2
            sort(str.begin(),str.end()); //sorting that substring
            if(str==s1) // comparing if they are equal or not
            {
                return true; // if equal, then return true
            }
            i++; // otherwise go to the next index and again create a
            // substring of the length of s1 and comapre
        }
        return false;
    }
};