#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include "Header.h"


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n;
		do
		{
			printf("Работа содержит 13 заданий.\n");
			printf("Для выхода наберите 0.\n");
			printf("Введите номер задания: ");
			scanf("%d", &n);
			printf("\n");

				switch (n)
				{
					case 1:
					{
						/*1. Даны два массива, упорядоченных по возрастанию: А[n] и B[m].
						Сформируйте массив C[n+m], состоящий из элементов массивов А и В, 
						упорядоченный по возрастанию (Массив С не должен сортироваться).*/

						int A[6], B[10], C[16], lenA=6, lenB=10, lenC=16, min=10, max=50;

						
						fillArrayInteger(A, &lenA, &min, &max);						
						fillArrayInteger(B, &lenB, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &lenA);
						printf("\nИсходный массив B:\n");
						printArray(B, &lenB);

						printf("\nОтсортированный массив А:\n");
						BubleSort(A, &lenA);
						printf("\n");
						printf("\nОтсортированный массив В:\n");
						BubleSort(B, &lenB);

						printf("\n");
						printf("\nМассив C[n+m], состоящий из элементов массивов А и В, упорядоченный по возрастанию\n");						
						thirdArraySort(A, B, C, lenA, lenB, lenC);
						printArray(C, &lenC);

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 2:
					{
						/*2. Даны два массива : А[n] и B[m]. Необходимо создать третий массив, 
						в котором нужно собрать общие элементы двух массивов.*/

						int A[6], B[10], C[6] = {}, lenA = 6, lenB = 10, lenC = 6, min = 10, max = 50;

						fillArrayInteger(A, &lenA, &min, &max);
						fillArrayInteger(B, &lenB, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &lenA);
						printf("\nИсходный массив B:\n");
						printArray(B, &lenB);

						printf("\nОтсортированный массив А:\n");
						BubleSort(A, &lenA);
						printf("\n");
						printf("\nОтсортированный массив В:\n");
						BubleSort(B, &lenB);

						printf("\n");
						thirdArrayEvennes(A, B, C, lenA, lenB, lenC);
						
						printf("\nОбщие элементы двух массивов:\n");
						for (int i = 0; i < lenC; i++)
						{
							if(*(C+i)!=0)
							printf("%d; ", *(C + i));
						}

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 3:
					{
						/*3. Даны два массива : А[n] и B[m]. Необходимо создать третий массив,
						в котором нужно собрать элементы массива A, которые не включаются в B.*/

						int A[6], B[10], C[16] = {}, lenA = 6, lenB = 10, lenC = 16, min = 10, max = 50;

						fillArrayInteger(A, &lenA, &min, &max);
						fillArrayInteger(B, &lenB, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &lenA);
						printf("\nИсходный массив B:\n");
						printArray(B, &lenB);

						printf("\nОтсортированный массив А:\n");
						BubleSort(A, &lenA);
						printf("\n");
						printf("\nОтсортированный массив В:\n");
						BubleSort(B, &lenB);

						printf("\n");
						thirdArrayArr1notArr2(A, B, C, lenA, lenB, lenC);

						printf("\nЭлементы массива А, которые не включаются в массив B:\n");

						for (int i = 0; i < lenC; i++)
						{
							if (*(C + i) != 0)
								printf("%d; ", *(C + i));
						}

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 4:
					{
						/*4. Даны два массива : А[n] и B[m]. Необходимо создать третий массив, 
						в котором нужно собрать элементы массива B, которые не включаются в A.*/

						int A[6], B[10], C[16] = {}, lenA = 6, lenB = 10, lenC = 16, min = 10, max = 50;

						fillArrayInteger(A, &lenA, &min, &max);
						fillArrayInteger(B, &lenB, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &lenA);
						printf("\nИсходный массив B:\n");
						printArray(B, &lenB);

						printf("\nОтсортированный массив А:\n");
						BubleSort(A, &lenA);
						printf("\n");
						printf("\nОтсортированный массив В:\n");
						BubleSort(B, &lenB);

						printf("\n");
						thirdArrayArr2notArr1(A, B, C, lenA, lenB, lenC);

						printf("\nЭлементы массива B, которые не включаются в массив A:\n");

						for (int i = 0; i < lenC; i++)
						{
							if (*(C + i) != 0)
								printf("%d; ", *(C + i));
						}

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 5:
					{
						/*5. Даны два массива : А[n] и B[m]. Необходимо создать третий массив, 
						в котором нужно собрать элементы массивов A и B, которые не являются общими для них.*/

						int A[6], B[10], C[16] = {}, lenA = 6, lenB = 10, lenC = 16, min = 10, max = 50;

						fillArrayInteger(A, &lenA, &min, &max);
						fillArrayInteger(B, &lenB, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &lenA);
						printf("\nИсходный массив B:\n");
						printArray(B, &lenB);

						printf("\nОтсортированный массив А:\n");
						BubleSort(A, &lenA);
						printf("\n");
						printf("\nОтсортированный массив В:\n");
						BubleSort(B, &lenB);
						
						thirdArrayTotal(A, B, C, A, B, C, lenA, lenB, lenC);
						
						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 6:
					{
						/*1. *Напишите функцию, которая принимает одномерный массив целых чисел и заполняет его случайными числами.*/
						int A[10], len = 10, minN =10, maxN = 100;

						fillArrayInteger(A, &len, &minN, &maxN);

						printf("Функция, которая принимает одномерный массив целых чисел и заполняет его случайными числами:\n");
						printArray(A, &len);

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 7:
					{
						/*2. *Напишите функцию, которая принимает число и возвращает истину, 
						если число четное и ложь, если нечетное.*/
						int n;
						printf("Введите число для проверки на четность: ");
						scanf("%d", &n);

						if (evennessCheck(&n))
							printf("Число четное.");
						else
							printf("Число нечетное.");

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 8:
					{
						/*3. **Написать функцию, которая возвращает истину, 
						если переданное число простое, и ложь, если не простое. 
						Простое число – это число, которое делиться ТОЛЬКО на 1 и на себя (2, 5, 7, 11 и т.д.).*/

						int n;
						printf("Введите число для проверки является ли оно простым: ");
						scanf("%d", &n);

						if (primeNumber(&n))
							printf("Число простое.");
						else
							printf("Число не является простым.");

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 9:
					{
						/*4. ***Число называется совершенным, если сумма всех его делителей равна ему самому. 
						Напишите функцию поиска таких чисел во введенном интервале.*/
						int n1, n2;
						printf("Проверка является ли число совершенным.\n");
						printf("Введите первое число интервала: ");
						scanf("%d", &n1);
						printf("Введите последнее число интервала: ");
						scanf("%d", &n2);

							for (int i = n1; i < n2; i++)
							{
								if (perfectNumber(i))
									printf("Число %d является совершенным.\n", i);
							}
								
						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 10:
					{
						/*5. **Написать функцию, которая возвращает истину, если переданный параметр является
						алфавитно-цифровым и ложь, если не является.*/

						char x;
						short b, result=0;

						printf("Введите символ: ");
						scanf(" %c", &x);

						b = (short)x;

						printf("Номер введенного символа: %d\n", b);

						result=analogDigitalNumber(b);
						if (result)
							printf("Переданный параметр является алфавитно - цифровым");
						else
							printf("Переданный параметр не является алфавитно - цифровым");
								
						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 11:
					{
						/*6. **Написать функцию, которая принимает одномерный массив целых чисел и возвращает 
						значения максимального числа в этом массиве.*/
						int A[10], len = 10, minN = 10, maxN = 100;

						fillArrayInteger(A, &len, &minN, &maxN);
						printArray(A, &len);
						maxElement(A, &len);

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 12:
					{
						/*7. **Напишите функцию, которая принимает три массива целых чисел.
						Выполнить поэлементное сложение элементов первых двух массивов, и результат занести в третий массив.*/

						int A[10], B[10], C[10] = {}, len = 10, min = 10, max = 50;

						fillArrayInteger(A, &len, &min, &max);
						fillArrayInteger(B, &len, &min, &max);

						printf("Исходный массив А:\n");
						printArray(A, &len);
						printf("\nИсходный массив B:\n");
						printArray(B, &len);

						printf("\nПоэлементное сложение элементов первых двух массивов:\n");
						sumArray(A, B, C, len);

						printf("\n");
						system("pause");
						system("cls");

					}break;

					case 13:
					{
						/*8. **Написать функцию, которая принимает целое шестизначное число и проверяет
						равна ли сумма первых трех цифр сумме последних трех цифр(счастливый билет).
						Функция возвращает истину, если число счастливое (суммы равны) и ложь, если не счастливое (суммы не равны).*/

						int n;
						printf("Введите число: ");
						scanf("%d", &n);

						if (luckyNumber(n))
							printf("Число счастливое.");
						else
							printf("Число не счастливое.");

						printf("\n");
						system("pause");
						system("cls");

					}break;

		
				}
		} while (n != 0);
}

