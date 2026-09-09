class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        while(left < right){
            //rotate the outside of the matrix then the inside of the matrix
            int bottom = right;
            int top = left;
            // [0,0 ][0, 1][ 0,2]
            // [1,0][1,1][1,2]
            // [2,0][2,1][2,2]

            //every loop you are swapping four elements on a "ring". i increments how far across each ring/layer you rotate
            for(int i = 0; i < (right - left); i++){
                //rotate
                //swap all the "corners"
                //keep topleft
                int topLeft = matrix[top][left+i];
                matrix[top][left+i] = matrix[bottom - i][left];
                matrix[bottom-i][left] = matrix[bottom][right - i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = topLeft;
            }
            right--;
            left++;


        }
    }
};
