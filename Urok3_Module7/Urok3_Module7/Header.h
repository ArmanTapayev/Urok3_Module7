#pragma once

/* Заполнение целочисленного массива */
void fillArrayInteger(int *mas, int *len, int *min, int *max);

/* Вывод на печать целочисленного массива*/
void printArray(int *mas, int *len);

/* Проверка на четность/нечетность */
bool evennessCheck(int *number);

/*Определение простого числа*/
bool primeNumber(int *number);

/* Проверка числа на совершенность */
bool perfectNumber(int number);

/* Максимальный элемент массива */
void maxElement(int *mas, int *len);

/* Перевод цифр числа в массив */
void getNumber(int *arr1, int len, int number);

/* Нахождение счастливого числа */
bool luckyNumber(int number);