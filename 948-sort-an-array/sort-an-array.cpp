// class Solution {
// public:
//     int partition(vector<int>& nums, int l, int r) {
//         // Find the pivot element
//         int pivotEle = nums[l];
//         int count = 0;

//         // Find the correct position of the pivot element
//         for (int i = l + 1; i <= r; i++) {
//             if (nums[i] <= pivotEle) {
//                 count++;
//             }
//         }

//         int pivotIdx = l + count;
//         swap(nums[l], nums[pivotIdx]);

//         // Partition the array around the pivot element
//         int i = l, j = r;
//         while (i < pivotIdx && j > pivotIdx) {
//             while (nums[i] <= pivotEle) {
//                 i++;
//             }
//             while (nums[j] > pivotEle) {
//                 j--;
//             }
//             if (i < pivotIdx && j > pivotIdx) {
//                 swap(nums[i], nums[j]);
//             }
//         }
//         return pivotIdx;
//     }

//     void quickSort(vector<int>& nums, int l, int r) {
//         if (l >= r) return;

//         int pivotIndex = partition(nums, l, r);

//         quickSort(nums, l, pivotIndex - 1);
//         quickSort(nums, pivotIndex + 1, r);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         quickSort(nums, 0, nums.size() - 1);
//         return nums;
//     }
// };

class Solution {
public:
    void merge(vector<int>& nums, int l,int mid, int r) {
        int len1=mid-l+1;
        int len2=r-mid;

        vector<int>arr1(len1,0);
        vector<int>arr2(len2,0);

        for(int i=0;i<len1 ;i++)
        {
            arr1[i]=nums[l+i];
        }

        for(int i=0;i<len2 ;i++)
        {
            arr2[i]=nums[mid+1+i];
        }

        int i=0,j=0,k=l;
        while(i<len1 && j<len2)
        {
            if(arr1[i]<arr2[j])
            {
                nums[k++]=arr1[i++];
            }
            else
            {
                nums[k++]=arr2[j++];
            }
        }

         while(i<len1)
        {
            nums[k++]=arr1[i++];
        }

        while(j<len2)
        {
            nums[k++]=arr2[j++];
        }

    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid=(l+r)/2;

        mergeSort(nums, l, mid );
        mergeSort(nums, mid + 1, r);
        merge(nums,l,mid,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// class Solution {
// public:
//     // Function to partition the array around a pivot
//     // Returns the final position of pivot element
//     int partition(vector<int>& arr, int low, int high) {
//         int pivot = arr[low];  // First element as pivot
//         int i = low, j = high; // Two pointers approach

//         while (i < j) {
//             // Find element greater than pivot from left
//             while (arr[i] <= pivot && i <= high - 1)
//                 i++;

//             // Find element smaller than or equal to pivot from right
//             while (arr[j] > pivot && j >= low + 1)
//                 j--;

//             // Swap if pointers haven't crossed
//             if (i < j)
//                 swap(arr[i], arr[j]);
//         }
//         // Place pivot in correct position
//         swap(arr[low], arr[j]);
//         return j;
//     }

//     // Recursive QuickSort function
//     void quickSortRecursive(vector<int>& arr, int low, int high) {
//         // Base case: if low >= high, array has 1 or 0 elements
//         if (low >= high)
//             return;

//         // 1. Get pivot position
//         int pivotPos = partition(arr, low, high);

//         // 2. Recursively sort left part
//         quickSortRecursive(arr, low, pivotPos - 1);

//         // 3. Recursively sort right part
//         quickSortRecursive(arr, pivotPos + 1, high);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         int n = nums.size();
//         quickSortRecursive(nums, 0, n - 1);
//         return nums;
//     }
// };