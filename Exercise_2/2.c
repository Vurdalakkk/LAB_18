#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    // Объявление переменных
    struct tm* mytime;
    time_t t;
    char buffer[100];

    // Получение системного времени
    t = time(NULL);
    mytime = localtime(&t);

    // 2.1 Вывод времени
    printf("Московское время %02d:%02d:%02d\n",
        mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    // 2.2 Дополнительная информация
    printf("\nДополнительная информация:\n");

    // 1. День недели
    char* days[] = { "воскресенье", "понедельник", "вторник", "среда",
                    "четверг", "пятница", "суббота" };
    printf("1. День недели: %s\n", days[mytime->tm_wday]);

    // 2. Дата через разделитель
    printf("2. Дата: %02d.%02d.%d\n",
        mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);

    // 3. День и месяц словами
    char* months[] = { "января", "февраля", "марта", "апреля", "мая", "июня",
                      "июля", "августа", "сентября", "октября", "ноября", "декабря" };
    printf("3. %d %s\n", mytime->tm_mday, months[mytime->tm_mon]);

    // 4. Номер дня в году
    printf("4. Сегодня %d-й день %d года\n",
        mytime->tm_yday + 1, mytime->tm_year + 1900);

    // 5. До воскресенья
    int days_to_sunday = (7 - mytime->tm_wday) % 7;
    printf("5. До воскресенья %d дней и %d часов\n",
        days_to_sunday, 24 - mytime->tm_hour);

    // 7. До нового года
    int months_to_ny = 11 - mytime->tm_mon;
    int days_in_month;
    if (mytime->tm_mon == 1) // февраль
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

    printf("7. До Нового года осталось %d месяцев и %d дней\n",
        months_to_ny, days_to_ny);

    // 10. Месяц римскими цифрами
    char* roman_months[] = { "I", "II", "III", "IV", "V", "VI",
                           "VII", "VIII", "IX", "X", "XI", "XII" };
    printf("10. %s %d\n", roman_months[mytime->tm_mon],
        mytime->tm_year + 1900);

    // 11. Время года
    char* season;
    if (mytime->tm_mon >= 2 && mytime->tm_mon <= 4)
        season = "весна";
    else if (mytime->tm_mon >= 5 && mytime->tm_mon <= 7)
        season = "лето";
    else if (mytime->tm_mon >= 8 && mytime->tm_mon <= 10)
        season = "осень";
    else
        season = "зима";

    int short_year = (mytime->tm_year + 1900) % 100;
    printf("11. %s %02d\n", season, short_year);

    getchar();
    return 0;
}
