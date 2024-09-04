class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>mp;
        for(auto &it:obstacles)
        {
            string key=to_string(it[0])+"_"+to_string(it[1]);
           mp.insert(key);
        }
        int maxDis=INT_MIN;

        int x=0;int y=1;
        
        int cordX=0;
        int cordY=0; //north face
        for(int i=0;i<commands.size();i++)
        {
            int val=commands[i];
            if(val==-1)  //right
            {
               int temp=x;
                x=y;
                y=-temp;
                continue;
            }
            if(val==-2)  //left
            {
                int temp=x;
                x=-y;
                y=temp;
                continue;
            }

            for(int i=0;i<val;i++)
            {
                int moveX=cordX+x;
                int moveY=cordY+y;
                string key=to_string(moveX)+"_"+to_string(moveY);
                if(mp.find(key)!=mp.end())
                {
                    break;
                }

                cordX=moveX;
                cordY=moveY;
            }
            maxDis=max(maxDis,cordX*cordX + cordY*cordY);
        }
        return maxDis;
    }
};