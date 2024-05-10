#include <iostream>

int* spiralOrder(int** matrix, int rows, int cols) {
    int size = rows * cols;
    int* result = new int[size];
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int index = 0;
    
    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; ++col) {
            result[index++] = matrix[top][col];
        }
        top++;
        
        for (int row = top; row <= bottom; ++row) {
            result[index++] = matrix[row][right];
        }
        right--;
        
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                result[index++] = matrix[bottom][col];
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                result[index++] = matrix[row][left];
            }
            left++;
        }
    }
    
    return result;
}

int main() {
    // Define matrix 1
    int rows1 = 3, cols1 = 3;
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Define matrix 2
    int rows2 = 4, cols2 = 4;
    int matrix2[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Matrices to pointers
    int* matrix1Ptr[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int* matrix2Ptr[4] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};

    // Call the function and print the results for matrix1
    int* result1 = spiralOrder(matrix1Ptr, rows1, cols1);
    std::cout << "Spiral order of matrix 1: ";
    for (int i = 0; i < rows1 * cols1; i++) {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;
   
    // Call the function and print the results for matrix2
    int* result2 = spiralOrder(matrix2Ptr, rows2, cols2);
    std::cout << "Spiral order of matrix 2: ";
    for (int i = 0; i < rows2 * cols2; i++) {
        std::cout << result2[i] << " ";
    }

    return 0;
}
