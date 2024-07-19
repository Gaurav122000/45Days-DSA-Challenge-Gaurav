class Solution {
public:

    void swap(vector<int>& arr, int post1, int post2){
        int temp = arr[post1];
        arr[post1] = arr[post2];
        arr[post2] = temp;
    }

    void sortColors(vector<int>& nums) {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;

        while(mid<=end){
            switch(nums[mid]){
                case 0:
                //swap with start index
                    swap(nums, start, mid);
                    mid++; start++;
                    break;
                
                case 1:
                    mid++;
                    break;
                
                case 2:
                    swap(nums, mid, end);
                    end--;
                    break;

            }
        }
    }
};
//time complexity = O(n)