//T.C = O(N) & S.C =O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto x: intervals){
        	/*if new interval's end value is smaller 
        	than the start value of the current
        	interval*/
            if(newInterval[1]<x[0]){
                ans.push_back(newInterval);
                newInterval = x;
                //take the new interval and insert it into the result
            }
            /*if the start value of the new interval 
            is greater than the end value of current
            interval*/
            else if(newInterval[0]>x[1]){
                ans.push_back(x);
            }
            //in case of overlapping
            else{
                newInterval[0] = min(x[0],newInterval[0]);
                newInterval[1] = max(x[1],newInterval[1]);
            }            
        }
        ans.push_back(newInterval);
        return ans;
    }
};