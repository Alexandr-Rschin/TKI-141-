#include <stdio.h>
#include <math.h>


/**
* @brief Расчитывает площадь поверхности грани куба
* @param a - значение параметра a
* @return рассчитанное значение
*/
double SEdge(double a);

/**
 * @brief Расчитывает площадь поверхности всех граней куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SEveryoneEdge(double a);

/**
 * @brief Расчитывает объём куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double V(double a);


/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main() {
    double a;
    scanf_s("%lf", &a);

    printf("SEdge = %lf\n", SEdge(a));
    printf("SEveryoneEdge = %lf\n", SEveryoneEdge(a));
    printf("V = %lf\n", V(a));
    return 0;
}

double SEdge(double a)
{
    return a * a;

}

double SEveryoneEdge(double a)
{
    return a * a * 6;

}

double V(double a)
{
    return a * a * a;

}