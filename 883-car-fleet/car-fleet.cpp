class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();
        vector<pair<int, double>> cars(n);

        // Calculate time to reach the target for each car and store with position
        for (int i = 0; i < n; i++) {
            double time = (target - position[i]) / (double)speed[i];
            cars[i] = {position[i], time};
        }

        // Sort cars by their starting position in descending order
        sort(cars.begin(), cars.end(), [](pair<int, double>& a,pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = 0;

        // Go through each car to determine fleets
        for (const auto& car : cars) {
            double time = car.second;
            if (time > maxTime) {  // New fleet if this car takes longer than the previous
                fleets++;
                maxTime = time;
            }
        }

        return fleets;
    }
};