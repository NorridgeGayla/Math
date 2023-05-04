# Math

Реализация собственной версии математической библиотеки math.h.

## Содержание

- [Math](#math)
  - [Содержание](#содержание)
  - [Общая информация ](#общая-информация-)
  - [1. Реализация функций библиотеки math.h](#1-реализация-функций-библиотеки-mathh)

## Общая информация <br/>

- Библиотека разработана на языке Си стандарта C11 с использованием компиятора gcc <br/>
- Решение оформлено как статическая библиотека (с заголовочным файлом my_math.h) <br/>
- Расположение файлов <br/>
    * исходные файлы в src/sources <br/>
    * заголовочные файлы в src/headers <br/>
    * сборочный файл в src <br/>
    * собранная статическая библиотека располагается в директории build/my_math.a <br/>
- Обеспечено полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check <br/>
- Unit-тесты проверяют результаты работы реализованной библиотеки путём сравнения ее с реализацией стандартной библиотеки math.h <br/>
- Unit-тесты покрывают не менее 80% каждой функции <br/>
- Предусмотрен Makefile для сборки библиотеки и тестов (с целями all, clean, test, my_math.a, gcov_report) <br/>
- В цели gcov_report формируется отчёт gcov в виде html страницы <br/>
- Общая проверяемая точность - 16 значащих цифр <br/>
- Проверяемая точность дробной части - 6 знаков после запятой <br/>

## 1. Реализация функций библиотеки math.h

* Реализованы следующие функции библиотеки math.h <br/>
  
    | No. | Function                                   | Description                                                        |
    | --- | ------------------------------------------ | ------------------------------------------------------------------ |
    | 1   | `int abs(int x)`                           | вычисляет абсолютное значение целого числа                         |
    | 2   | `long double acos(double x)`               | вычисляет арккосинус                                               |
    | 3   | `long double asin(double x)`               | вычисляет арксинус                                                 |
    | 4   | `long double atan(double x)`               | вычисляет арктангенс                                               |
    | 5   | `long double ceil(double x)`               | возвращает ближайшее целое число, не меньшее заданного значения    |
    | 6   | `long double cos(double x)`                | вычисляет косинус                                                  |
    | 7   | `long double exp(double x)`                | возвращает значение e, возведенное в заданную степень              |
    | 8   | `long double fabs(double x)`               | вычисляет абсолютное значение числа с плавающей точкой             |
    | 9   | `long double floor(double x)`              | возвращает ближайшее целое число, не превышающее заданное значение |
    | 10  | `long double fmod(double x, double y)`     | остаток операции деления с плавающей точкой                        |
    | 11  | `long double log(double x)`                | вычисляет натуральный логарифм                                     |
    | 12  | `long double pow(double base, double exp)` | возводит число в заданную степень                                  |
    | 13  | `long double sin(double x)`                | вычисляет синус                                                    |
    | 14  | `long double sqrt(double x)`               | вычисляет квадратный корень                                        |
    | 15  | `long double tan(double x)`                | вычисляет тангенс                                                  |