Курс «Объектно-ориентированное программирование на C++» Неделя №12

Описать класс «Битовая строка» производный от класса «Строка».

Домашнее задание №12
(Строки данного класса могут содержать только символы ‘0’ и ‘1’). Если в основе инициализирующей строки встретятся любые символы, отличные от допустимых, 
то «Битовая строка» становится пустой. 
Содержимое строки рассматривается как двоичное представление целого числа со знаковым разрядом. 

Отрицательные числа хранятся в дополнительном коде. // не реализовано

Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра C-строку;
3) конструктор копирования;
4) оператор присваивания;
4) деструктор;
5) изменение знака числа (перевод числа в дополнительный код);// не реализовано
8) сложение битовых строк (перегрузить операторы + и +=);
9) проверка на равенство (= =) и на неравенство (!=).
