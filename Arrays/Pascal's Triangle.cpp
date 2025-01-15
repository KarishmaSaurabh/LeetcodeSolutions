class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows==1){
            return {{1}};
        }
        v.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> k;
            k.push_back(1);
            for(int j=0;j<v[i-1].size()-1;j++){
              k.push_back(v[i-1][j]+v[i-1][j+1]);
            }
            k.push_back(1);
            v.push_back(k);
        }
        return v;
    }
};
