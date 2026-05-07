class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int num:stones) pq.push(num);
        while(pq.size()>1){
            int top = pq.top(); pq.pop();
            int top2 = pq.top();

            if(top==top2) pq.pop();
            else { pq.pop(); pq.push(top-top2);}

        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};
