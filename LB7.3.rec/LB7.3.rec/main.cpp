#include <iostream>
#include <iomanip>
using namespace std;

// ������� ��� ���������� �������
void CompactMatrix(int** a, int& rowCount, int& colCount) {
    // ��������� ���� ������� ��� ��������� ��������� ����� � ��������
    int** newMatrix = new int* [rowCount];
    int newRowCount = 0;

    for (int i = 0; i < rowCount; i++) {
        bool isEmptyRow = true;
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] != 0) {
                isEmptyRow = false;
                break;
            }
        }
        if (!isEmptyRow) {
            newMatrix[newRowCount++] = a[i]; // ������ �����, ���� �� �� ������
        }
    }

    // ��������� �������, �������� ������
    int* columnFlags = new int[colCount] {0}; // ̳��� ��������

    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < newRowCount; i++) {
            if (newMatrix[i][j] != 0) {
                columnFlags[j] = 1; // �������� �� ������
                break;
            }
        }
    }

    // ������� ���� ������� ��� ������ ��������
    int newColCount = 0;
    for (int j = 0; j < colCount; j++) {
        if (columnFlags[j]) {
            newColCount++;
        }
    }

    int** finalMatrix = new int* [newRowCount];
    for (int i = 0; i < newRowCount; i++) {
        finalMatrix[i] = new int[newColCount];
        int currentColIndex = 0;
        for (int j = 0; j < colCount; j++) {
            if (columnFlags[j]) {
                finalMatrix[i][currentColIndex++] = newMatrix[i][j];
            }
        }
    }

    // ��������� �������� rowCount � colCount
    rowCount = newRowCount;
    colCount = newColCount;

    // �������� ���� �������
    cout << "Compact Matrix:\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << finalMatrix[i][j];
        }
        cout << endl;
    }

    // ��������� ���'���
    delete[] columnFlags;
    delete[] newMatrix;
    for (int i = 0; i < newRowCount; i++) {
        delete[] finalMatrix[i];
    }
    delete[] finalMatrix;
}

// ������� ��� ����������� ������ ������� ����� � ������� ���������
int FirstPositiveRow(int** a, int rowCount, int colCount, int rowNo = 0) {
    if (rowNo >= rowCount) {
        return -1; // �� �������� ������� ����� � �������� ����������
    }
    for (int j = 0; j < colCount; j++) {
        if (a[rowNo][j] > 0) {
            return rowNo; // �������� ����� � ������� ���������
        }
    }
    return FirstPositiveRow(a, rowCount, colCount, rowNo + 1); // ����������� ������ ��� ���������� �����
}

int main() {
    int rowCount, colCount;
    cout << "Enter number of rows: "; cin >> rowCount;
    cout << "Enter number of columns: "; cin >> colCount;

    // ��������� �������� �������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // ������ �������
    CompactMatrix(a, rowCount, colCount);

    int firstPositiveRow = FirstPositiveRow(a, rowCount, colCount);
    if (firstPositiveRow != -1) {
        cout << "The first row with a positive element is: " << firstPositiveRow << endl;
    }
    else {
        cout << "No row contains a positive element." << endl;
    }

    // ��������� ���'���
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
