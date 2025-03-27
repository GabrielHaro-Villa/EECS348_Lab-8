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
    matrix.resize(N, std::vector<int>(N, 0));
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
        for (std::size_t j = 0; j < size; ++j) {
            infile >> matrix[i][j];
        }
    }

    infile.close();  // Close the file
    return true; // return true if successful, false otherwise
}


Matrix Matrix::operator+(const Matrix &rhs) const {
    // add two matrices
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}


Matrix Matrix::operator*(const Matrix &rhs) const {
    // multiply two matrices
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            for (std::size_t k = 0; k < size; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return result;
}


void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    // set the value of a specific element in the matrix
    matrix[i][j] = n;
}


int Matrix::get_value(std::size_t i, std::size_t j) const {
    // get the value of a specific element in the matrix
    return matrix[i][j];
}


void Matrix::update_element(std::size_t i, std::size_t j, int new_value) {
    // update the value of a specific element in the matrix
    matrix[i][j] = new_value;
}


int Matrix::get_size() const {
    // get the size of the matrix
    return size;
}


int Matrix::sum_diagonal_major() const {
    // sum the elements on the major diagonal
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}


int Matrix::sum_diagonal_minor() const {
    // sum the elements on the minor diagonal
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += matrix[i][size - i - 1];
    }
    return sum;
}


void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    // swap two rows in the matrix
    if (r1 >= size || r2 >= size) {
        return;
    }
    std::swap(matrix[r1], matrix[r2]);
}


void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    // swap two columns in the matrix
    if (c1 >= size || c2 >= size) {
        return;
    }
    for (std::size_t i = 0; i < size; ++i) {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}


void Matrix::print_matrix() const {
    // print out the matrix
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << std::setw(2) << std::setfill('0') << matrix[i][j] << " "; // Format output to keep leading zeros
        }
        std::cout << std::endl;
    }
}


bool Matrix::load_rows_from_file(const std::string &filename, size_t start_row, size_t num_rows) {
    // load specific rows from a file
    std::ifstream infile(filename);  // Open the file
    if (!infile.is_open()) {  // Check if the file is open
        return false;
    }

    size_t total_size;
    infile >> total_size;  // Read the size of the matrix (N)
    
    // Temporary storage for skipping rows
    std::string line;
    std::getline(infile, line);  // Skip the first line with size

    // Skip rows before start_row
    for (size_t i = 0; i < start_row; ++i) {
        std::getline(infile, line);
    }

    // Resize matrix to specified number of rows
    size = num_rows;
    matrix.resize(size, std::vector<int>(total_size));

    // Read specified number of rows
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < total_size; ++j) {
            infile >> matrix[i][j];
        }
    }

    infile.close();  // Close the file
    return true; // return true if successful, false otherwise
}