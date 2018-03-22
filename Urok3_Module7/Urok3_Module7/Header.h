#pragma once

/* Заполнение целочисленного массива */
void fillArrayInteger(int *mas, int *len, int *min, int *max);

/* Вывод на печать целочисленного массива*/
void printArray(int *mas, int *len);

/*Пузырьковая сортировка*/
void BubleSort(int *arr, int *len);

// Линейный поиск
void LineSearch(int *arr, int *len, int *key);

//Бинарный поиск
void BinarySearch(int *arr, int *len, int *key);

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

// Задание 1
void thirdArraySort(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);

// Задание 2
void thirdArrayEvennes(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);

// Задание 3
void thirdArrayArr1notArr2(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);
int thirdArrayArr1notArr2Int(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);

// Задание 4
void thirdArrayArr2notArr1(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);

// Задание 5
void thirdArrayTotal(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int *arr6, int len1, int len2, int len3);

// Задание 10
short analogDigitalNumber(short x);

// Задание 12
void sumArray(int *arr1, int *arr2, int *arr3, int len);
