#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 
* @brief считывает целое значение с клавиатуры в проверкой ввода
* @return возвращает считанное значение
*/
int getValue();
/*
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();
/*
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);
/*
 * @brief рассчитывает сумму членов последовательности, с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);
/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);
/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief расчитывает факториал числа
 * @param k - заданное число
 * @return расчитывает значение
*/
long factorial(const int k);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */

int main()
{
    printf("Введите n:");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.4lf\n",
                        n,getSumN(n));
    printf("Введите e:");
    double e = getDouble();
        checkPositive(e);
        printf("Сумма последовательности с точностью "
                "%lf равна %.4lf\n",
                        e,getSumE(e));
    return 0;
}
int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}
double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}
double getSumN(const int n)
{
    double current = -1;
    double result = current;
    for (int i = 1; i < n; i++ )
    {
        current *= getRecurent(i);
        result += current;
    }
    return result;
}
void checkPositive(const double value)
{
    if (!value > 0)
    {
        printf("Error\n");
        exit(1);
    }
}
double getRecurent(const int i)
{
    return pow(-1,i)/factorial(2*i);
}
double getSumE(const double e)
{
    double current = -1;
    double result = 0;
    for (int i = 1; fabs(current) > e; i++)
    {
        result += current;
        current = getRecurent(i);
    }
    return result;
}
long factorial(const int k)
{
    if (k == 0) return 1;
    int result = 1;
    for (int a = 1; a<=k; a++)
    {
        result *= a;
    }
    return result;
}