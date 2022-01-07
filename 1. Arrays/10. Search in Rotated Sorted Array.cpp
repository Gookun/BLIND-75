//TC= O(LogN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target)
                return mid;
            
            //check whether left half is sorted
            if(nums[low]<=nums[mid])
            {
                //target lies is left half or not
            if(nums[low]<=target &&nums[mid]>=target)
            {
                high=mid-1;
                
            }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                //check target is in unsorted left half
                if(nums[low]<=target || nums[mid]>=target)
                {
                    high=mid-1;
                    
                }
                else
                {
                    low=mid+1;
                }
                
            }
        }
        return -1;
        }
};