class StockSpanner {
public:
stack<pair<int,int>>s;
    StockSpanner() {
        
    }
  //price,span  
    int next(int price) {
int sp=1;
        while (!s.empty() && s.top().first <= price) {
    sp += s.top().second;
    s.pop();
}
s.push({price, sp});
        
            return sp;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */