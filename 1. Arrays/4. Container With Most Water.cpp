class Solution {
public:
    int maxArea(vector<int>& height) {
        long long res = 0;
        long long area=0;
        int l=0, r=height.size()-1;

        while(l<r)
        {
            
            area = (r-l) * min(height[l],height[r]);
            res = (int)max(res,area);

            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};