class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long val = 0;
        int bit = 0;

      
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; 
            } else {
                if (bit < 32 && (val + (1LL << bit)) <= k) {
                    val += (1LL << bit);
                    count++;
                }
            }class Solution {
public:
    int longestSubsequence(string s, int k) {
      long long n=s.size(),len=0,x=0;
      bool safe=true;
      for(int i=n-1;i>=0;i--){
        if(s[i]=='1' && safe==true){
          cout<<len<<" ";
          long long num=(1LL<<len);
          
           if (x + num <= k) {
            x += num;
            len++;
            } else {       
             safe = false;
            }
        
        }
        else if(s[i]=='0'){
          len++;
        }
   
      }
      return len;
    }
};
            bit++;
        }

        return count;
    }
};
