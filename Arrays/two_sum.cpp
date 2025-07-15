#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> res; // maps number -> its index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement is already in the map
        if (res.find(complement) != res.end()) {
            return {res[complement], i};
        }

        // Store current number and its index
        res[nums[i]] = i;
    }

    // If no solution found
    return {};
}

