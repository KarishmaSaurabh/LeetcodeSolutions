class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==INT_MIN){
            x=x*x;
            n=n/2;
        }
        if(n<0){
           x= 1/x;
           n=-n;
        }
        double t=myPow(x,n/2);
        if(n%2==0){
            return t*t;
        }
        else{
            return x*t*t;
        }
    }
};
