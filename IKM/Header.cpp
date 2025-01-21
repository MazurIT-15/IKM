#include <iostream>
#include "Header.h"
#include <cctype>
#include <string>
const int MAX_DIGITS = 1000;
using namespace std;

// Функция для умножения больших число
void multiply(int* num1, int num2, int* result, int& result_size) {

    int carry = 0;
    int temp[MAX_DIGITS] = { 0 }; // Временный массив для хранения промежуточного результата
    int temp_size = 0;

    // Умножение на единицы
    for (int i = 0; i < result_size; i++) {
        int product = num1[i] * (num2 % 10) + carry;
        temp[i] = product % 10; //сохраняем последнюю цифру
        carry = product / 10; //перенос
    }
    while (carry) {
        temp[result_size] = carry % 10;
        carry /= 10;
        result_size++;
    }
    temp_size = result_size;

    // Умножение на десятки (если num2 двузначное)
    if (num2 >= 10) {
        carry = 0;
        for (int i = 0; i < result_size; i++) {
            int product = num1[i] * (num2 / 10) + carry;
            temp[i + 1] += product % 10; // Сдвиг на один разряд влево
            carry = product / 10;
        }
        while (carry) {
            temp[result_size + 1] = carry % 10;
            carry /= 10;
            result_size++;
        }
        temp_size = result_size + 1;
    }

    // Копирование результата в выходной массив
    for (int i = 0; i < temp_size; i++) {
        result[i] = temp[i];
    }
    result_size = temp_size;

}

//Функция для возведения в степень
void pow(int x, int n, int* result, int& result_size)
{
    result[0] = 1; // Начальное значение - 1
    result_size = 1;

    for (int i = 0; i < n; i++)
    {
        multiply(result, x, result, result_size);// Умножаем результат на x
    }
}

// Функция для сложения больших чисел
void add(int* num1, int size1, int* num2, int size2, int* result, int& result_size) {
    int carry = 0;
    result_size = max(size1, size2);

    for (int i = 0; i < result_size || carry; ++i) {// Проход по всем разрядам
        if (i < size1) carry += num1[i];// Добавляем цифру из первого числа
        if (i < size2) carry += num2[i];// Добавляем цифру из второго числа
        result[i] = carry % 10;
        carry /= 10;
    }

    while (carry) { // Обработка переноса
        result[result_size] = carry % 10;
        carry /= 10;
        result_size++;
    }

    while (result_size > 1 && result[result_size - 1] == 0) {
        result_size--; // Удаление ведущих нулей
    }

}



// Основная функция для вычисления суммы
void sumOf(int n)
{
    int sum[MAX_DIGITS] = { 0 }; // Массив для хранения суммы
    int sum_size = 1; // Изначально сумма равна 0 (1 цифра)

    for (int i = 1; i <= n; ++i) {
        int current_power[MAX_DIGITS] = { 0 }; // Массив для текущей степени
        int current_power_size;

        pow(i, n, current_power, current_power_size); // Возведение в степень
        add(sum, sum_size, current_power, current_power_size, sum, sum_size); // Сложение
    }

    // Вывод результата
    cout << "Сумма 1^" << n << " + 2^" << n << " + ... + " << n << "^" << n << " = ";
    for (int i = sum_size - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;
}


