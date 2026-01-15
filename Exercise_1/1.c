#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <math.h>

// Объявление структуры точки
struct point {
    float x;
    float y;
    char name;
};

// Создание псевдонима
typedef struct point Point;

// Прототипы функций
void put_point(Point z);
float dist(Point z, Point w);
Point middle(Point z, Point w);
int quarter(Point z);

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    // Создание и инициализация точек
    Point a, b, m;

    a = (Point){ 1.f, 2.f, 'A' };
    b.name = 'B';
    b.x = 5;
    b.y = -3;

    // Вывод точек
    printf("Точка A: ");
    put_point(a);
    printf("\nТочка B: ");
    put_point(b);

    // Вычисление расстояния
    printf("\n\nРасстояние между точками: %.2f\n", dist(a, b));

    // Вычисление середины отрезка
    m = middle(a, b);
    printf("Середина отрезка AB: ");
    put_point(m);

    // Определение четверти
    printf("\n\nТочка A находится в ");
    switch (quarter(a))
    {
    case 1: printf("первой четверти"); break;
    case 2: printf("второй четверти"); break;
    case 3: printf("третьей четверти"); break;
    case 4: printf("четвертой четверти"); break;
    default: printf("на оси координат");
    }

    printf("\nТочка B находится в ");
    switch (quarter(b))
    {
    case 1: printf("первой четверти"); break;
    case 2: printf("второй четверти"); break;
    case 3: printf("третьей четверти"); break;
    case 4: printf("четвертой четверти"); break;
    default: printf("на оси координат");
    }

    getchar();
    return 0;
}

// Функция отображения точки
void put_point(Point z)
{
    printf("точка %c (%.1f, %.1f)", z.name, z.x, z.y);
}

// Функция вычисления расстояния
float dist(Point z, Point w)
{
    float dx = w.x - z.x;
    float dy = w.y - z.y;
    return sqrt(dx * dx + dy * dy);
}

// Функция вычисления середины отрезка
Point middle(Point z, Point w)
{
    Point result;
    result.x = (z.x + w.x) / 2;
    result.y = (z.y + w.y) / 2;
    result.name = 'M';
    return result;
}

// Функция определения координатной четверти
int quarter(Point z)
{
    if (z.x > 0 && z.y > 0) return 1;
    if (z.x < 0 && z.y > 0) return 2;
    if (z.x < 0 && z.y < 0) return 3;
    if (z.x > 0 && z.y < 0) return 4;
    return 0; // на оси
}