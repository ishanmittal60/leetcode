class ProductOfNumbers {
public:
vector<int>prod;
        int ans=1;
    ProductOfNumbers() {
        prod.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            prod.clear();
            prod.push_back(1);
            ans = 1;
        }
        else {prod.push_back(ans*num);
        ans=ans*num;}
    }
    
    int getProduct(int k) {
        int n=prod.size();
        if(k >= n) return 0;
        return prod[n-1]/prod[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */