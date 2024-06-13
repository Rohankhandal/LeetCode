class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        
        // If k is larger than or equal to n, the maximum element will be the winner
        if (k >= n) {
            int maxSkill = *max_element(skills.begin(), skills.end());
            return find(skills.begin(), skills.end(), maxSkill) - skills.begin();
        }

        queue<int> q;
        unordered_map<int, int> skillIndex;

        for (int i = 0; i < n; ++i) {
            q.push(skills[i]);
            skillIndex[skills[i]] = i;
        }

        int winCount = 0;
        int currentWinner = q.front(); q.pop();

        while (winCount < k && !q.empty()) {
            int challenger = q.front(); q.pop();
            if (currentWinner > challenger) {
                ++winCount;
                q.push(challenger);
            } else {
                winCount = 1;
                q.push(currentWinner);
                currentWinner = challenger;
            }
        }

        return skillIndex[currentWinner];
    }
};