# New_lem_in

## ВАЖНО! РАБОЧАЯ ВЕРСИЯ В КОРНЕ, ПРОТОТИП (НЕ РАБОЧИЙ) В ПАПКЕ TMP

 v: 0.7.1 [Большое обновление]:

	- Изменен Makefile;
	- GNL теперь часть файлов проекта, а не отдельная папка;
	- Добавлен make erandal - клонит папку с картами и генератором;
	- Добавлен make norme - цветная проверка нормы;

 v: 0.7 - Изменено:

	- Полностью изменен порядок файлов. Все разбито по блокам;
	- Каждый файл имеет приписку 'ln_';
	- Новые хеддеры. Папки ./srcs и ./includes подогнанны под норму;

		- Добавлено:

	- Автор файл с 2-мя никами;

# Archive
 v: 0.2 - added 'L'-char && RU-char errors;
 
 v: 0.3 - added:
 
        - Message if no ways from start to end;
        
        - The best free at err_exit;
        
        - Check foreign room at link parse;

 v: 0.4 - added:
		
		- Nullified all pointers at ini();

		- Added check the same links;
		
 v: 0.4.2 - added:
		
		- "No rooms" - error;

		- All files Normed;

		- (+mod) at parse_rooms - added one more func for getting coords;

		  - deleted:
		
		- "-s" - flag from Makefile;

 v: 0.5 - Добавлены:
		
	- Возможность комментария перед числом муравьев;
	-** Временно отключены очистки; 
	- Добавлены отрицательные координаты;
	- Добавлена возможность компат со знаком '-';
	- Если пути нет - это не ошибка, будет выведено "нет пути";

 v: 0.5.1 - Добавлены:
 
	- Обработка MAX\MIN INT;
	- Убраны несколько лишних масивов, да будет много памяти!;

 v: 0.6 - Добавлены:

	- Добавлен флаг '-e' для вывода полной ошибки;
	- Проверено на утечки;
	- Заменен способ вывода карты. Теперь после обработки алгоритма;
	- Проверено разными картами;
	- Исправлены Errors в valgrind;

 v: 0.6.1 - Добавлены:

	- Добавлены ограничения для карт 100к+ и списков 100к+ (Шоб не сегало);

 v: 0.6.2 - Добавлены:

	- Незначительно: Добавлен '\n' в выводе между картой и муравьями;
