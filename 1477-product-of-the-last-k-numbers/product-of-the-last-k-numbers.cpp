class ProductOfNumbers {
public:
     std::vector<int> prefixProducts;
public:
    ProductOfNumbers() {
        prefixProducts = {1}; 
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset on zero
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProducts.size()) return 0; // If k exceeds available range, there was a zero
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */