#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    size = N;
    matrix.resize(N, std::vector<int>(N, 0)); // resize the matrix to NxN and fill with 0s
}


Matrix::Matrix(std::vector<std::vector<int>> nums) {
    // initialize a matrix with the given values
    size = nums.size();
    matrix = nums;
}


bool Matrix::load_from_file(const std::string &filename) {
    // load a matrix from a file
    std::ifstream infile(filename);  // Open the file
    if (!infile.is_open()) {  // Check if the file is open
        return false;
    }

    infile >> size;  // Read the size of the matrix (N)
    matrix.resize(size, std::vector<int>(size));  // Resize matrix A to NxN
    // for loop to read the first NxN integers in the file
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) { // Read each element
            infile >> matrix[i][j]; // Store it in the matrix
        }
    }

    infile.close();  // Close the file
    return true; // return true if successful, false otherwise
}


Matrix Matrix::operator+(const Matrix &rhs) const {
    // add two matrices
    Matrix result(size); // create a new matrix to store the result
    for (std::size_t i = 0; i < size; ++i) { // iterate through rows
        for (std::size_t j = 0; j < size; ++j) { // iterate through columns
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j]; // add the elements
        }
    }
    return result; // return the result sum matrix
}


Matrix Matrix::operator*(const Matrix &rhs) const {
    // multiply two matrices
    Matrix result(size); // create a new matrix to store the result
    for (std::size_t i = 0; i < size; ++i) { // iterate through rows
        for (std::size_t j = 0; j < size; ++j) { // iterate through columns
            for (std::size_t k = 0; k < size; ++k) { // iterate through inner dimension
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j]; // multiply them
            }
        }
    }
    return result; // return the result product matrix
}


void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    // set the value of a specific element in the matrix
    if (i >= size || j >= size) {
        throw std::out_of_range("Index out of bounds in set_value()");
    }
    matrix[i][j] = n; // set the value at (i, j) to n
}


int Matrix::get_value(std::size_t i, std::size_t j) const {
    // get the value of a specific element in the matrix
    if (i >= size || j >= size) { // checks if the indices are in bounds
        throw std::out_of_range("Index out of bounds in get_value()");
    }
    return matrix[i][j]; // returns the value at (i, j)
}


void Matrix::update_element(std::size_t i, std::size_t j, int new_value) {
    // update the value of a specific element in the matrix
    if (i >= size || j >= size) { // checks if the indices are in bounds
        throw std::out_of_range("Index out of bounds in update_element()");
    }
    matrix[i][j] = new_value; // set the value at (i, j) to new_value
}


int Matrix::get_size() const { // gets the size of the matrix
    return size;
}


int Matrix::sum_diagonal_major() const { // sums the diagonal elements
    int sum = 0; // intialize sum to 0
    for (std::size_t i = 0; i < size; ++i) { // iterate through the diagonal elements
        sum += matrix[i][i]; // add the diagonal elements to sum
    }
    return sum; // return the sum of the diagonal elements
}


int Matrix::sum_diagonal_minor() const { // sums the secondary diagonal elements
    int sum = 0; // initialize sum to 0
    for (std::size_t i = 0; i < size; ++i) { // iterate through the secondary diagonal elements
        sum += matrix[i][size - i - 1]; // add the secondary diagonal elements to sum
    }
    return sum; // return the sum of the secondary diagonal elements
}


void Matrix::swap_rows(std::size_t r1, std::size_t r2) { // swaps the two rows in the matrix
    if (r1 >= size || r2 >= size) { // checks if the indices are in bounds
        return;
    }
    std::swap(matrix[r1], matrix[r2]); // swap the rows
}


void Matrix::swap_cols(std::size_t c1, std::size_t c2) { // swaps the two columns in the matrix
    if (c1 >= size || c2 >= size) { // checks if the indices are in bounds
        return;
    }
    for (std::size_t i = 0; i < size; ++i) { // iterate through the rows
        std::swap(matrix[i][c1], matrix[i][c2]); // swap the columns
    }
}


void Matrix::print_matrix() const { // prints the matrix
    for (size_t i = 0; i < size; ++i) { // iterate through the rows
        for (size_t j = 0; j < size; ++j) { // iterate through the columns
            std::cout << std::setw(2) << std::setfill('0') << matrix[i][j] << " "; // Format output to keep leading zeros
        }
        std::cout << std::endl; // prints a new line after each row
    }
}


bool Matrix::load_rows_from_file(const std::string &filename, size_t startRow) { // load specific rows from a file
    std::ifstream infile(filename);  // Open the file
    if (!infile.is_open()) {  // Check if the file is open
        return false;
    }

    infile >> size; // Read and ignore the size again (since we already know it)
    matrix.resize(size, std::vector<int>(size)); // Resize matrix B to NxN
    
    // Skip the rows of Matrix A
    int temp; //initialize a temporary variable to read and ignore the values
    for (std::size_t i = 0; i < startRow * size; ++i) {
        infile >> temp; // Read and ignore the row
    }

    // Read Matrix B from the file
    for (std::size_t i = 0; i < size; ++i) { // iterate through the rows
        for (std::size_t j = 0; j < size; ++j) { // iterate through the columns
            if (!(infile >> matrix[i][j])) { // Read each element
                return false; // Return false if reading fails
            }
        }
    }

    infile.close(); // close the file
    return true; // return true if successful, false otherwise
}