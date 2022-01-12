Bruteforce
Time Complexity: O (n^3)
Space Complexity: O (1)

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength=1, start=0;
        for (int i=0; i<s.size(); i++) {
            for (int j=i+1; j<s.size(); j++) {
                int flag=1; //true
                
                for (int k=0; k<(j-i+1)/2; k++) {
                    if (s[i+k]!=s[j-k]) flag=0;
                }
                if (flag==1 && j-i+1>maxLength)
                    maxLength=j-i+1, start=i;
            }
        }
        string res;
        for (int i=start; i<maxLength+start; i++)
            res+=s[i];
        return res;
    }
};
DP
Time Complexity: O (n^2)
Space Complexity: O (n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength=1, start=0;
        vector <vector<bool>> dp(s.size(), vector <bool> (s.size(), 0));

        for (int i=0; i<s.size()-1; i++) dp[i][i]=1;
        for (int i=s.size()-1; i>=0; i--) {
            for (int j=i+1; j<s.size(); j++) {
                if (s[i]==s[j]) {
                    if (j-i==1 || dp[i+1][j-1]) dp[i][j]=true;
                }
           
                if (dp[i][j]==1 && maxLength < j-i+1) {
                    maxLength=j-i+1;
                    start=i;
                }
            }
        }
        string res;
        for (int i=start; i<maxLength+start; i++)
            res+=s[i];
        return res;
    }
};
Expand Around Centre
Time Complexity: O (n^2)
Space Complexity: O (n)

class Solution {
public:
    int expand(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.length()==1)
            return s;
        int len=s.length();
        int start=0,end=0;
        
        for(int i=0;i<len;i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start){
                start = i - (len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start,(end-start)+1);
    }
};