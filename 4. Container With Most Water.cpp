class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_a = 0;
        int p1=0;
        int p2=height.size()-1;
        while(p1<p2){
                if(height[p1]<height[p2]){
                    max_a = max(max_a,height[p1]*(p2-p1));
                    p1+=1;
                }
                else{
                    max_a = max(max_a,height[p2]*(p2-p1));
                    p2-=1;
                }
            }
        return max_a;
    }
};