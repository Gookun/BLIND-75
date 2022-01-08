class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int curMin=1,curMax=1,temp=0;
        for(auto n:nums){
            temp = curMax *n;
            curMax = max({n*curMax, n*curMin,n});
            curMin = min({temp, n*curMin,n});
            res = max(res,curMax);
        }
        return res;
    }
};