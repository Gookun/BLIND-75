// TC = (NlogN)+(N)
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> output;
        
        if(intervals.size() == 0)
            return output; 
        
        sort(intervals.begin(),intervals.end());
        vector<int> lastEnd = intervals[0];
        
        for(auto it:intervals)
        {
            if(it[0] <= lastEnd[1])
              //start <= lastend
                lastEnd[1] = max(lastEnd[1],it[1]);
            else
            {
                output.push_back(lastEnd);
                lastEnd = it;
            }
        }
        
        output.push_back(lastend);
        return output;
    }
