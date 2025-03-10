#include <iostream>
#include <vector>

int findMajorityElement(std::vector<int>& nums) {
    int candidate = 0, count = 0;

    // Phase 1: Find potential candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) count++;
    }

    return (count > nums.size() / 2) ? candidate : -1; // Return -1 if no majority element
}

int main() {
    std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int result = findMajorityElement(arr);
    
    if (result != -1) 
        std::cout << "Majority Element: " << result << std::endl;
    else
        std::cout << "No Majority Element found" << std::endl;

    return 0;
}
