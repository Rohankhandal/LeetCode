// https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Custom%20Sort%20String.cpp

// INTUITION : 
// 	The question is actually testing if we know about comparators in sorting.
// 	It just wants us to sort the string "str" but the ordering of characters must be in order
// 	of their indices they occur in string "order"
	
// 	It's similar to what I have shown below example :
// 	Example : 
// 	order = "cba"
// 	str      = "abcd"
	
// 	Assign numbers to characters of "order"
// 	c -> 0
// 	b -> 1
// 	a  -> 2
	
// 	Now, put those numbers in characters in "str"
// 	We get,
// 	a   b   c    d
// 	2   1   0   INF   (If a char is not present in "order" assign it the largest value)
	
// 	Now , we are sorting {2, 1, 0, INF} in ascending order
// 	{0, 1, 2, INF}
// 	correspnding characters are :
// 	{c, b, a, d}
	
// 	This is just the intuition about the approach.
// 	The actualy solution is just imply applying the comparator and it will be done.


//Approach-1 (Just making use of frequency of each char) : 
//T.C : O(str.length())
//S.C : O(26) ~ O(1)
// class Solution {
// public:
//     string customSortString(string order, string str) {
//         int count[26] = {0};
        
//         for(char &x : str)
//             count[x-'a']++;
        
//         string result = "";
//         for(char &ch : order) {
//             while(count[ch-'a']--) {
//                 result.push_back(ch);
//             }
//         }
        
//         //Add the characters which are not present in 'order'
//         for(char &ch : str) {
//             if(count[ch-'a'] > 0) {
//                 result.push_back(ch);
//             }
//         }
        
//         return result;
//     }
// };

//Approach-2 (Using comparator)
//T.C : O(nlogn)
//S.C : O(26) ~ O(1)
// class Solution {
// public:
//     string customSortString(string order, string str) {
//         vector<int> index(26, -1);
        
//         for(int i = 0; i<order.length(); i++)
//             index[order[i]-'a'] = i;
        
        
//         auto lambda = [&index](char &ch1, char &ch2) {  //lambda comparator
//             return index[ch1-'a'] < index[ch2-'a'];
//         };
        
//         sort(begin(str), end(str), lambda);
//         return str;
        
//     }
// };

/*What was actually asked in Facebook :
FOLLOW UP NOTE : The original questions that was asked by Facebook was similar to
this but there was one small variation that "The characters which don't
occur in "str" must be sorted as per English Alphabet order".  In that case
one slight change will do the job in comparator function below :
*/
// class Solution {
// public:
//     string customSortString(string order, string str) {
//         vector<int> index(26, INT_MAX);
        
//         for(int i = 0; i<order.length(); i++)
//             index[order[i]-'a'] = i;
        
        
//         auto lambda = [&](char &ch1, char &ch2) {
//             if(index[ch1-'a'] == index[ch2-'a'])
//                 return ch1 < ch2;
            
//             return index[ch1-'a'] < index[ch2-'a'];
//         };
        
//         sort(begin(str), end(str), lambda);
//         return str;
        
//     }
// };



class Solution {
public:
    static string str;
    static bool mycomp(char a, char b) { return (str.find(a) < str.find(b)); }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), mycomp);
        return s;
    }
};

string Solution::str;