#include <iostream>
#include <Windows.h>
#include <cctype>
#include <string>
#include "Header.h"
using namespace std;

bool IsNumber(string& n_str) {
    for (char ch : n_str) {
        if (!isdigit(ch)) { // проверка является ли символ цифрой
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string n_str;
    int n = 0;
    cout << "Вычисление суммы ряда: 1^n + 2^n + ... + n^n" << endl;

    while (true) {
        cout << "Введите значение n: ";
        cin >> n_str;
        if (IsNumber(n_str)) {
            n = stoi(n_str);
            if (n >= 10) {
                break;
            }
        }
        cout << "Введено неверное значение n. Повторите ввод." << endl;
    }

    sumOf(n); // подсчёт суммы ряда при помощи функции 

    return 0;
}