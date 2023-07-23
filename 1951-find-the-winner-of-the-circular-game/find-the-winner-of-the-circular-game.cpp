class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1){
           return 1;
       }
       int x= (findTheWinner(n-1,k)+k)%n;
       if(x==0){
           return n;
       }
       return x;
    }
};