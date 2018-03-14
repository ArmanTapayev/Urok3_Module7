#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include "Header.h"


/* Заполнение целочисленного массива */
void fillArrayInteger(int * mas, int *len, int *min, int *max)
{
	for (int i = 0; i < *len; i++)
		*(mas+i) = rand() * (*max - *min) / RAND_MAX + *min;
}

/* Вывод на печать целочисленного массива*/
void printArray(int *mas, int *len)
{
	printf("Исходный массив:\n");
	for (int i = 0; i < *len; i++)
		printf("A[%d]=%d; ", i, *(mas+i));
	printf("\n");
}

/* Проверка на четность/нечетность */
bool evennessCheck(int *number)
{
	bool flag;

	*number % 2 == 0 ? flag = 1 : flag = 0;

	return flag;
}

/*Определение простого числа*/
bool primeNumber(int *number)
{
	bool flag = 1;
	for (int i = 2; i <= *number / 2; ++i)
	{
		if (*number%i == 0)
		{
			flag = 0;
			break;
		}

	}
	return flag;
}

/* Проверка числа на совершенность */
bool perfectNumber(int number)
{
	int sum = 1;
	bool flag = 0;
		for (int i = 2; i <= number / 2; ++i)
		{
			if (number%i == 0)
				sum += i;
		}

		if(sum==number)
			flag=1;

		return flag;
}

/* Максимальный элемент массива */
void maxElement(int *mas, int *len)
{
	int max = *mas, index;
	for (int i = 0; i < *len; i++)
	{
		if (*(mas + i) > max)
		{
			max = *(mas + i);
			index = i;
		}
	}	
	printf("Максимальный элемент: A[%d]=%d; ", index, max);
}

/* Перевод цифр числа в массив */
void getNumber(int *arr1, int len, int number)
{
	if (len >= 0 && number>0)
	{
		arr1[len - 1] = number % 10;
		number /= 10;
		getNumber(arr1, len - 1, number);
	}

}

/* Нахождение счастливого числа */
bool luckyNumber(int number)
{
	int arr[6], len = 6, sum1=0, sum2=0;
	bool flag = 0;

	getNumber(arr, len, number);

		for (int i = 0; i < len; i++)
		{
			if (i < 3) sum1 += *(arr + i);
			else sum2 += *(arr + i);
		}

		if (sum1 == sum2)
			flag = 1;

	return flag;
}