/* Approach : Greedy
1. First simulate until all array elements are traversed once.
2. If no one win k rounds, then ans will be max element index.
Because then max element will come at beginning of queue and it will
keep winning matches until required k is reached.

Since we only need to traverse elements once, we can simulate without actual queue.
Time : O(n)
Space : O(1)
*/

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int currWinCount = 0;
        int winner = skills[0];
        int winnerIndex = 0;
        for (int i=1; i<skills.size(); i++) {
            if(skills[i] > winner) {    // new winner
                winner = skills[i];
                winnerIndex = i;
                currWinCount = 1;
            } else {            // same winner
                currWinCount++;
            }
            if(currWinCount >= k)   // k consecutive wins
                return winnerIndex;
        } 
        return winnerIndex;     // max element index
    }
};
// class Solution {
// public:
//     int findWinningPlayer(vector<int>& skills, int k) {
//         int n = skills.size();
        
//         // If k is larger than or equal to n, the maximum element will be the winner
//         if (k >= n) {  //Very iMP
//             int maxSkill = *max_element(skills.begin(), skills.end());
//             return find(skills.begin(), skills.end(), maxSkill) - skills.begin();
//         }

//         queue<int> q;
//         unordered_map<int, int> skillIndex;

//         for (int i = 0; i < n; ++i) {
//             q.push(skills[i]);
//             skillIndex[skills[i]] = i;
//         }

//         int winCount = 0;
//         int currentWinner = q.front(); q.pop();

//         while (winCount < k && !q.empty()) {
//             int challenger = q.front(); q.pop();
//             if (currentWinner > challenger) {
//                 ++winCount;
//                 q.push(challenger);
//             } else {
//                 winCount = 1;
//                 q.push(currentWinner);
//                 currentWinner = challenger;
//             }
//         }

//         return skillIndex[currentWinner];
//     }
// };