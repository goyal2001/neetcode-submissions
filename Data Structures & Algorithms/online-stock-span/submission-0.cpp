class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count;
    StockSpanner() {
        count=1;
    }
    
    int next(int price) {
        if(st.empty() || (!st.empty()&& st.top().first>price)){
            st.push({price,count});
            count++;
            return 1;
        }else if(!st.empty() && st.top().first<=price){
            while(!st.empty() && st.top().first<=price) st.pop();

            int top;
            if(!st.empty()) top = st.top().second;
            else top=0;
            st.push({price,count});
            top=count - top;
            count++;
            return top;
        }

        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */