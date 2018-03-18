#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include "Header.h"


/* Заполнение целочисленного массива */
void fillArrayInteger(int *arr, int *len, int *min, int *max)
{
	for (int i = 0; i < *len; i++)
		*(arr +i) = rand() * (*max - *min) / RAND_MAX + *min;
}

/* Вывод на печать целочисленного массива*/
void printArray(int *arr, int *len)
{
	printf("Исходный массив:\n");
	for (int i = 0; i < *len; i++)
		printf("A[%d]=%d; ", i, *(arr + i));
	printf("\n");
}

/*Пузырьковая сортировка*/
void BubleSort(int *arr, int *len)
{
	printf("\nМассив после сортировки:\n");

	for (int i = 0; i < *len; i++)
	{
		for (int j = (*len - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (*(arr + j-1) > *(arr + j)) // если текущий элемент меньше предыдущего
			{
				int temp = *(arr + j - 1); // меняем их местами
				*(arr + j - 1) = *(arr + j);
				*(arr + j) = temp;
			}
		}

		printf("A[%d]=%d ", i, *(arr + i ));
	}
}

// Линейный поиск
void LineSearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);

	for (int i = 0; i < *len; i++) // просматриваем все элементы в цикле
	{
		if (*(arr + i) == *key)      // если находим элемент со значением key,
		{
			printf("\nЭлемент A[%d]=%d найдем за %d проходов.\n", i, *(arr + i), i);
			break;
		}

	}

}

//Бинарный поиск
void BinarySearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);
	int left = 0; // задаем левую и правую границы поиска
	int right = *len - 1;
	int search = -1; // найденный индекс элемента равен -1 (элемент не найден)
	int count = 0;

	while (left <= right) // пока левая граница не "перескочит" правую
	{
		count++;
		int mid = (left + right) / 2; // ищем середину отрезка

									  // если ключевое поле равно искомому
									  // мы нашли требуемый элемент, выходим из цикла
		if (*key == *(arr + mid))
		{
			search = mid;
			break;
		}


		if (*key < *(arr + mid))     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}

	if (search == -1)     // если индекс элемента по-прежнему -1, элемент не найден
		printf("\nЭлемент не найден!");

	else          // иначе выводим элемент, его ключ и значение
		printf("\nЭлемент A[%d]=%d найдем за %d проходов.\n", search, *(arr+search), count);

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

/* Задание 1 */
void thirdArraySort(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{	
	int i = 0, j = 0, k = 0;
	/*for (int k = 0; k < len3; k++)
	{
		for ( int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (arr2[j] < arr1[i])
					arr3[k] = arr2[j];
				else if(arr2[j] > arr1[i])
					arr3[k] = arr1[i];
			}
		}

	}*/
	while ((i < len1 || j < len2) && k<len3+1)
	{
		if (*(arr1+i)<=*(arr2+j)) //(i < len1 || j < len2)&&
		{
			*(arr3 + k) = *(arr1 + i);
			i++;
			k++;
		}
		else if (*(arr1 + i)>=*(arr2 + j))
		{
			*(arr3 + k) = *(arr2 + j);
			j++;
			k++;
		}

	}
	
}