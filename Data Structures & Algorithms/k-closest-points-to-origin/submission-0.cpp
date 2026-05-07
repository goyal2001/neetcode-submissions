class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<points.size();i++){
            int d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            v.push_back({d,i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans(k,vector<int>(2,0));
        for(int i=0;i<k;i++){
            int idx=v[i].second;
            ans[i][0]=points[idx][0];
            ans[i][1]=points[idx][1];
        }
        return ans;
    }
};
