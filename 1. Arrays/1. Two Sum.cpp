    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        /*use hash map to instantly check for difference value, 
        map will add index of last occurrence of a num, 
        don’t use same element twice;*/
        for (int i = 0; i < nums.size(); i++) {
            if (prevMap.find(target - nums[i]) != prevMap.end()) {
                return {prevMap[target - nums[i]], i};
            }
            prevMap[nums[i]] = i;
        }
        return {};
    }