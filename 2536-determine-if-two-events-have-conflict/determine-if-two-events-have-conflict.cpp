class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int minuteStartingTime1=((event1[0][0]-'0')*10+(event1[0][1]-'0'))*60+
        (event1[0][3]-'0')*10+(event1[0][4]-'0');
         int minuteEndingTime1=((event1[1][0]-'0')*10+(event1[1][1]-'0'))*60+
        (event1[1][3]-'0')*10+(event1[1][4]-'0');

        int minuteStartingTime2=((event2[0][0]-'0')*10+(event2[0][1]-'0'))*60+
        (event2[0][3]-'0')*10+(event2[0][4]-'0');
         int minuteEndingTime2=((event2[1][0]-'0')*10+(event2[1][1]-'0'))*60+
        (event2[1][3]-'0')*10+(event2[1][4]-'0');

        if(minuteStartingTime1>=minuteStartingTime2 &&minuteStartingTime1<= minuteEndingTime2)
            return true;
        if(minuteEndingTime1>=minuteStartingTime2 &&minuteEndingTime1<= minuteEndingTime2)
            return true;
        if(minuteStartingTime2>=minuteStartingTime1 &&minuteStartingTime2<= minuteEndingTime1)
            return true;
        if(minuteEndingTime2>=minuteStartingTime1 &&minuteEndingTime2<= minuteEndingTime1)
            return true;
        return false;

        
        
    }
};