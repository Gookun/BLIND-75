class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN,sum = 0;
        for(auto it:nums)
        {
            sum += it;
            maxsum = max(sum,maxsum);
            if(sum<0) sum=0;
        }
        return maxsum;
    }
};