class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1)
            return 0;
        vector<bool> mark(n, true);
        mark[0] = false;
        mark[1] = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if(mark[i]==true)  //IMP
            {
                int j = i * i;
                while (j < n) {
                    mark[j] = false;
                    j = j + i;
                }
            }
            
        }
        int primeCount = 0;
        for (int i = 0; i < n; i++) {

            if (mark[i] == true) {
                primeCount++;
                // cout<<i<<endl;
            }
        }
        return primeCount;
    }
};