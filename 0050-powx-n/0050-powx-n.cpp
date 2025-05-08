class Solution {
public:
    double myPow(double x, long n) {

        if(n==0) return 1;
        if(n<0){
            return 1.0/pow(x,-n);
        }

        if(n%2!=0) return x*pow(x*x,(n-1)/2);
        return pow(x*x,n/2);
        
    }
};