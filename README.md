# CppSource

Repo for fifth homework on 2019/2020 C++ course

# Task 1

Создайте класс **Counted**, каждый экземпляр которого имеет свой ID типа *int*. 
ID должны быть:
 - положительны
 - уникальны у каждого объекта
 - иметь минимально возможное значение, чтобы предотвратить переполнение типа
 
То есть, если какой-то момент времени в памяти существует два объекта, то их ID должны быть равны 1 и 2, соответственно. Объектов с невалидными ID или без ID не должно существовать.

Не забывайте про Rule of Five.

# Task 2

Добавьте экземпляры класса **Counted** в `std::vector`. Правильно реализованный класс **Counted** будет вызывать ошибку компиляции при попытке компиляции такого кода. Найдите в документации `std::vector` часть, объясняющую причину ошибки компиляции. Скопируйте/заскриньте эту часть и отправьте ее в коммент Pull Request-а. 

# Task 3

Не меняя класс **Counted**, предложите два способа добавления экземпляров этого класса в `std::vector`. "Добавление" в данном случае означает, что через элементы вектора должна быть возможность получить доступ к объектам **Counted**. 

Примерный код:
```cpp
Counted c1;
Counted c2;
std::vector</* ваш код */> vector = /* ваш код, добавляющий c1 и c2 в vector */ ;
for(const auto& i:vector){
    std::cout << /* ваш код */ << std::endl; // вывод ID объектов, чтобы убедиться, что все работает как надо
}
```

# Task 4*

Не меняя класс **Counted**, предложите еще один способ добавления экземпляров этого класса в `std::vector`. 
