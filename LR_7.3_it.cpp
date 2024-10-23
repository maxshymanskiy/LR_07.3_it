#include <iostream>
#include <iomanip>

using namespace std;

//void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);

int Part1_Count(int** a, const int rowCount, const int colCount);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount);

bool IsMinInRow(int** a, const int row, const int col, const int colCount);
bool IsMaxInCol(int** a, const int row, const int col, const int rowCount);

int main() {
   /* int Low = -17;
    int High = 15;*/

    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    //Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = Part1_Count(a, rowCount, colCount);
    cout << "Number of negative elements in rows with zero : " << count << endl;

    cout << endl;
    Part2_SaddlePoint(a, rowCount, colCount);
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

//void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
//    for (int i = 0; i < rowCount; i++)
//        for (int j = 0; j < colCount; j++)
//            a[i][j] = Low + rand() % (High - Low + 1);
//}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount) {
    int totalNegativeCount = 0;

    for (int i = 0; i < rowCount; i++) {
        bool hasZero = false;
        int negativeCount = 0;

        for (int j = 0; j < colCount; j++) {
            if (a[i][j] == 0)
                hasZero = true;
            if (a[i][j] < 0)
                negativeCount++;
        }

        if (hasZero)
            totalNegativeCount += negativeCount;
    }

    return totalNegativeCount;
}

bool IsMinInRow(int** a, const int row, const int col, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        if (a[row][j] < a[row][col])
            return false;
    }
    return true;
}

bool IsMaxInCol(int** a, const int row, const int col, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        if (a[i][col] > a[row][col])
            return false;
    }
    return true;
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount) {
    cout << "Saddle points (minimum in row and maximum in column):" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (IsMinInRow(a, i, j, colCount) && IsMaxInCol(a, i, j, rowCount)) {
                cout << setw(4) << ++No << setw(6) << i << setw(6) << j << endl;
            }
        }
    }

    if (No == 0)
        cout << "No saddle points found." << endl;
}
