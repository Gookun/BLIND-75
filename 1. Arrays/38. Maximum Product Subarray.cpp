//dp: compute max and max-abs-val for each prefix subarr
//T.C=O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int curMin=1,curMax=1,temp=0;
        for(auto n:nums){
            temp = curMax *n;
            curMax = max({n*curMax, n*curMin,n});
            curMin = min({temp, n*curMin,n});
            /*having n in max/min of (n*max, n*min, n) 
            helped us sailing across the edge case of 0.*/
            res = max(res,curMax);
        }
        return res;
    }
};