class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> lToR(n, 0); // force from right
        vector<int> rToL(n, 0); // force from left
        
        // Left to right forces (R)
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == 'R') {
                force = n; // maximum force
            } else if (d[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            lToR[i] = force;
        }

        // Right to left forces (L)
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L') {
                force = n;
            } else if (d[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            rToL[i] = force;
        }

        // Determine final state
        string res(n, '.');
        for (int i = 0; i < n; i++) {
            if (lToR[i] == rToL[i]) {
                res[i] = '.'; // equal force cancels out
            } else if (lToR[i] > rToL[i]) {
                res[i] = 'R';
            } else {
                res[i] = 'L';
            }
        }

        return res;
    }
};
