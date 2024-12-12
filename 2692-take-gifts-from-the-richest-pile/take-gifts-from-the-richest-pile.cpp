class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq;
        long long sum=0;
        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
            sum+=gifts[i];
        }

        while(k>0)
        {
            int top=pq.top();
            pq.pop();
            sum-=top;
            cout<<"F"<<sum<<" ";
            int sqRoot=sqrt(top);
            pq.push(sqRoot);
            sum+=sqRoot;
            cout<<"S"<<sum<<endl;
            k--;
        }

        return sum;


    }
};