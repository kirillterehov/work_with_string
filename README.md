Part1. 
Реализовал функции библиотеки string.h, а также тип s21_size_t и макрос S21_NULL на языке программирования С. Библиотека разработана на языке С стандарта C11 с использованием компилятора gcc.

void *memchr(const void *str, int c, size_t n)	Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.

int memcmp(const void *str1, const void *str2, size_t n)	Сравнивает первые n байтов str1 и str2.

void *memcpy(void *dest, const void *src, size_t n)	Копирует n символов из src в dest.

void *memset(void *str, int c, size_t n)	Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.

char *strncat(char *dest, const char *src, size_t n)	Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.

char *strchr(const char *str, int c)	Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.

int strncmp(const char *str1, const char *str2, size_t n)	Сравнивает не более первых n байтов str1 и str2.

char *strncpy(char *dest, const char *src, size_t n)	Копирует до n символов из строки, на которую указывает src, в dest.

size_t strcspn(const char *str1, const char *str2)	Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.

char *strerror(int errnum)	Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.

size_t strlen(const char *str)	Вычисляет длину строки str, не включая завершающий нулевой символ.

char *strpbrk(const char *str1, const char *str2)	Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.

char *strrchr(const char *str, int c)	Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.

char *strstr(const char *haystack, const char *needle)	Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.

char *strtok(char *str, const char *delim)	Разбивает строку str на ряд токен


Part 2. Реализовал функцию sprintf а также некоторые флаги и спецификаторы для нее

Спецификаторы:

c	Символ	Символ

d	Знаковое десятичное целое число	Знаковое десятичное целое число

i	Знаковое десятичное целое число	Знаковое целое число (может быть десятичным, восьмеричным или шестнадцатеричным)

s	Строка символов	Строка символов

u	Беззнаковое десятичное целое число	Беззнаковое десятичное целое число

x	Беззнаковое шестнадцатеричное целое число	Беззнаковое шестнадцатеричное целое число (любые буквы)

X	Беззнаковое шестнадцатеричное целое число (заглавные буквы)	Беззнаковое шестнадцатеричное целое число (любые буквы)

p	Адрес указателя	Адрес указателя

Флаги

-	Выравнивание по левому краю в пределах заданной ширины поля. Выравнивание по правому краю используется по умолчанию (см. подспецификатор ширины).

+	Заставляет явно указывать знак плюс или минус (+ или -) даже для положительных чисел. По умолчанию только отрицательным числам предшествует знак «-».

(пробел)	Если знак не будет выведен, перед значением вставляется пробел.

#	При использовании со спецификаторами o, x или X перед числом вставляется 0, 0x или 0X соответственно (для значений, отличных от нуля). При использовании с e, E и f «заставляет» записанный вывод содержать десятичную точку, даже если за ней не последует никаких цифр. По умолчанию, если не следует никаких цифр, десятичная точка не записывается. При использовании с g или G результат такой же, как и с e или E, но конечные нули не удаляются.

0	Заполняет число слева нулями (0) вместо пробелов, где указан спецификатор ширины (см. подспецификатор ширины).

h	Аргумент интерпретируется как короткое int или короткое int без знака (применяется только к целочисленным спецификаторам: i, d, o, u, x и X).

l	Аргумент интерпретируется как длинное int или длинное int без знака для целочисленных спецификаторов (i, d, o, u, x и X) и как широкий символ или строка широких символов для спецификаторов c и s.

1	(число)	Минимальное количество печатаемых символов. Если выводимое значение короче этого числа, результат дополняется пробелами. Значение не усекается, даже если результат больше.
2	*	В sprintf знак * значит, что ширина указывается не в строке формата, а в качестве дополнительного аргумента целочисленного значения, предшествующего аргументу, который необходимо отформатировать. В sscanf знак *, помещенный после % и перед спецификатором формата, считывает данные указанного типа, но подавляет их присваивание.
sprintf Точность
№	.точность	Описание
1	.число	Для целочисленных спецификаторов (d, i, o, u, x, X) — точность определяет минимальное количество записываемых цифр. Если записываемое значение короче этого числа, результат дополняется ведущими нулями. Значение не усекается, даже если результат длиннее. Точность 0 означает, что для значения 0 не записывается ни одного символа. Для спецификаторов e, E и f — это количество цифр, которые должны быть напечатаны после десятичной точки. Для спецификаторов g и G — это максимальное количество значащих цифр, которые должны быть напечатаны. Для s — это максимальное количество печатаемых символов. По умолчанию все символы печатаются до тех пор, пока не встретится терминирующий нуль. Для типа с — никак не влияет. Если точность не указана для спецификаторов e, E, f, g и G, то по умолчанию ее значение равно 6. Если точность не указана для остальных спецификаторов, то по умолчанию ее значение равно 1. Если число не указано (нет явного значения точности), то по умолчанию — 0.


Part 3. Реализовал функцию sscanf, а также некоторые флаги и спецификаторы для нее.

Спецификаторы

e	Научная нотация (мантисса/экспонента) с использованием символа e (вывод чисел должен совпадать с точностью до e-6)	Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

E	Научная нотация (мантисса/экспонента) с использованием символа Е	Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

f	Десятичное число с плавающей точкой	Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

g	Использует кратчайший из представлений десятичного числа	Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

G	Использует кратчайший из представлений десятичного числа	Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

%	Символ %	Символ %

Флаги

-	Выравнивание по левому краю в пределах заданной ширины поля. Выравнивание по правому краю используется по умолчанию (см. подспецификатор ширины).

+	Заставляет явно указывать знак плюс или минус (+ или -) даже для положительных чисел. По умолчанию только отрицательным числам предшествует знак «-».


Part 4. Реализовал специальные функции обработки строк

void *to_upper(const char *str)	Возвращает копию строки (str), преобразованной в верхний регистр. В случае какой-либо ошибки следует вернуть значение NULL.

void *to_lower(const char *str)	Возвращает копию строки (str), преобразованной в нижний регистр. В случае какой-либо ошибки следует вернуть значение NULL.

void *insert(const char *src, const char *str, size_t start_index)	Возвращает новую строку, в которой указанная строка (str) вставлена в указанную позицию (start_index) в данной строке (src). В случае какой-либо ошибки следует вернуть значение NULL.

void *trim(const char *src, const char *trim_chars)	Возвращает новую строку, в которой удаляются все начальные и конечные вхождения набора заданных символов (trim_chars) из данной строки (src). В случае какой-либо ошибки следует вернуть значение NULL.


Подготовил полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check. Unit-тесты проверяют результаты работы моей реализации путём сравнения ее с реализацией стандартной библиотеки string.h. Предусмотрен Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_string.a, gcov_report). В цели gcov_report формируется отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov.
