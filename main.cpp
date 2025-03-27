#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    Matrix matrixA(4);
    
    // Load data from a file (assuming the file "matrix.txt" is properly formatted)
    if (!matrixA.load_from_file("matrix.txt")) {
        std::cerr << "Failed to load matrix from file." << std::endl;
        return 1;
    }

    // Print the loaded matrix
    std::cout << "Matrix A:" << std::endl;
    matrixA.print_matrix();

    // Create another matrix (for addition and multiplication test)
    Matrix matrixB(4);
    if (!matrixB.load_rows_from_file("matrix.txt", 4, 4)) {
        std::cerr << "Failed to load matrixB from file." << std::endl;
        return 1;
    }

    // Print matrix B
    std::cout << "Matrix B:" << std::endl;
    matrixB.print_matrix();

    // Add two matrices and print the result
    Matrix sum = matrixA + matrixB;
    std::cout << "Sum of Matrix A and Matrix B:" << std::endl;
    sum.print_matrix();

    // Multiply two matrices and print the result
    Matrix product = matrixA * matrixB;
    std::cout << "Product of Matrix A and Matrix B:" << std::endl;
    product.print_matrix();

    // Print the sum of the main diagonal
    int mainDiagonalSum = matrixA.sum_diagonal_major();
    std::cout << "Sum of the main diagonal: " << mainDiagonalSum << std::endl;

    // Print the sum of the secondary diagonal
    int secondaryDiagonalSum = matrixA.sum_diagonal_minor();
    std::cout << "Sum of the secondary diagonal: " << secondaryDiagonalSum << std::endl;

    // Swap two rows in matrix A and print the result
    std::size_t row1, row2;
    std::cout << "Enter two row indices to swap: " << std::endl;
    std::cin >> row1 >> row2;
    matrixA.swap_rows(row1, row2);
    matrixA.print_matrix();

    // Swap two columns in matrix A and print the result
    std::size_t col1, col2;
    std::cout << "Enter two column indices to swap: " << std::endl;
    std::cin >> col1 >> col2;
    matrixA.swap_cols(col1, col2);
    matrixA.print_matrix();

    // Update a value in matrix A and print the result
    matrixA.update_element(1, 1, 999);
    std::cout << "Matrix A after updating element at (1,1) to 999:" << std::endl;
    matrixA.print_matrix();


    return 0;
}
