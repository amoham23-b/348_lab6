#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


//reading from the file
void read_file(const string& filePath, int **& first_matrix, int **& second_matrix, int& size){
    ifstream file(filePath);
    if(file){
        file >> size;
        first_matrix = new int*[size];
        second_matrix = new int*[size];
        for(int i = 0; i < size; ++i){
            first_matrix[i] = new int[size];
            for (int j = 0; j < size; ++j){
                file >> first_matrix[i][j];
            }
        }

        for (int i = 0; i < size; ++i) {
            second_matrix[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                file >> second_matrix[i][j];
            }
        }
        
    }
    else{
        cout << "The file is not here" << endl;
    }
}

void print_matrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void add_matrix(int **first_matrix, int **second_matrix, int **&result, int size) {
    result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }
}

void matrix_mult(int **first_matrix, int **second_matrix, int **&result, int size) {
    result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < size; k++) {
                result[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
        }
    }
}

void subtract_matrix(int **first_matrix, int **second_matrix, int **&result, int size){
    result = new int*[size];
    for (int i = 0; i < size; i++){
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = first_matrix[i][j] - second_matrix[i][j];
        }
    }
}

void copy_matrix(int **first_matrix, int **second_matrix, int size){
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            second_matrix[i][j] = first_matrix[i][j];
        }
    }
}

void new_matrix(int **first_matrix, int **updatedMatrix, int row, int col, int value, int size){
    copy_matrix(first_matrix, updatedMatrix, size);
    if (row >= 0 && row < size && col >= 0 && col < size){
        updatedMatrix[row][col] = value;
    }
    else{
        cout << "Error" << endl;
    }
}

int get_max(int **matrix, int size){
    int max = matrix[0][0];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] > max){
               max = matrix[i][j];
            }
        }
    }
    return max;
}

void transpose(int **first_matrix, int **transposedMatrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposedMatrix[j][i] = first_matrix[i][j];
        }
    }
}

int main(){
    int** first_matrix;
    int** second_matrix;
    int matrixSize = 3;
    int** addedMatrix;
    int** multiplyMatrix;
    int** subtractedMatrix;
    int** updatedMatrix = new int*[matrixSize];
    int maxVal;
  
    

    string filePath = "matrix.txt";
    read_file(filePath, first_matrix, second_matrix, matrixSize);

    for(int i = 0; i < matrixSize; ++i) {
        updatedMatrix[i] = new int[matrixSize];
        for(int j = 0; j < matrixSize; ++j) {
            updatedMatrix[i][j] = 0;
        }
    }

    int **transposedMatrix = new int*[matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        transposedMatrix[i] = new int[matrixSize];
        for (int j = 0; j < matrixSize; ++j) {
            transposedMatrix[i][j] = 0;
        }
    }

    cout << "Matrix 1:" << endl;
    print_matrix(first_matrix, matrixSize);
    cout << endl;
    cout << "Matrix 2:" << endl;
    print_matrix(second_matrix, matrixSize);

    cout << endl;

    add_matrix(first_matrix, second_matrix, addedMatrix, matrixSize);
    cout << "Added Matrix:" << endl;
    print_matrix(addedMatrix, 3);

    cout << endl;

    matrix_mult(first_matrix, second_matrix, multiplyMatrix, matrixSize);
    cout << "Multiplied Matrix:" << endl;
    print_matrix(multiplyMatrix, matrixSize);

    cout << endl;

    subtract_matrix(first_matrix, second_matrix, subtractedMatrix, matrixSize);
    cout << "subtracted Matrix: " << endl;
    print_matrix(subtractedMatrix, matrixSize);

    cout << endl;

    new_matrix(first_matrix, updatedMatrix, 0 , 2, 100, 3);
    cout << "Updated Matrix: " << endl;
    print_matrix(updatedMatrix, matrixSize);

    cout << endl;

    maxVal = get_max(first_matrix, 3);
    cout << "The max value of matrix:  " << maxVal << endl;

    cout << endl;

    transpose(first_matrix, transposedMatrix, matrixSize);
    cout << "Transposed Matrix:" << endl;
    print_matrix(transposedMatrix, matrixSize);


    for (int i = 0; i < matrixSize; ++i) {
        delete[] first_matrix[i];
        delete[] second_matrix[i];
        delete[] addedMatrix[i];
        delete[] multiplyMatrix[i];
        delete[] subtractedMatrix[i];
        delete[] updatedMatrix[i];
        delete[] transposedMatrix[i];
    }
    delete[] first_matrix;
    delete[] second_matrix;
    delete[] addedMatrix;
    delete[] multiplyMatrix;
    delete[] subtractedMatrix;
    delete[] updatedMatrix;
    delete[] transposedMatrix;
    return 0;
}