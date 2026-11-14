#include <iostream>
using namespace std;

int main() {

    const int rows = 4, cols = 5;
    int matrix[rows][cols] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int sparse[rows * cols + 1][3]; // hidden representation

    int k = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    cout << "row\tcol\tvalue" << endl;
    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }

    return 0;
}