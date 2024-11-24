//Approach-1 (Naive O(n^2) approach that comes to mind first)
//T.C : O(n^2)
//S.C : O(n)
// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n = times.size();
        
//         vector<int> endTimes(n, -1); //at max we will have 0 to n-1 chairs
        
//         /*
//             We need to sort the times based on arrival time but we don't want to
//             loose the friend number after sorting. So, store the arrival time
//             of targetFriend because it's given in the question that 
//             Each arrival time is distinct.
//         */
        
//         int targetArrivalTime = times[targetFriend][0];
        
//         sort(begin(times), end(times));
        
//         for(vector<int> &time : times) {
//             int arrival = time[0];
//             int depart  = time[1];
//             //Find the first unoccupied chair
//             for(int i = 0; i<n; i++) {
//                 if(endTimes[i] <= arrival) {
//                     endTimes[i] = depart; //update with current friend depart time
                    
//                     if(arrival == targetArrivalTime)
//                         return i;
//                     break;
//                 }
//             }
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;
        
        // Record arrival and departure events
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i}); // Arrival
            events.push_back({times[i][1], ~i}); // Departure (negated index)
        }
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs; // Min-heap of available chairs
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // Initially all chairs are available
        }
        
        vector<int> chairAssignment(n, -1); // Stores chair assignment for each friend
        
        for (auto& event : events) {
            int time = event.first;
            int idx = event.second;
            
            if (idx >= 0) { // Arrival
                int chair = availableChairs.top();
                availableChairs.pop();
                chairAssignment[idx] = chair;
                if (idx == targetFriend) return chair;
            } else { // Departure
                int friendIdx = ~idx;
                availableChairs.push(chairAssignment[friendIdx]);
            }
        }
        
        return -1; // Should never reach here
    }
};