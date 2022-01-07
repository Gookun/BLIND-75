/*2 passes - first multiply by all elements in the right, 
then go from the end and multiply by all elements in the left:
Prefix and postfix
TC= O(n)
SC = O(1)*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefix=1,postfix=1;
        vector<int> res(n);
        
        // Put in each index in res the product of all elements before it:
        for (int i=0; i<n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        
        // Now multiply each one with all the elements after it:
        postfix = 1;
        for (int i=n-1; i>=0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        
        return res;
    }
};

/*This solution leads to a better one -
1-pass: do it simultaneously*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size()-1, prefix = 1, postfix = 1;
        vector<int> res(n+1, 1);

        for (int i=0; i<=n; i++) {
            res[i] *= prefix;
            res[n-i] *= postfix;
            prefix *= nums[i];
            postfix *= nums[n-i];
        }
        
        return res;
    }
};