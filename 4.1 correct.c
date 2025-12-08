#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
#include <errno.h> 

/**
* @brief считывает целое значение с клавиатуры в проверкой ввода
* @return возвращает считанное значение
*/
int Value();

/**
* @brief считывает размер с клавиатуры с проверкой ввода и корректности значения
* @param message сообщение для пользователя, которое выводится перед вводом
* @return возвращает считанное значение типа size_t
*/
size_t getSize(const char* message);

/**
* @brief заполняет массив числами, введенными с клавиатуры
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void fillArray(int* arr, const size_t size);

/**
* @brief выводит наш массив
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void printArray(const int* arr, const size_t size);

/**
* @brief заполняет массив случайнвми числами
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void fillRandom(int* arr, const size_t size);

/**
* @brief находит четные, по модулю не превосходящие 5 числа и перемножяет их
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void findChetElementsMoreFive(const int* arr, const size_t size);

/**
* @brief создает копию массива
* @param arr указатель на исходный массив
* @param size размер массива
* @return указатель на новый массив - копию
*/
int* copyArray(const int* arr, const size_t size);

/**
* @brief находит нечетные, по модулю превосходящие параметр А числа и считает их количество
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void EX2(const int* arr, const size_t size, const int A);

/**
* @brief находит нечетные, кратные трем элементы и умножает их значение на порядковый номер
* @param arr указатель на массив для заполнения
* @param size размер массива
*/
void EX3(int* arr, const size_t size);

/**
* @param RANDOM - заполняет массив случайными числами
* @param MANUAL - заполняет массив числами введенными с клавиатуры
*/
enum { RANDOM = 1, MANUAL = 2 };

/**
 * @brief точка входа в программу
 * @return 0 - успех
 */
int main()
{
    srand((unsigned int)time(NULL));

    printf("Введите константный параметр A : ");
    const int A = Value();

    const size_t size = getSize("Введите размер массива: ");
    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        perror("Ошибка выделения памяти");
        return 1;
    }

    printf("Выберите способ заполнения массива:\n"
        "%d случайными числами, %d вручную: ", RANDOM, MANUAL);
    const int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        fprintf(stderr, "Ошибка: Неверный выбор способа заполнения.\n");
        free(arr);
        return 1;
    }

    printf("\n--- Исходный массив ---\n");
    printArray(arr, size);

    findChetElementsMoreFive(arr, size);
    EX2(arr, size, A);
    EX3(arr, size);

    int* copyArr = copyArray(arr, size);
    if (copyArr == NULL) {
        perror("Ошибка выделения памяти для копии");
        free(arr);
        return 1;
    }

    printf("\n--- Скопированный массив (состояние после EX3) ---\n");
    printArray(copyArr, size);

    free(arr);
    free(copyArr);

    return 0;
}

int Value()
{
    int value;
    if (scanf("%d", &value) != 1)
    {
        fprintf(stderr, "Ошибка ввода: Введено не целое число.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        exit(EXIT_FAILURE);
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return value;
}

size_t getSize(const char* message)
{
    printf("%s", message);
    const int value = Value();

    if (value <= 0)
    {
        fprintf(stderr, "Ошибка: Размер массива должен быть положительным числом (> 0).\n");
        exit(EXIT_FAILURE);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент arr[%zu] = ", i);
        *(arr + i) = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    printf("Диапазон: start = ");
    const int start = Value();
    printf("Диапазон: end = ");
    const int end = Value();

    if (start > end) {
        fprintf(stderr, "Ошибка: Начало диапазона (%d) не может быть больше конца (%d).\n", start, end);
        exit(EXIT_FAILURE);
    }

    const int range = end - start + 1;
    if (range <= 0) {
        fprintf(stderr, "Ошибка: Неверный диапазон (start=%d, end=%d).\n", start, end);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        *(arr + i) = (rand() % range) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = (int*)malloc(sizeof(int) * size);
    if (copyArr == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
    {
        *(copyArr + i) = *(arr + i);
    }

    return copyArr;
}

void findChetElementsMoreFive(const int* arr, const size_t size)
{
    long long result = 1;
    int found_count = 0;

    printf("\n--- Задание 1: Четные, по модулю не превосходящие 5 ---\n");
    for (size_t i = 0; i < size; i++)
    {
        const int current_val = *(arr + i);
        if (current_val % 2 == 0 && abs(current_val) <= 5)
        {
            printf("Найден элемент: %d (индекс %zu)\n", current_val, i);
            result *= current_val;
            found_count++;
        }
    }

    if (found_count > 0)
    {
        printf("Произведение найденных элементов: %lld\n", result);
    }
    else
    {
        printf("Подходящие элементы не найдены.\n");
    }
}

void EX2(const int* arr, const size_t size, const int A)
{
    int count = 0;
    int found = 0;

    printf("\n--- Задание 2: Нечетные, по модулю превосходящие %d ---\n", A);
    for (size_t i = 0; i < size; i++)
    {
        const int current_val = *(arr + i);
        if (current_val % 2 != 0 && abs(current_val) > A)
        {
            printf("Найден элемент: %d (индекс %zu)\n", current_val, i);
            count++;
            found = 1;
        }
    }

    if (found)
    {
        printf("Количество найденных элементов: %d\n", count);
    }
    else
    {
        printf("Подходящие элементы не найдены.\n");
    }
}

void EX3(int* arr, const size_t size)
{
    int found = 0;

    printf("\n--- Задание 3: Умножение нечетных, кратных 3 на порядковый номер ---\n");
    printf("Массив до изменения: ");
    printArray(arr, size);

    for (size_t i = 0; i < size; i++)
    {
        if (*(arr + i) % 3 == 0 && *(arr + i) % 2 != 0)
        {
            const int originalARR = *(arr + i);
            *(arr + i) *= (i + 1);

            printf("Изменен элемент arr[%zu]: %d * (%zu + 1) -> %d\n", i, originalARR, i, *(arr + i));
            found = 1;
        }
    }

    if (found)
    {
        printf("Массив после изменения: ");
        printArray(arr, size);
    }
    else
    {
        printf("Нечетные элементы, кратные 3, не найдены.\n");
    }
}