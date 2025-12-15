#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf  
/**
 * @brief Считывает значение, введеное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int Value(void);
/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);
/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr, const size_t size);
/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(const int* arr, const size_t size);
/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);
/**
 * @brief Заполнение массива случайными числами
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param size Размер массива
 * @return Полученный массив
 */
int* copyArray(const int* arr, const size_t size);
/**
 * @brief Заменяет предпоследний элемент массива на элемент с максимальным по модулю значением
 * @param copyArr Массив, в котором выполняется замена
 * @param size Размер массива
 * @return 1, если замена выполнена успешно, иначе 0
 */
int replaceAbs(int* copyArr, const size_t size);
/**
 * @brief Вставляет элемент со значением K до и после всех элементов, которые оканчиваются на цифру K
 * @param copyArr Исходный массив
 * @param size Размер массива
 * @return 1, если хотя бы один элемент был изменён, 0 если замены не произошло
 */
int insertK(const int* copyArr, const size_t size);
/**
 * @brief Формирует новый массив A той же длины, что и D по правилу
 * @param copyArr Исходный массив D
 * @param size Размер массива
 * @return 1, если массив A успешно сформирован, 0 если не сформирован
 */
int fromDtoA(const int* copyArr, const size_t size);
/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную.
 */
enum { RANDOM = 1, MANUAL };
/**
 * @brief Точка входа в программу.
 * @return 0, если программа выполнена корректно.
 */
int main(void)
{
    size_t size = getSize("Введите размер массива: ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка!\n");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами\n"
        "%d - вручную\n"
        "Введите нужный номер заполнения: ",
        RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("Ошибка!\n");
        free(arr);
        exit(1);
    }
    printArray(arr, size);
    int* copyArr = copyArray(arr, size);
    replaceAbs(copyArr, size);
    printArray(copyArr, size);
    printf("\n");
    insertK(arr, size);
    printf("\n");
    fromDtoA(arr, size);
    printf("\n");
    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка, введено неверное значение!\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Ошибка!");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите a[%zu] = ", i);
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    printf("Текущий массив: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Ошибка!\n");
        exit(1);
    }
}

void fillRandom(int* arr, const size_t size)
{
    printf("Введите начало диапазона случайных чисел: ");
    int start = Value();
    printf("Введите конец диапазона случайных чисел: ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL)
    {
        printf("Ошибка!\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceAbs(int* copyArr, const size_t size)
{
    if (size < 2)
    {
        abort();
    }
    size_t indexMax = 0;
    int maxAbs = abs(copyArr[0]);
    for (size_t i = 1; i < size; i++)
    {
        int curAbs = abs(copyArr[i]);

        if (curAbs > maxAbs)
        {
            maxAbs = curAbs;
            indexMax = i;
        }
    }
    copyArr[size - 2] = copyArr[indexMax];
    return 1;
}

int insertK(const int* copyArr, const size_t size)
{
    printf("Введите значение K: ");
    int K = Value();
    int lastDigitK = abs(K) % 10;
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        int lastDigit = abs(copyArr[i]) % 10;
        if (lastDigit == lastDigitK)
        {
            count++;
        }
    }
    if (count == 0)
    {
        printf("Элементов, оканчивающихся на цифру %d, нет.\n", lastDigitK);
        abort();
    }
    size_t newSize = size + 2 * count;
    int* newArr = malloc(newSize * sizeof(int));
    if (newArr == NULL)
    {
        printf("Ошибка!\n");
        exit(1);
    }
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        int lastDigit = abs(copyArr[i]) % 10;
        if (lastDigit == lastDigitK)
        {
            newArr[j++] = K;
            newArr[j++] = copyArr[i];
            newArr[j++] = K;
        }
        else
        {
            newArr[j++] = copyArr[i];
        }
    }
    printArray(newArr, newSize);

    free(newArr);
    return 1;
}

int fromDtoA(const int* copyArr, const size_t size)
{
    if (size == 0)
    {
        printf("Массив D пуст, нельзя сформировать новый массив!\n");
        abort();
    }
    int* A = malloc(size * sizeof(int));
    if (A == NULL)
    {
        printf("Ошибка!\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        size_t number = i + 1;
        if (number % 2 == 0)
        {
            int Di2 = copyArr[i] * copyArr[i];
            A[i] = (int)number * Di2;
        }
        else
        {
            if (number == 1)
            {
                A[i] = 0;
            }
            else
            {
                A[i] = copyArr[i] / (int)(number - 1);
            }
        }
    }
    printArray(A, size);
    free(A);
    return 1;
}