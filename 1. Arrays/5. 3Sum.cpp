class Solution {
public:
                        /*sort input, 
                    for each first element, 
                    find next two where -a = b+c, 
                    if a=prevA, skip a, 
                    if b=prevB skip b to elim duplicates; 
                    to find b,c use two pointers, 
                    left/right on remaining list;*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < (int)nums.size()-1; i++) {
            
            if (i > 0 && nums[i] == nums[i-1])
                continue;
                
                int l = i+1, r = (int)(nums.size())-1;
                
                while (l < r) {
                    int threeSum = nums[i] + nums[l] +nums[r];
                    if(threeSum>0)
                        r -= 1;
                    else if(threeSum<0)
                        l += 1;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[l]); 
                        temp.push_back(nums[r]); 
                        res.push_back(temp);
                        l+=1; 
                        while(nums[l] == nums[l-1] && l<r)
                            l+=1;
                    }
            }
        }
        return res;
    }
};