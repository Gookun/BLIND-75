//T.C = O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxf = 0;
        unordered_map<char,int>mp;
        int res = -1;
        while(r < n)
        {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            if((r-l+1) - maxf > k){
                mp[s[l]]--;
                l++;
            }
            res = max(res, (r-l+1));
            r++;   
        }
        return res;
    }
};