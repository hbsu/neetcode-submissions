class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int startPointer = 0;
        int endPointer = numbers.size() - 1;
        while (startPointer < endPointer){

            int currentSum = numbers[startPointer] + numbers[endPointer];
            if (currentSum > target){

                endPointer -= 1;
            } else if(currentSum < target){
                startPointer +=1;
            } else {
                return {startPointer + 1, endPointer + 1};
            }
        }
        return {};

    }
};
