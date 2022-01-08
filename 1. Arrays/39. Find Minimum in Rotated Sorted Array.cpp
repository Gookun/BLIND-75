class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int l=0,r=nums.size()-1,m=0;
        
        if (!r) return nums[0];//if there is one element
        
        while(l<=r)
        {
            if(nums[l]<nums[r]){
                res = min(res,nums[l]);
                break;
            }
            m =(l+r)/2;
            res = min(res, nums[m]);
            if(nums[m] >= nums[l])
                l=m+1; //search right
            else
                r=m-1; //search left
        }
        return res;
    }
};