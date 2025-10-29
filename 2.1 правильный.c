#include <stdio.h>
#include <math.h>


/**
 * @brief Расчитывает площадь поверхности грани куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SEdge(const double a);

/**
 * @brief Расчитывает площадь поверхности всех граней куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SEveryoneEdge(const double a);

/**
 * @brief Расчитывает объём куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double V(const double a);


/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main() {
	const double a = 2;

	printf("A = %lf\n", getA(a));
	printf("B = %lf\n", getB(a));
	printf("C = %lf\n", getC(a));
	return 0;
}

double getA(const double a)
{
	return a * a;

}

double getB(const double a)
{
	return a * a * 6;

}

double getC(const double a)
{
	return a * a * a;

}