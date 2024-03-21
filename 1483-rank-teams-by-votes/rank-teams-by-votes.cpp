class Solution {
public:
    string rankTeams(vector<string>& votes) {
	int n = votes.size(), m = votes[0].size();
	vector<vector<int>> vec(m, vector<int>(26, 0));
	for (auto v : votes) {
		for (int i = 0; i < m; ++i) {
			vec[i][v[i] - 'A']++;
		}
	}
	string str = votes[0];
	sort(str.begin(), str.end(), [&](char a, char b){
		for (int i = 0; i < m; ++i) {
			if (vec[i][a - 'A'] == vec[i][b - 'A']) continue;
			else return vec[i][a - 'A'] > vec[i][b - 'A'];
		}
		return a < b;
	});
	return str;
}
};



// Space Complexity
// vector<vector<int>> vec: This creates a vector of vectors. The outer vector has m elements.
// vector<int>(26, 0): This creates an inner vector of integers with a size of 26, all initialized to 0.
// The space complexity of this line can be calculated as follows:

// The outer vector vec has m elements, each element being a vector of integers with a fixed size of 26.
// So, the space required for the outer vector vec is O(m * sizeof(vector<int>)).
// The inner vector has a fixed size of 26 integers, so its space complexity is O(26 * sizeof(int)).
// Assuming sizeof(vector<int>) and sizeof(int) are constant:

// The space complexity of the outer vector vec is O(m).
// The space complexity of the inner vector is O(1) because its size is constant.
// Thus, the overall space complexity of the given line is O(m).








// Approach
// Create an array which consists of the characters present in the votes array . Now we need to sort this array on the basis of votes given by all the members .

// Hence i will create a map of type char,int which will store the count of votes given to a character for a particular position

// For ex : mpp[{'a' , 2}] represents the count of vote given to character a for the second position

// This data will help us in lamba function to sort the array . We wiil first compare the two characters on the basis of votes at a particular position from 1 till votes[0].size() and thereafter on the basis of the alphabetical order of the characters

// Finally when the array is sorted successfully we will then append the characters of the array in a string (in same order) and return the answer

// Complexity
// Time complexity:
// O(NMlogn)

// where N is the number of unique characters in the votes array and M is number of people giving the votes

// Space complexity:
// O(N*M)

// where N is the number of unique characters in the votes array and M is number of people giving the votes
// class Solution {
// public:
//     string rankTeams(vector<string>& votes) {
         
//          set<char>st;
         
//          vector<char>arr;
         
//          map<pair<char,int>,int>mpp;
          
//          // storing the unique characters in the vector (arr) and  counting the votes for each character for a particular position         

//          for(int i = 0 ; i < votes.size() ; i++)
//          {   
//              int cnt = 1;

//              for( auto ele : votes[i])
//              {
//                  if(st.find(ele) == st.end())
//                  {
//                     arr.push_back(ele);
//                     st.insert(ele);
//                  }

//                  mpp[{ele,cnt}] += 1;

//                  cnt++;    
//              }
//          }

//          int size = votes[0].size();
         
//         // sort on the basis of the count of votes for a particular position and thereafter on the basis of alphabetical order
       
//          sort( arr.begin() , arr.end(),[&mpp,&size](char a , char b)
//          {
//              for( int i = 1 ; i <= size; i++)
//              {
//                  if(mpp[{a,i}] != mpp[{b,i}])
//                  {
//                      return mpp[{a,i}] > mpp[{b,i}];
//                  }
//              }

//              return a < b;
//          });

//         // Finally append the characters of the arr into a string and return answer 

//          string ans = "";

//          for( auto ele : arr)
//          {
//              ans += ele;
//          }

//          return ans;
//     }
// };