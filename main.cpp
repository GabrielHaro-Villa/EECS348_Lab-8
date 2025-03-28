#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    string filename; // string to store the filename
    std::cout << "Enter the filename: "; // prompts the user for the filename
    std::cin >> filename; // reads the filename from the user input
    Matrix matrixA(0); // Creates matrix A default size 0x0
    
    // Load data from a file (assuming the file "matrix.txt" is properly formatted)
    if (!matrixA.load_from_file(filename)) {
        std::cerr << "Failed to load matrix from file." << std::endl; // error message if it fails to load the file
        return 1; // exits the program with error code 1
    }

    // Print the loaded matrix
    std::cout << "Matrix A:" << std::endl;
    matrixA.print_matrix();

    Matrix matrixB(0); // Creates matrix B default size 0x0
    // Create another matrix (for addition and multiplication test)
    if (!matrixB.load_rows_from_file(filename, matrixA.get_size())) {
        std::cerr << "Failed to load matrixB from file." << std::endl; // error message if it fails to load the file
        return 1; // exits the program with error code 1
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
    product.print_matrix(); // prints the matrix

    // Print the sum of the main diagonal
    int mainDiagonalSum = matrixA.sum_diagonal_major();
    std::cout << "Sum of the main diagonal: " << mainDiagonalSum << std::endl;

    // Print the sum of the secondary diagonal
    int secondaryDiagonalSum = matrixA.sum_diagonal_minor();
    std::cout << "Sum of the secondary diagonal: " << secondaryDiagonalSum << std::endl;

    // Swap two rows in matrix A and print the result
    std::size_t row1, row2;
    std::cout << "Enter two row indices to swap: " << std::endl;
    std::cin >> row1 >> row2; // reads the row indices from the user input
    matrixA.swap_rows(row1, row2); // function call to swap the rows using the two indices
    matrixA.print_matrix(); // prints the matrix

    // Swap two columns in matrix A and print the result
    std::size_t col1, col2;
    std::cout << "Enter two column indices to swap: " << std::endl;
    std::cin >> col1 >> col2; // reads the column indices from the user input
    matrixA.swap_cols(col1, col2); // function call to swap the columns using the two indices
    matrixA.print_matrix(); // prints the matrix

    // Update a value in matrix A and print the result
    std::size_t row, col;
    int newValue; // variable to store the new value
    std::cout << "Enter row index, column index, and new value: " << std::endl; 
    std::cin >> row >> col >> newValue; // reads the row index, column index, and new value from the user input
    matrixA.update_element(row, col, newValue); // function call to update the element in the matrix
    matrixA.print_matrix(); // prints the matrix


    return 0; // exits the program with success code 0
}
