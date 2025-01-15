#include <iostream>
#include "Header.h"
#include <cctype>
#include <string>
const int MAX_DIGITS = 1000;
using namespace std;

// ������� ��� ��������� ������� �����
void multiply(int* num1, int num2, int* result, int& result_size) {

    int carry = 0;
    for (int i = 0; i < result_size; i++) {
        int product = num1[i] * num2 + carry;
        result[i] = product % 10; // ��������� ��������� �����
        carry = product / 10;      // �������� �������
    }
    //��������� ��������
    while (carry) {
        result[result_size] = carry % 10;
        carry /= 10;
        result_size++;
    }

}

//������� ��� ���������� � �������
void pow(int x, int n, int* result, int& result_size)
{
    result[0] = 1; // ��������� �������� - 1
    result_size = 1;

    for (int i = 0; i < n; i++)
    {
        multiply(result, x, result, result_size);
    }
}

// ������� ��� �������� ������� �����
void add(int* num1, int size1, int* num2, int size2, int* result, int& result_size) {
    int carry = 0;
    result_size = max(size1, size2);

    for (int i = 0; i < result_size || carry; ++i) {
        if (i < size1) carry += num1[i];
        if (i < size2) carry += num2[i];
        result[i] = carry % 10;
        carry /= 10;
    }

    while (result_size > 1 && result[result_size - 1] == 0) {
        result_size--; // �������� ������� �����
    }

}



// �������� ������� ��� ���������� �����
void sumOf(int n)
{
    int sum[MAX_DIGITS] = { 0 }; // ������ ��� �������� �����
    int sum_size = 1; // ���������� ����� ����� 0 (1 �����)

    for (int i = 1; i <= n; ++i) {
        int current_power[MAX_DIGITS] = { 0 }; // ������ ��� ������� �������
        int current_power_size;

        pow(i, n, current_power, current_power_size); // ���������� � �������
        add(sum, sum_size, current_power, current_power_size, sum, sum_size); // ��������
    }

    // ����� ����������
    cout << "����� 1^" << n << " + 2^" << n << " + ... + " << n << "^" << n << " = ";
    for (int i = sum_size - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;
}


