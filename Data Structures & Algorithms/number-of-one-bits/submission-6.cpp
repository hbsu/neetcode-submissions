class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++){
            if(mask & n) result+=1;
            mask <<= 1;
        }
        return result;
    }
};
