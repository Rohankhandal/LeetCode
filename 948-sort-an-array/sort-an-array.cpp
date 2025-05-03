class Solution {
public:
    int  findPivot(vector<int>&arr,int low,int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (i <= high - 1 && arr[i] <= pivot)
                i++;
            while (j >= low + 1 && arr[j] > pivot)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]); // place pivot at its correct position
        return j;
    }
    void qs(vector<int>&nums,int l,int r)
    {
        if(l<r){
            int pivotIdx=findPivot(nums,l,r);

            qs(nums,l,pivotIdx-1);
            qs(nums,pivotIdx+1,r);

        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};