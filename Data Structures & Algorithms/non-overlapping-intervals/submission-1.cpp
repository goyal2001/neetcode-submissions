class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        if(intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end(),[](vector<int> &i,vector<int> &j){
            if(i[0]==j[0]){
                return i[1]<j[1];
            }
            return i[0]<j[0];
        });
        int end = intervals[0][1];
       for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<end){
            ans++;
            end = min(end,intervals[i][1]);
        }
        else if(intervals[i][0]>=end)
            end = intervals[i][1];
        
       }
       return ans;
    }
};
