class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //have poitner at front back of array.
        //iterate through 32 bit number and push either a 1 or a 0
        uint32_t result = 0;
        for(int i = 0; i < 32; i++){
            result <<= 1;
            if(n & 1){
                result |= 1;
            }
            n >>=1 ;
        }
        return result;
    }
};
