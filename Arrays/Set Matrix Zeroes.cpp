class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> x;
        set<int> y;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for(auto k=x.begin();k!=x.end();k++){
            for(int j=0;j<m;j++){
               matrix[*k][j]=0;
            }
        }
        for(auto k=y.begin();k!=y.end();k++){
            for(int j=0;j<n;j++){
               matrix[j][*k]=0;
            }
        }
        return;
              
    }
};

//In place soln
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int c0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(j==0){
                       c0=0;
                    }
                    else{
                        matrix[0][j]=0;
                    }
                    
                     matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(c0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
};


