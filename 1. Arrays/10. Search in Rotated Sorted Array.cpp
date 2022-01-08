//TC= O(LogN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m=0;
        
        while(l<=r)
        {
            m=(l+r)/2;
            if(target == nums[m])
                return m;
            
            //left sorted portion
            if(nums[l]<=nums[m])
            {
                //target lies is left half or not
                if( target > nums[m] || target<nums[l])
                    l=m+1;
                else
                    r=m-1;
            }

            //right sorted portion
            else
            {
                if(target<nums[m] || target>nums[r])
                    r=m-1;
                else
                    l=m+1;
                
            }

        }
        return -1;
    }
};