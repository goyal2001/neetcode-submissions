class Solution {
public:
   int mySqrt(int x) {
        int i=0;
        int j=x;
        int mid = 0;
        if(x<=1) return x;
        while(i<=j){
            int mid= i + (j-i)/2;
            if(mid==(x/mid)) return mid;
            else if(mid>(x/mid)) j=mid-1;
            else i = mid+1;
        }
        return i-1;
    }
};