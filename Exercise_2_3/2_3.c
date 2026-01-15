#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

// Функция для центрированного вывода
void print_centered(char* text, int width, char fill)
{
    int len = strlen(text);
    int padding = (width - len) / 2;

    for (int i = 0; i < padding; i++)
        putchar(fill);

    printf("%s", text);

    for (int i = 0; i < width - len - padding; i++)
        putchar(fill);

    printf("\n");
}

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    // Объявление переменных
    struct tm* mytime;
    time_t t;
    char buffer[100];
    char line[100];

    // Получение времени
    t = time(NULL);
    mytime = localtime(&t);

    // Массивы для дней и месяцев
    char* days[] = { "воскресенье", "понедельник", "вторник", "среда",
                    "четверг", "пятница", "суббота" };
    char* months[] = { "января", "февраля", "марта", "апреля", "мая", "июня",
                      "июля", "августа", "сентября", "октября", "ноября", "декабря" };

    // Верхняя граница окна
    for (int i = 0; i < 80; i++) printf("*");
    printf("\n");

    // Заголовок
    print_centered("ТЕКУЩЕЕ ВРЕМЯ", 78, ' ');

    // Разделитель
    for (int i = 0; i < 80; i++) printf("*");
    printf("\n");

    // Время
    sprintf(line, "Время: %02d:%02d:%02d",
        mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    print_centered(line, 78, ' ');

    // Дата
    sprintf(line, "Дата: %d %s %d года",
        mytime->tm_mday, months[mytime->tm_mon], mytime->tm_year + 1900);
    print_centered(line, 78, ' ');

    // День недели
    sprintf(line, "День недели: %s", days[mytime->tm_wday]);
    print_centered(line, 78, ' ');

    // Номер дня в году
    sprintf(line, "Сегодня %d-й день года", mytime->tm_yday + 1);
    print_centered(line, 78, ' ');

    // До нового года
    int months_to_ny = 11 - mytime->tm_mon;
    int days_in_month;
    if (mytime->tm_mon == 1)
        days_in_month = 28 + ((mytime->tm_year % 4 == 0) ? 1 : 0);
    else if (mytime->tm_mon == 3 || mytime->tm_mon == 5 ||
        mytime->tm_mon == 8 || mytime->tm_mon == 10)
        days_in_month = 30;
    else
        days_in_month = 31;

    int days_to_ny = days_in_month - mytime->tm_mday;
    for (int i = mytime->tm_mon + 1; i < 12; i++)
    {
        if (i == 1)
            days_to_ny += 28 + ((mytime->tm_year % 4 == 0) ? 1 : 0);
        else if (i == 3 || i == 5 || i == 8 || i == 10)
            days_to_ny += 30;
        else
            days_to_ny += 31;
    }

    sprintf(line, "До Нового года: %d месяцев и %d дней", months_to_ny, days_to_ny);
    print_centered(line, 78, ' ');

    // Нижняя граница окна
    for (int i = 0; i < 80; i++) printf("*");
    printf("\n");

    getchar();
    return 0;
}