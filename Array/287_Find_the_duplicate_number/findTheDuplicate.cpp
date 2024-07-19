#include <iostream>
#include <vector> // Include the vector header

using namespace std;

int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    //find the intersection
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];//because it move 2 times
    }while(slow!=fast);

    //find the enterance of the cycle
    slow = nums[0]
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 2, 3, 2}; // Sample vector
    int result = findDuplicate(nums);
    cout << "Duplicate: " << result << endl;
    return 0;
}
