# Game Life
###### Лабораторная работа по программированию №5

Реализация [игры “Жизнь”](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), позволяющая выводить поколение игры в монохромную картинку в [формате BMP](https://en.wikipedia.org/wiki/BMP_file_format). Плоскость “вселенной” игры ограничена положительными координатами.  
Программа выполнена в виде консольного приложения принимающего в качестве аргументов следующие параметры:  

__--input input_file.bmp__ - где input_file.bmp - монохромная картинка в формате bmp, хранящая начальную ситуацию (первое поколение) игры
__--output dir_name__ - название директории для хранения поколений игры в виде
монохромной картинки
__--max_iter N__ - максимальное число поколений которое может эмулировать программа. Необязательный параметр, по-умолчанию бесконечность
__--dump_freq N__ - частота с которой программа должно сохранять поколения виде картинки. Необязательный параметр, по-умолчанию равен 1

#### Название файла и опции передаются через аргументы командной строки в следующем формате:  
___Game_Life.exe --input input_file.bmp --output dir_name --max_iter N --dump_freq N___  

---
#### Примеры использования программы:

1. ___Входные аргументы:___ Game_Life.exe --input test_images\snow.bmp --output generations_test1 --max_iter 10  
___Выходные данные:___ 
2. ___Входные аргументы:___ Game_Life.exe --input test_images\monochrome_image.bmp --output generations_test2 --max_iter 20 --dump_freq 2  
___Выходные данные:___ 
![pictures](https://raw.githubusercontent.com/ITMO-IS-Programming/hw5-NadezhdaShilaeva/main/test_images/monochrome_image.bmp?token=GHSAT0AAAAAABRDH7Z26UZJSS6NU4K2PI3IYPZHXWA)