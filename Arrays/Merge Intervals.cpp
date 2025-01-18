class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        
        for(int i=1;i<n;i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            int lx=v[v.size()-1][0];
            int ly=v[v.size()-1][1];
            if(x<=ly){
                v.pop_back();
                v.push_back({lx,max(y,ly)});
            }
            else{
                v.push_back({x,y});
            }
        }
        return v;
    }
};
