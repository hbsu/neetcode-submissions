class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # Initialize two pointers where l = 0 (left boundary of current layer)
        l = 0
        r = len(matrix) - 1
        # r = n -1 (right boundary of current layer)
        # while left is less than right (process each layer)
        while l < r:
        # processing layer: 
        # For each position i in the current layer from 0 to r - l - 1:
            for i in range(r-l):

        # identify top = l, bottom = r
                top = l
                bottom = r
        # save top left value temporarily
                topLeft = matrix[top][l+i]
        # move bottom left ->top left
                matrix[top][l+i] = matrix[bottom - i][l]
        # move bottom right-> bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i]
        # move top right -> bottom right
                matrix[bottom][r - i] = matrix[top+i][r]
        # move saved top left  -> top right
                matrix[top + i][r] = topLeft
            r-= 1
            l+= 1
        # after finishing one layer increment left, decrement r
        # continue until all layers rotated


