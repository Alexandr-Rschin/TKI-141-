#include <stdio.h>
#include <math.h>


/
* @brief Расчитывает площадь поверхности грани куба
* @param a - значение параметра a
* @return рассчитанное значение
*/
double SEdge(const double a);

/
 * @brief Расчитывает площадь поверхности всех граней куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SEveryoneEdge(const double a);

/
 * @brief Расчитывает объём куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double V(const double a);


/
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main() {
    double a = 0;
    while (scanf_s("%lf", &a) > 0) {

        printf("SEdge = %lf\n", SEdge(a));
        printf("SEveryoneEdge = %lf\n", SEveryoneEdge(a));
        printf("V = %lf\n", V(a));
        while (getchar() != '\n');
    }

    return 0;
}

double SEdge(const double a)
{
    return a * a;

}

double SEveryoneEdge(const double a)
{
    return a * a * 6;

}

double V(const double a)
{
    return a * a * a;

}
