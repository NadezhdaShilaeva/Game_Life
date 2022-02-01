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
(Изначальное изображение: ![snow](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/test_images/snow.bmp?raw=true))  
___Выходные данные:___  Программа создает 10 новых изображений в директории generations_test1:  
>![1](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_1.bmp?raw=true) 
![2](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_2.bmp?raw=true) 
![3](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_3.bmp?raw=true) 
![4](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_4.bmp?raw=true) 
![5](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_5.bmp?raw=true) 
![6](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_6.bmp?raw=true) 
![7](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_7.bmp?raw=true) 
![8](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_8.bmp?raw=true) 
![9](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_9.bmp?raw=true) 
![10](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test1/generation_10.bmp?raw=true)

2. ___Входные аргументы:___ Game_Life.exe --input test_images\monochrome_image.bmp --output generations_test2 --max_iter 20 --dump_freq 2  
(Изначальное изображение: ![picture](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/test_images/monochrome_image.bmp?raw=true))  
___Выходные данные:___  Программа создает 10 новых изображений в директории generations_test2:  
>![1](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_2.bmp?raw=true) 
![2](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_4.bmp?raw=true) 
![3](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_6.bmp?raw=true) 
![4](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_8.bmp?raw=true) 
![5](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_10.bmp?raw=true) 
![6](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_12.bmp?raw=true) 
![7](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_14.bmp?raw=true) 
![8](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_16.bmp?raw=true) 
![9](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_18.bmp?raw=true) 
![10](https://github.com/NadezhdaShilaeva/Game_Life/blob/main/generations_test2/generation_20.bmp?raw=true)