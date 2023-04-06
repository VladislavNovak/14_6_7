#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

const unsigned int DIM1 = 4;
const unsigned int DIM2 = 4;
const unsigned int DIM3 = 10;

// Визуализирует всю карту в поперечном срезе
void printMap(int (&minecraft)[DIM1][DIM2][DIM3]) {
    cout << std::setw(20) << "-----MAP----" << endl;

    cout << "level:  ";
    for (int i = 0; i < DIM3; ++i) cout << std::setw(2) << i;
    cout << "\n\t" << endl;
    for (auto & line : minecraft) {
        for (auto & cell : line) {
            cout << "\t";
            for (int stage : cell) {
                if (!stage) break;
                cout << std::setw(2) << stage;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Визуализирует карту в горизонтальном срезе
void printSliceMinecraft(int (&minecraft)[DIM1][DIM2][10], int level = (DIM3 - 1)) {
    cout << std::setw(18) << "-----SLICE----" << endl;

    for (auto & line : minecraft) {
        cout << "\t";
        for (auto & cell : line) {
            cout << cell[level - 1] << " ";
        }
        cout << endl;
    }
}

int main() {
    int minecraft[DIM1][DIM2][DIM3] = { 0 };
    int vec[DIM1][DIM2] = {
            {5, 5, 5, 6},
            {4, 4, 4, 4},
            {3, 2, 2, 3},
            {0, 1, 1, 1},
    };

    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            int currentValue = vec[i][j];
            for (int k = 0; k < currentValue; k++) {
                minecraft[i][j][k] = 1;
            }
        }
    }

    printMap(minecraft);

    printSliceMinecraft(minecraft, 1);
}
