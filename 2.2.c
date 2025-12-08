#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cfloat>

/*
@brief высчитывает значение y по формуле от значения x
@param x значение x  @param a заданная константа
@return значение y от x 
*/

double getY(const double x, const double a);

/* 
*@brief сичтывает значение, введенное с клавиатуры с проверкой ввода
* @return считанное значение
*/

double getValue(void);

/*
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */

int main(void)
{
    const double a = 2.5;
    printf("Введите x\n");
    double x = getValue();
    printf("%.7g", getY(x, a));
    return 0;
}

double getY(const double x, const double a)
{
    if (0.5 - x > DBL_EPSILON)
    {
        return (sqrt(a * pow(x, 2) + 1));
    }
    else if (fabs(x - 0.5) < DBL_EPSILON)
    {
        return (a * x + 3);
    }
    else
    {
        return (sqrt(pow(a, 2) * x - 1));
    }
}

double getValue(void)
{
    double value = 0;
    if (!scanf("%lg", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}