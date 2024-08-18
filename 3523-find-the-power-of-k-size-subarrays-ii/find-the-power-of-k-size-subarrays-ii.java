class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int length = nums.length;
        int[] op = new int[length - k + 1];

        boolean isSortedConsecutively = true;
        for (int i = 1; i < k; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                isSortedConsecutively = false;
                break;
            }
        }
        op[0] = isSortedConsecutively ? nums[k - 1] : -1;

        for (int i = 1; i <= length - k; i++) {
            if (isSortedConsecutively && nums[i + k - 1] == nums[i + k - 2] + 1) {
                op[i] = nums[i + k - 1];
            } else {

                isSortedConsecutively = true;
                for (int j = 1; j < k; j++) {
                    if (nums[i + j] != nums[i + j - 1] + 1) {
                        isSortedConsecutively = false;
                        break;
                    }
                }
                op[i] = isSortedConsecutively ? nums[i + k - 1] : -1;
            }
        }

        return op;
    }
}