class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0;
        int right = 0;
        int maxFruits = 0;

        for (right = 0; right < fruits.size(); right++) {
            // Add current to basket
            basket[fruits[right]] ++;

            // If basket has more than 2 types of fruits,
            // start emptying the basket
            while (basket.size() > 2) {
                int fruitCount = basket[fruits[left]];
                if (fruitCount == 1)
                    basket.erase(fruits[left]);
                else
                    basket[fruits[left]] = fruitCount - 1;
                left++;
            }

            maxFruits =max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};