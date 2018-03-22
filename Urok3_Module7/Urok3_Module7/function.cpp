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
	//printf("Исходный массив:\n");
	for (int i = 0; i < *len; i++)
		printf("%d; ", *(arr + i));
	printf("\n");
}

/*Пузырьковая сортировка*/
void BubleSort(int *arr, int *len)
{
	//printf("\nМассив после сортировки:\n");

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

		printf("%d; ", *(arr + i ));
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
			printf("\nЭлемент arr[%d]=%d найдем за %d проходов.\n", i, *(arr + i), i);
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
		printf("\nЭлемент arr[%d]=%d найдем за %d проходов.\n", search, *(arr+search), count);

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
	printf("Максимальный элемент: max[%d]=%d; ", index, max);
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


/* Задание 1. Даны два массива, упорядоченных по возрастанию: А[n] и B[m].
Сформируйте массив C[n+m], состоящий из элементов массивов А и В,
упорядоченный по возрастанию (Массив С не должен сортироваться).*/

void thirdArraySort(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{	
	int i = 0, j = 0, k = 0;
	
		while ((i < len1 && j < len2)) // при этом не все элементы попадут в третий массив
		{

			if (*(arr1+i) <= *(arr2+j))
			{
				*(arr3+k) = *(arr1+i);
				i++;
				k++;
			}
			else if (*(arr1+i) >= *(arr2+j))
			{
				*(arr3 + k) = *(arr2+j);
				j++;
				k++;
			}

		}

		while (i < len1)					// дописываем элементы из массива 1
		{
			*(arr3 + k) = *(arr1 + i);
			i++;
			k++;			
		}

		while (j < len2)					// дописываем элементы из массива 2
		{
			*(arr3 + k) = *(arr2 + j);
			j++;
			k++;
		}

}

/* Задание 2. Даны два массива : А[n] и B[m]. Необходимо создать третий массив,
в котором нужно собрать общие элементы двух массивов.*/

void thirdArrayEvennes(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{
	int k = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (*(arr1 + i) == *(arr2 + j))
			{
				*(arr3 + k) = *(arr1 + i);
				k++;
			}
		}
	}
}


/* Задание 3. Даны два массива : А[n] и B[m]. Необходимо создать третий массив,
в котором нужно собрать элементы массива A, которые не включаются в B.*/

void thirdArrayArr1notArr2(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{
	int k = 0, flag = 1;
	
		for (int i = 0; i < len1; i++)
		{	
			
			for (int j = 0; j < len2; j++)
			{
				if (*(arr1 + i) == *(arr2 + j))
				
					flag = 0;									
			}	

			if (flag)
			{
				*(arr3 + k) = *(arr1 + i);
				k++;					
			}

			flag = 1;		
		}

}

int thirdArrayArr1notArr2Int(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{
	int k = 0, flag = 1;

	for (int i = 0; i < len1; i++)
	{

		for (int j = 0; j < len2; j++)
		{
			if (*(arr1 + i) == *(arr2 + j))

				flag = 0;
		}

		if (flag)
		{
			*(arr3 + k) = *(arr1 + i);
			k++;
		}

		flag = 1;
	}

	return *arr3;
}

/* Задание 4. Даны два массива : А[n] и B[m]. Необходимо создать третий массив,
в котором нужно собрать элементы массива B, которые не включаются в A.*/

void thirdArrayArr2notArr1(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{
	int k = 0, flag = 1;

	for (int j = 0; j < len2; j++)
	{

		for (int i = 0; i < len1; i++)
		{
			if (*(arr1 + i) == *(arr2 + j))

				flag = 0;
		}
		if (flag)
		{
			*(arr3 + k) = *(arr2 + j);
			k++;
		}

		flag = 1;
	}

}


/* Задание 5. Даны два массива : А[n] и B[m]. Необходимо создать третий массив,
в котором нужно собрать элементы массивов A и B, которые не являются общими для них.*/

void thirdArrayTotal(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int *arr6, int len1, int len2, int len3)
{
	int C[16] = {};

	thirdArrayArr1notArr2(arr1, arr2, arr3, len1, len2, len3);

	printf("\n");

	printf("\nЭлементы массива А, которые не включаются в массив B:\n");

		for (int i = 0; i < len3; i++)
		{
			if (*(arr3 + i) != 0)
			{
				*(C+i) = *(arr3 + i);
				printf("%d; ", *(C + i));
			}
				
		}

	int D[16] = {};

	thirdArrayArr2notArr1(arr4, arr5, arr6, len1, len2, len3);

	printf("\n");

	printf("\nЭлементы массива B, которые не включаются в массив A:\n");

		for (int i = 0; i < len3; i++)
		{
			if (*(arr6 + i) != 0)
			{
				*(D + i) = *(arr6 + i);
				printf("%d; ", *(D + i));
			}
		}

		printf("\n");

		printf("\nЭлементы массивов A и B, которые не являются общими для них:\n");
		
		int F[32] = {};
		thirdArraySort(C, D, F, len3, len3, 32);
		for (int i = 0; i < 32; i++)
		{
			if (*(F + i) != 0)
				printf("%d; ", *(F + i));
		}
		printf("\n");
}

/*5. **Написать функцию, которая возвращает истину, если переданный параметр является
алфавитно-цифровым и ложь, если не является.*/

short analogDigitalNumber(short x)
{
	if ((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x >= 97 && x <= 122) || (x >= 192 && x <= 255))
		return 1;
	else
		return 0;
}

/* Напишите функцию, которая принимает три массива целых чисел.
Выполнить поэлементное сложение элементов первых двух массивов, и результат занести в третий массив.*/

void sumArray(int *arr1, int *arr2, int *arr3, int len)
{
	for (int i = 0; i < len; i++)
	{
		*(arr3 + i) = *(arr1 + i) + *(arr2 + i);
		printf("%d; ", *(arr3 + i));
	}
}
