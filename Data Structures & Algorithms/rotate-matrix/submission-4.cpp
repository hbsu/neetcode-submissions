class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0; //leftmost
        int right = matrix.size() - 1; //riightmost
        //rotate every corner of images, then size down the bounds of the edges
        //rotate along the outside edges then the inside edges
        //has to be while left is less than right
        while ( left < right ) {

            //walk the the loop
            for(int i = 0; i < (right - left); i++) {
                int top = left;
                int bottom = right;
                //save the top left corner
                int topLeft = matrix[top][left+i]; //if first iteration, top left, if second iteration, right to the top left
                //top left = bottom left
                matrix[top][left+i] = matrix[bottom-i][left];
                //bottom left = bottom right
                matrix[bottom-i][left] = matrix[bottom][right-i];
                //bottom right = top right
                matrix[bottom][right - i] = matrix[top+i][right];
                //top right = topleft
                matrix[top+i][right] = topLeft;

            }
            left++;
            right--;

        }



    }
};
