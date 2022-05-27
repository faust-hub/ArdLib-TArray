# ArdLib-TArray <span style="font-size:small"> v1.0.0 </span>

Библиотека класса **TArray** для работы с массивами (JS-style)

## Инициализация
   - **TArray** <type_item> *arrName*                                 - создание пустого массива
   - **TArray** <type_item> *arrName*(num_items)                      - создание массива с заданным количеством элементов
   - **TArray** <type_item> *arrName*(num_items, value)               - создание массива и заполнение всех элементов одним значением
   - **TArray** <type_item> *arrName*{ value1, value2, ..., valueN }  - создание массива с заданными значениями

## Методы
   - *arrName*.**length**()         -  возвращает число элементов массива
   - *arrName*.**push**(*val*, ...) - добавляет элемент/элементы в конец массива
   - *arrName*.**pop**()            - извлекает и возвращает элемент из конца массива

## Перебор всех элементов массива (callback lambda)
   - *arrName*.**forEach**([](type_item *val*) -> void { ... })
   - *arrName*.**forEach**([](type_item *val*, uint8_t ind) -> void { ... })

## Изменение всех элементов массива (callback lambda)
   - *arrName*.**modify**([](type_item *val*) -> type_item { ... return *new_val* })
   - *arrName*.**modify**([](type_item *val*, uint8_t ind) -> type_item { ... return *new_val* })

## Создание нового массива из исходного с преобразованием элементов (callback lambda)
   - **TArray** <new_type_item> *arrOther* = *arrName*.**map** <new_type_item> ([](type_item *val*) -> new_type_item { ... return *new_val* })
   - **TArray** <new_type_item> *arrOther* = *arrName*.**map** <new_type_item> ([](type_item *val*, uint8_t ind) -> new_type_item { ... return *new_val* })