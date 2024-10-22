#include <iostream>
#include <iomanip>
using namespace std;

// Функція для ущільнення матриці
void CompactMatrix(int** a, int& rowCount, int& colCount) {
    // Створюємо нову матрицю для зберігання непорожніх рядків і стовпців
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
            newMatrix[newRowCount++] = a[i]; // Додаємо рядок, якщо він не пустий
        }
    }

    // Видаляємо стовпці, заповнені нулями
    int* columnFlags = new int[colCount] {0}; // Мітки стовпців

    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < newRowCount; i++) {
            if (newMatrix[i][j] != 0) {
                columnFlags[j] = 1; // Стовпець не пустий
                break;
            }
        }
    }

    // Формуємо нову матрицю без пустих стовпців
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

    // Оновлюємо значення rowCount і colCount
    rowCount = newRowCount;
    colCount = newColCount;

    // Виводимо нову матрицю
    cout << "Compact Matrix:\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << finalMatrix[i][j];
        }
        cout << endl;
    }

    // Звільняємо пам'ять
    delete[] columnFlags;
    delete[] newMatrix;
    for (int i = 0; i < newRowCount; i++) {
        delete[] finalMatrix[i];
    }
    delete[] finalMatrix;
}

// Функція для знаходження номера першого рядка з додатнім елементом
int FirstPositiveRow(int** a, int rowCount, int colCount, int rowNo = 0) {
    if (rowNo >= rowCount) {
        return -1; // Не знайдено жодного рядка з додатніми елементами
    }
    for (int j = 0; j < colCount; j++) {
        if (a[rowNo][j] > 0) {
            return rowNo; // Знайдено рядок з додатнім елементом
        }
    }
    return FirstPositiveRow(a, rowCount, colCount, rowNo + 1); // Рекурсивний виклик для наступного рядка
}

int main() {
    int rowCount, colCount;
    cout << "Enter number of rows: "; cin >> rowCount;
    cout << "Enter number of columns: "; cin >> colCount;

    // Створення динамічної матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Виклик функцій
    CompactMatrix(a, rowCount, colCount);

    int firstPositiveRow = FirstPositiveRow(a, rowCount, colCount);
    if (firstPositiveRow != -1) {
        cout << "The first row with a positive element is: " << firstPositiveRow << endl;
    }
    else {
        cout << "No row contains a positive element." << endl;
    }

    // Звільняємо пам'ять
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
