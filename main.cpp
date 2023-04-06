#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

const unsigned int DIM1 = 5;
const unsigned int DIM2 = 5;
const unsigned int DIM3 = 10;

void setHeightToMap(int (&map)[DIM1][DIM2][DIM3], const int (&heights)[DIM1][DIM2]) {
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            int currentValue = heights[i][j];
            for (int k = 0; k < currentValue; k++) {
                map[i][j][k] = 1;
            }
        }
    }
}

// Визуализирует всю карту в поперечном срезе
void printMap(int (&map)[DIM1][DIM2][DIM3]) {
    cout << std::setw(22) << "--PRINT-MAP--" << endl;

    cout << "levels: ";
    for (int i = 0; i < DIM3; ++i) cout << std::setw(2) << i;
    cout << "\n\t" << endl;
    for (auto &line: map) {
        for (auto &cell: line) {
            cout << "\t";
            for (int stage: cell) {
                if (!stage) break;
                cout << std::setw(2) << stage;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Визуализирует карту в горизонтальном срезе
void printSliceMap(int (&minecraft)[DIM1][DIM2][DIM3], int level = (DIM3 - 1)) {
    cout << std::setw(19) << "-----SLICE----" << endl;

    for (auto &line: minecraft) {
        cout << "\t";
        for (auto &cell: line) {
            cout << cell[level - 1] << " ";
        }
        cout << endl;
    }
}

// Возвращает введенную пользователем цифру
int getUserDigit() {
    int input = 0;

    // Пока не будет введено нормальное число, выполняем цикл
    while (!(cin >> input)) {
        cout << "Error. Enter a number: ";
        // Сбрасываем коматозное состояние cin
        cin.clear();
        // Очищаем поток ввода
        fflush(stdin);
    }

    return input;
}
int getSlice() {
    while (true) {
        cout << "Enter the number (1 - " << (DIM3 - 1) << ") ";
        cout << "to make a slice in the map: ";
        int input = getUserDigit();

        if (input >= 1 && input < DIM3) {
            return input;
        }

        cout << "Error. Try again" << endl;
    }
};

// Возвращает результат пользовательского ввода
void setHeight(int (&userInput)[DIM1][DIM2]) {
    for (size_t i = 0; i < DIM1; ++i) {
        for (size_t j = 0; j < DIM2; ++j) {
            while (true) {
                cout << "Enter value (0 - " << (DIM3 - 1) << ") ";
                cout << "for the cell " << j << " on line " << i << ": ";
                int input = getUserDigit();

                if (input >= 0 && input < DIM3) {
                    userInput[i][j] = input;
                    break;
                }

                cout << "Error. Try again" << endl;
            }
        }
    }
}

// Возвращает уже готовую версию для тестирования. Без пользовательского ввода
void setHeightForTest(int (&userInput)[DIM1][DIM2]) {
    int test[DIM1][DIM2] = {
            {5, 5, 5, 6, 1},
            {4, 4, 4, 4, 1},
            {3, 2, 2, 3, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
    };

    for (size_t i = 0; i < DIM1; ++i) {
        for (size_t j = 0; j < DIM2; ++j) {
            userInput[i][j] = test[i][j];
        }
    }
}

int main() {
    // true исключит пользовательский ввод и приведет к простому тестированию
    bool test = false;

    int minecraftMap[DIM1][DIM2][DIM3] = {0};
    int heights[DIM1][DIM2] = {0};

    test ? setHeightForTest(heights) : setHeight(heights);

    setHeightToMap(minecraftMap, heights);

    printMap(minecraftMap);

    printSliceMap(minecraftMap, getSlice());
}
