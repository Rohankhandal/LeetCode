class Solution {
public:
int lowerBound(vector<int>&arr,int x)
{
    int start=0,end=arr.size()-1;
    // int ans=-1;
    int ans=end;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]>=x)
        {
            ans=mid;
            end=mid-1;
        }
        else if(x>arr[mid])
        {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return ans;
}
vector<int> bs_method(vector<int>&arr, int k, int x) 
//e.g 12,16,22,30,35,39,42,45,48,50,53,55,56
{
    //lower bound
    int h=lowerBound(arr,x);
    int l=h-1;
    while(k--)
    {
        //EDGE CASE:
        if(l<0)
        {
            h++;
        }
        else if(h>=arr.size())
        {
            l--;
        }
        else if(x-arr[l]>arr[h]-x)
        {
            h++;
        }
        else {
            l--;
        }
    }
    return vector<int>(arr.begin()+l+1,arr.begin()+h);


    return vector<int>(arr.begin()+l,arr.begin()+h+1);
}
// vector<int> twoPtrMethod(vector<int>&arr, int k, int x) 
// //e.g 12,16,22,30,35,39,42,45,48,50,53,55,56
// {
//     int l=0,h=arr.size()-1;
//     while(h-l>=k)
//     {
//         if(x-arr[l] > arr[h] -x )  //comparsion respect of difference with x
//         {
//             l++;  //shrink array if diff is greater than the h pointer element diff
//         }
//         else {
//             h--;
//         }
//     }
//     // vector<int>ans;
//     // for(int i=l;i<=h;i++)
//     // {
//     //     ans.push_back(arr[i]);
//     // }
//     // return ans;
//     // or

//     return vector<int>(arr.begin()+l,arr.begin()+h+1);
// }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return twoPtrMethod(arr,k,x);
        return bs_method(arr,k,x);
    }
};