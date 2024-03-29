class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double num=myPow(x,n/2);
        if(n%2==0){
            return num*num;
        }else{
            if(n>0){
                return num*num*x;
            }
        }
        return num*num/x;
    }
};