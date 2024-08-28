class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadList(deadends.begin(),deadends.end());

        if(deadList.count("0000")) return -1;
        unordered_map<string,bool>visited;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        visited["0000"]=true;

        while(!q.empty())
        {
            string combination=q.front().first;
            int moves=q.front().second;

            q.pop();
            if(combination==target) return moves;

            for(int i=0;i<4;i++)
            {
                for(int delta=-1;delta<=1;delta++)
                {
                    int newDigit=((combination[i]-'0')+delta+10)%10;
                    string newCombination=combination;
                    newCombination[i]=(newDigit+'0');

                    if(deadList.find(newCombination)==deadList.end() && visited.find(newCombination)==visited.end())
                    {
                        visited[newCombination]=true;
                        q.push({newCombination,moves+1});
                    }
                }
            }
        }


        return -1;


    }
};