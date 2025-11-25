#include <stdio.h>
#include <math.h>

/**
 * @brief Расчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y -значение парметра y
 * @param z- значение параметра z
 * @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);
/**
 * @brief Расчитывает функцию B по заданной формуле
 * @param x - значение параметра x
 * @param y -значение парметра y
 * @param z- значение параметра z
 * @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);
/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */

int main() {
    const double x = 2.2;
    const double y = 9.2;
    const double z = 10.2;
    printf("A = %lf\n", getA(x, y, z));
    printf("B = %lf\n", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (log(log(z + pow(x, 2))) + (x / y));

}

double getB(const double x, const double y, const double z)
{
    return (exp(-z) * ((x + (sqrt(x + z))) / (x - (sqrt(fabs(x - y))))));

}
