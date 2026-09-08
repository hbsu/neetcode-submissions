class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to handle duplicates and enable two pointer logic
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // Loop through the array using index i:
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            // if a > 0, break (all remaining numbers are positive)
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // skip duplicate values for the first number
            // startPointer = i + 1;
            // endPointer = nums.length() - 1;
            int left = i + 1, right = nums.size() - 1;
            // while startPointer < endPointer:        
            while ( left < right) {

                // int threeSum = a + nums[startPointer] + nums[endPointer]
                int summation = nums[left] + nums[i] + nums[right];
                // if threeSum > 0, move r left
                // if threeSum < 0, move startPointer right.
                // if threeSum == 0:
                if(summation > 0) {
                    right--;
                } else if (summation < 0) {
                    left++;
                } else {
                    // Add triplet to the result
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Move poitners inward.
                    left++;
                    right--;
                    // Skip duplicates at the left pointer.
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                

            }
        }
        // Return the list
        return result;
    }
};
