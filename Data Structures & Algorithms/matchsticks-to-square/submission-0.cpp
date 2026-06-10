class Solution {
public:
    bool solve(int i,vector<int>& matchsticks,int a,int b,int c,int d){
        if(i==matchsticks.size()){
            if(a==0 && b==0 && c==0 && d==0) return true;
            else return false;}

        if(matchsticks[i]<=a){
            a-=matchsticks[i];
            if(solve(i+1,matchsticks,a,b,c,d)) return true;
            a+=matchsticks[i];   
        }
        if(matchsticks[i]<=b){
            b-=matchsticks[i];
            if(solve(i+1,matchsticks,a,b,c,d)) return true;
            b+=matchsticks[i];                           
        }
        
        if(matchsticks[i]<=c){
            c-=matchsticks[i];
            if(solve(i+1,matchsticks,a,b,c,d)) return true;
            c+=matchsticks[i];         
        }
        
        if(matchsticks[i]<=d){
            d-=matchsticks[i];
            if(solve(i+1,matchsticks,a,b,c,d)) return true;
            d+=matchsticks[i];        
        }

        return false;   
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;

        int sum=0;
        for(int i:matchsticks) sum+=i;

        if(sum%4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        return solve(0,matchsticks,sum/4,sum/4,sum/4,sum/4);
    }
};