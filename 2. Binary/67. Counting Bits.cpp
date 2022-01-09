/* write out result for num=16 
  to figure out pattern; 
  res[i] = res[i - offset], 
  where offset is the 
  biggest power of 2 <= I; */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        int offset=1;
        for(int i=1; i<=n;i++)
        {
           if(offset*2==i)
               offset=i;
            dp[i]=1+dp[i-offset];
        }
        return dp;
    }
};
/*Number[i] -- Binary Value -- No of 1's
--------------------------------------
0            00000          0   
1            00010          1   1+dp[n-1]
2            00100          1   1+dp[n-12
3            00110          2   1+dp[n-2]
4            01000          1   1+dp[n-4]
5            01010          2   1+dp[n-4]
6            01100          2   1+dp[n-4]
7            01110          3   1+dp[n-4]
8            10000          1   1+dp[n-18]