В данном проекте рассматривается задача обедающих философов.

Цель проекта: научиться работать с многопоточностью, изучить mutex и semafores.

Коротко о проекте:
- есть входные данные, такие как: 
        - колчиество философов(потоков), 
        - время до сметри философа, 
        - время в течении, которого философ ест, 
        - время сна, 
        - количество раз сколько должен поесть каждый филосов(опционально).
- у каждого философа есть одна вилка(мьютекс) и он должен использовать вилку соседа, для того чтобы поесть.
- необходимо разработать программу, в которой с опеределенных ситуaциях философы будут жить вечно, а в других погибать.

Во второй(бонусной части) аналогичная задача, однако, для реализации используются семафоры(вместо мьютексов) и процессы (вместо потоков).
