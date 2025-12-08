#include "stdio.h"
#include "math.h"
#include "stdlib.h"

/**
* @brief Проверка введённого значения
* @return Возвращает значение если ввод правильный, иначе выводит сообщение об ошибке/
*/
float get_input();

/**
 * @brief Функция для вычисления среднего арифметического кубов двух чисел
 * @param a Первое число
 * @param b Второе число
 * @return Среднее арифметическое кубов
 */
float get_mean_arith(float a, float b);

/**
 * @brief Функция для вычисления среднего геометрического модулей двух чисел
 * @param a Первое число
 * @param b Второе число
 * @return Среднее геометрическое модулей
 */
float get_mean_geom(float a, float b);

/**
 * @brief Точка входа в программу
 * @return Выводит 0 в случае успеха, иначе 1
 */
int main() {
    puts("Введите два числа: ");

    float number1 = get_input();
    float number2 = get_input();

    printf("Среднее арифметическое кубов: %f\n"
        "Среднее геометрическое модулей: %f\n",
        get_mean_arith(number1, number2), get_mean_geom(number1, number2));

    return 0;
}

float get_input() {
    float input;

    if (scanf_s("%f", &input) != 1) {
        puts("Ошибка ввода");
        exit(EXIT_FAILURE);
    }

    return input;
}

float get_mean_arith(float a, float b) {
    return (pow(a, 3) + pow(b, 3)) / 2;
}

float get_mean_geom(float a, float b) {
    return sqrtf(fabs(a * b));
}