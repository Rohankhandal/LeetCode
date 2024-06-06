class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        int n = hand.size();
        if (n % groupSize != 0) return false; // If total cards are not a multiple of groupSize, return false
        
        // Count the frequency of each card
        for (auto &card : hand) {
            mp[card]++;
        }
        
        // Try to create consecutive groups
        while (!mp.empty()) {
            int first = mp.begin()->first; // Get the smallest card value
            
            // Try to create a group starting with the smallest card
            for (int i = 0; i < groupSize; i++) {
                int currentCard = first + i;
                if (mp[currentCard] > 0) {
                    mp[currentCard]--;
                    if (mp[currentCard] == 0) {
                        mp.erase(currentCard); // Remove the card from map if its count becomes zero
                    }
                } else {
                    return false; // If we can't find the consecutive card needed, return false
                }
            }
        }
        
        return true; // If we successfully create all groups, return true
        

    }
};