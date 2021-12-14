g++ -c main.cpp Game.cpp Player.cpp ConstParser.cpp -ISFML/SFML/include

g++ main.o Game.o Player.o ConstParser.o -o tron -LSFML/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Долгосрочное домашнее задание (игра "Трон")

## Этап I
Время на этап: **18 часов**

### Цель

Необходимо разработать игру для одного пользователя против ботов. Правила игры можно найти в интернете, вспомнить фильм "Трон", более корректное название этой игры "Lightning Cycles".

### Инструменты

На этом и следующем этапе вам потребуется изучить и использовать следующие основные инструменты для разработки вашего приложения:

* IDE для разработки (CLion)
* Совместный GIT-репозиторий (см. [Задание 3 по командной работе](../task3.md))
* Библиотека SFML (см. [Задание 6 по GUI](../task6.md))

Возможность реализации с использованием других средств разработки и языков программирования необходимо обсудить с преподавателем.

### Задание

На этом этапе необходимо реализовать desktop-приложение, c графической отрисовкой процесса игрыи реализующее основную логику игры.

#### Функционал, который должен быть реализован:
1. Игровое меню
    * кнопка **Начать** - открывает новое окно с настройками игры:
        * выбор **количества раундов** или **быструю игру (1 раунд) на время, кто дольше**
        * выбор количества ботов (с возможностью выбора 0, это режим тренировки)
        * кнопка "Начать игру"
    * кнопка **Настройки** - открывает новое окно с настройками:
        * **раскладки клавиатуры** для игрока, ввод конкретных клавиш, или выбор готовых раскладок типа WASD, стрелочки и т.п.
        * выбором **имени** игрока
        * выбором **цвета** игрока (нельзя выбирать желтый цвет - это цвет ботов, а также цвет фона карты).
        * выбором размера поля
        * кнопка "Сохранить" сохраняет настройки и выходит в прелылущее меню
    * кнопка **Выход** - выдаёт диалоговое окно "Хотите выйти из игры?" с вариантами действий по выходу или возрату в игру.
2. Игровой процесс
    * возможность управлять своим персонажем (раскладки "WASD", "стрелочки" и т.п.)
    * возможность поставить игру на паузу с отображением **диалогового окна**:
        * кнопка **Возобновить игру**
        * кнопка **Выйти из игры** - возврат в основное меню программы
        * кнопка **Рестарт** - запуск игры заново с теми же параметрами, расположение игрока и ботов при этом выбирается случайное, новое.
    * визуальная часть:
        * отображение времени игры
        * отображение счёта игры (если это многораундовая игра)
        * отображение счётчика раундов (если это многораундовая игра)
        * отображение **имени** игрока с **цветом**
    * по завершению игры вывод **диалогового окна**:
        * **имя** и **цвет** победителя
        * **счёт игры**, если это игра с несколькими раундами, или **время** игры, если это быстрая игра
        * кнопки **Выход** или **Рестарт**
    * логика игры:
        * игрок проигрывает, если встречается со своим или чужим **следом**
        * игрок проигрывает, если сталкивается с **препятствием** или стеной
        * объявляется **ничья**, если игроки столкнулись "лоб в лоб" (для варианта многопользовательской игры на втором этапе), столкновение "лоб в лоб" с ботом это проигрыш.
        * выигрыш игрока в раунде - это смерть всех ботов, столкнувшихся с препятствием, другим объектом или его следом.
        * в **раундовом сражении** побеждает тот игрок, который выиграл **наибольшее** число раундов
3. Конфигурация игры
    * все важные настройки игры хранить в файлах в любом удобном формате   
    * в настройках должна содержаться вся информация из вкладки **Настройки** игрового меню и различные параметры игрового процесса: раскладки клавиатуры и т.п. При этом, в случае если конфигурационный файл отсутствует, необходимо прописать в коде **настройки по умолчанию**, либо иным разумным способом обработать эту ситуацию

### Командная разработка

Далее пошагово представлен процесс реализации игры на этапе I. Каждый из членов команды выбирает себе задание,
согласовав этот шаг разработки с остальными участниками команды. Шаги разработки составлены так, что **лучше всего** для команды — полностью закрыть все задачи **конкретного** шага, прежде чем переходить к **следующему** шагу (тут вам потребуется командная работа).

На каждом шаге разработки ожидается **очевидный** промежуточный результат от команды. Команда должна иметь возможность отчитаться в любой момент о состоянии дел по разработке игры. Основное ТЗ можно посмотреть ещё раз
[тут](#функционал-который-должен-быть-реализован), подробное ТЗ будет расписано в каждом шаге.

#### Шаги разработки:

1. Время на работу: **6 часов**  

   * **Разработка макета визуальной части процесса игры и части главного меню**.  

     Необходимо разработать подробный макет (в любом из доступных средств визуализации макетов) основного экрана игры.
     На экране должны быть:
     * **имя игрока**, выделенные выбранными цветами,
     * **время игры**;
     * **счёт игры** (если это многораундовая игра);
     * **счётчик раундов** (если это многораундовая игра);
     * сама **карта**, по которой будут передвигаться игроки и боты. Очевидно, что всё это должно лаконично смотреться и не "накладываться" друг на друга.

     Для каждой отдельной кнопки меню необходимо сделать "подсвечивание" кнопки.

   * **Разработка основного меню игры**.  

     Необходимо разработать основное меню игры с кнопками: **Начать**, **Настройки** и **Выход** с указанным ранее функционалом.

     Для работы с настройками и их хранением в файле реализовать отдельный класс/модель для удобства работы.         

   Для этого шага разработки **результатом** является готовое меню с фоном. Каждая кнопка должна открывать своё окно, а все прописываемые в окнах параметры должны записываться в соответствующие поля конфигурационного файла или переменные программы, если их нет смысла хранить в файле.

2. Время на работу: **6 часов**  

   * **Визуализация окна игры**  

     На этом шаге необходимо отобразить на экран всё то, что было нанесено на макет на предыдущем шаге. На экране могут быть "заглушки". Главное, чтобы был реализован такой функционал, который позволит другому члену команды использовать прописанные игроками параметры (имена, цвета, способности и т.д.), чтобы связать визуализацию с логикой.  

   * **Привязка визуальной составляющей с логикой игры**  

     Необходимо написать функционал, который позволяет получать параметры, вводимые игроками на предыдущем шаге, чтобы использовать их для визуализации на экране и для реализации логики игры. Здесь необходимо параллельное взаимодействие двух членов команды, чтобы по итогу полученные на предыдущем шаге параметры      игроков корректно отображались на экране игры.  

   * **Написание логики движения игроков и ботов**

     Необходимо написать функционал, который отображает на экране игроков и ботов (на данном шаге не важен цвет) в случайных местах на карте и заставляет их двигаться в случайном направлении. Необходимо написать функционал, позволяющий управлять игроком на карте (на данном шаге не важна раскладка — пропишите их "по-умолчанию"). Необходимо, чтобы игрок и боты оставляли за собой **след**, а также могли двигаться за пределы карты: если игрок или бот зашёл за границу карты, он просто появляется на противоположной стороне и продолжает движение.

   Для этого шага разработки **результатом** является основное окно игры с отображенными параметрами на экране: имя игрока, выделенное выбранным цветом; время игры; основная карта с игроком и ботами на ней.
   Также должна быть реализована логика движения игрока с возможностью управления и возможностью выхода игроков за границы карты.

3. Время на работу: **6 часов**

   * **Реализация поведения ботов**

     Необходимо реализовать логику поведения ботов, либо со случайными поворотами, либо основываясь на состоянии карты и игрока. Время между случайными поворотами подобрать в процессе разработки, при этом время или момент поворота должен определяться исходя из растояния бота до любого статичного препятствия (то есть кроме игроков и ботов), чтобы минимизировать количество ботов "самоубийц", врезающихся в стену.

     Возможен вариант выбора сложности ботов, которые могут учитывать статичные препятствия, движушиеся объекты и следы и т.п. Таким образом, чтобы убить самого сложного бота необходимо загнать его в ловушку, поскольку от всех препятствий он уворачивается.

   * **Реализация логики столкновения игрока и ботов и дополнения к игре**  

     Необходимо реализовать логику, когда игрок или боты сталкиваются со стеной, со следом противника, либо со своим следом — все случаи означают проигрыш столкнувшегося. Здесь же нужно обработать ситуацию при столкновении "лоб в лоб".

     Также необходимо реализовать возможность выбора конкретной раскладки клавиатуры. На прошлом шаге стояло значение по-умолчанию. Теперь необходимо учесть задание параметров раскладки из поля **Настройки** в главном меню.

   * **Реализация диалогового окна паузы**  

     Необходимо реализовать диалоговое окно, которое будет появляться при нажатии клавиши "ESC". На диалоговом окне необходимо отобразить информацию и кнопки, представленные ранее в ТЗ.

   * **Реализация диалогового окна по завершению игры**  

     Необходимо написать диалоговое окно, которое вызывается в случае завершения игры или раунда. При этом, для двух ситуаций диалоговые окна отличаются. В случае, когда был сыгран один из раундов (когда играется многораундовая игра), но не конечный, то отображается временное окно, в котором указывается:
       * **имя** и **цвет** победителя раунда
       * **счёт игры**
       * **время** раунда

     Временное окно должно исчезать через какое-то разумное время (можно добавить эффект "растворения" окна, когда постепенно снижается его прозрачность), игроки должны расставляться заново случайно, время обновляться, а счётчик раундов и сам счёт — изменяться.

     В случае, когда сыграна **быстрая** игра или это был финальный раунд **многораундовой** игры, необходимо показывать диалоговое окно, в котором указывается:
       * **имя** и **цвет** победителя игры
       * **счёт игры**, если это игра с несколькими раундами (в случае быстрой игры этот пункт не учитывать)
       * **суммарное время** игры (сумма времени всех раундов)
       * кнопка **Выйти из игры**, возвращающая игроков в главное меню
       * кнопка **Рестарт**, начинающая игру с самого начала, сохраняя все заданные параметры, но обнуляя время, карту и т.п. Стартовая расстановка игроков на карте тоже обновляется — игроки расставляются случайно.

     Важно учесть, что многораундовая игра может закончиться раньше, чем количество раундов (к примеру, когда раундов 5, а один из игроков выиграл уже 3 раунда подряд, тогда доигрывать 2 раунда не имеет смысла).

   Для этого шага разработки **результатом** является реализованная логика передвижения игроков, их столкновения, а также вывод всех сопутствующих **работающих** диалоговых окон в случае завершения игры/раунда или паузы (нажатие на клавишу "ESC"). При этом, должно работать изменение раскладки для игроков, задаваемое в **Настройках** игры, а также изменение счётчика раундов и счёта (в случае многораундовой игры). На этом шаге игра должна выглядеть готовой для комфортной **быстрой** или **многораундовой** игры.


## Этап II
Время на этап: **18 часов**

### Цель

Необходимо разработать многопользовательскую (на 2 игрока) версию игры.

В этот этап необходимо включить:
* Выбор количество игроков - 1 или 2 при начале игры
* Ввод имени и выбор цвета и раскладки для второго игрока в настройках
* Добавление случайных препятствий на карту
* запись статистики в отдельный файл по игрокам и вывод статистики при нажатии клавиши **Статистика** в главном меню

Функционал и задачи определить самостоятельно аналогично первому этапу. Второй этап это развитие первого этапа в многопользовательском режиме.
