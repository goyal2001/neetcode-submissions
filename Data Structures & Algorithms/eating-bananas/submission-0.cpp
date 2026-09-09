class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        
        //int j = *max_element(piles.begin(), piles.end());
        int j = -1;
        for(int k=0;k<piles.size();k++) j= max(j,piles[k]);
        
        //int j=piles[piles.size()-1];
        int mid=0;
        while(i<=j){
            mid=(i+j)/2;
            //cout<<mid<<endl;
            long long count=0;
         for(int k=0;k<piles.size();k++){
            if(mid!=0){
            count = count + piles[k]/mid;
            if(piles[k]%mid>0) count++;
            }
            //cout<<count;
         }
         if(count<=h)  j=mid-1;
         else i=mid+1;
        
        }
      return i;
    }
};
