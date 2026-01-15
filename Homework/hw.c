#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Объявление структуры поезда
struct train {
    int number;
    char arrival_time[6];    // формат "ЧЧ:ММ"
    char departure_time[6];  // формат "ЧЧ:ММ"
    char direction[50];
    float distance;
};

// Создание псевдонима
typedef struct train Train;

// Прототипы функций
void print_train(Train t);
void input_train(Train* t);

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    // Создание структуры поезда
    Train train1;

    // Заполнение структуры
    printf("Введите данные поезда:\n");
    input_train(&train1);

    // Вывод информации
    printf("\nИнформация о поезде:\n");
    print_train(train1);

    // Пример с инициализацией
    Train train2 = {
        78,
        "14:30",
        "15:00",
        "Москва - Санкт-Петербург",
        650.5
    };

    printf("\nПример поезда №2:\n");
    print_train(train2);

    getchar();
    getchar();
    return 0;
}

// Функция ввода данных поезда
void input_train(Train* t)
{
    printf("Номер поезда: ");
    scanf("%d", &t->number);
    getchar();

    printf("Время прибытия (ЧЧ:ММ): ");
    fgets(t->arrival_time, 6, stdin);
    getchar();

    printf("Время отбытия (ЧЧ:ММ): ");
    fgets(t->departure_time, 6, stdin);
    getchar();

    printf("Направление: ");
    fgets(t->direction, 50, stdin);
    // Удаление символа новой строки
    t->direction[strcspn(t->direction, "\n")] = 0;

    printf("Расстояние (км): ");
    scanf("%f", &t->distance);
}

// Функция вывода данных поезда
void print_train(Train t)
{
    printf("==============================\n");
    printf("Поезд №%d\n", t.number);
    printf("Время прибытия: %s\n", t.arrival_time);
    printf("Время отбытия: %s\n", t.departure_time);
    printf("Направление: %s\n", t.direction);
    printf("Расстояние: %.1f км\n", t.distance);
    printf("==============================\n");
}
