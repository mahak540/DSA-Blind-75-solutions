 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        for(const auto& inter : intervals)
    {
        if(res.empty() || res.back()[1]<inter[0])
        res.push_back(inter);
        else
        res.back()[1]=max(res.back()[1],inter[1]);

    }
    return res;
    }
