#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
/**
*@brief Проверяет пройдет ли кирпич через отверстие
*@param x первая сторона кирпича
*@param y вторая сторона кирпича
*@param z третья сторона кирпича
*@param r первая сторона отверстия
*@param s вторая сторона отверстия
*@return Возвращает рассчитанную проверку
*/
bool func(const double x, const double y, const double z, const double r, const double s);
/**
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double value();
/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkvalue(const double value);
/**
*@brief Точка входа в программу
*@param x выбранный вользователем значение первой стороны кирпича
*@param y выбранный вользователем значение второй стороны кирпича
*@param z выбранный вользователем значение третьей стороны кирпича
*@param r выбранный вользователем значение первой стороны отверстия
*@param s выбранный вользователем значение второй стороны отверстия
*@return вовзвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Введите значение стороны кирпича x:");
    double x = value();
    checkvalue(x);
    printf("Введите значение стороны кирпича y:");
    double y = value();
    checkvalue(y);
    printf("Введите значение стороны кирпича z:");
    double z = value();
    checkvalue(z);
    printf("Введите значение стороны отверсия r:");
    double r = value();
    checkvalue(r);
    printf("Введите значение стороны отверстия s:");
    double s = value();
    checkvalue(s);
    if (func(x, y, z, r, s))
    {
        printf("Кирпич пройдет через отверстие!\n");
    }
    else
    {
        printf("Кирпич не пройдет через отверстие!\n");
    }
    return 0;

}
bool func(const double x, const double y, const double z, const double r, const double s)
{
    return (x <= r && y <= s) || (x <= s && y <= r) || (y <= r && z <= s) || (y <= s && z <= r) || (x <= r && z <= s) || (x <= s && z <= r);
}
double value()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return value;
}
void checkvalue(const double value)
{
    if (value <= 0 + DBL_EPSILON)
    {
        printf("Число должно быть положительным!\n");
        abort();
    }
}
