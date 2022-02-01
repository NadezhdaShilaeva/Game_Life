#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	int infoheader_size[1];
	int width_pix[1];
	int width_byte[1];
	int height_pix[1];
	int size[1];
	char black;
} image;

char* make_file_name(char* dir_name, int generation)
{
	char number_generation[100];
	sprintf(number_generation, "%d", generation);
	char* new_file_name = (char*)malloc(strlen(dir_name) + 16 + strlen(number_generation));
	new_file_name[0] = '\0';
	strcat(new_file_name, dir_name);
	strcat(new_file_name, "\\generation_");
	strcat(new_file_name, number_generation);
	strcat(new_file_name, ".bmp");
	return new_file_name;
}

void get_headers(image* image_in, FILE* file_in, FILE* new_file)
{
	char byte[1];
	int i = 0;
	for (i = 0; i < 14; ++i)
	{
		fread(byte, 1, 1, file_in);
		fwrite(byte, 1, 1, new_file);
	}
	fread(image_in->infoheader_size, 4, 1, file_in);
	fwrite(image_in->infoheader_size, 4, 1, new_file);
	fread(image_in->width_pix, 4, 1, file_in);
	fwrite(image_in->width_pix, 4, 1, new_file);
	fread(image_in->height_pix, 4, 1, file_in);
	fwrite(image_in->height_pix, 4, 1, new_file);
	for (i = 12; i < 20; ++i)
	{
		fread(byte, 1, 1, file_in);
		fwrite(byte, 1, 1, new_file);
	}
	fread(image_in->size, 4, 1, file_in);
	fwrite(image_in->size, 4, 1, new_file);
	image_in->width_byte[0] = image_in->size[0] / image_in->height_pix[0];
	for (i += 4; i < image_in->infoheader_size[0]; ++i)
	{
		fread(byte, 1, 1, file_in);
		fwrite(byte, 1, 1, new_file);
	}
	int color[2];
	fread(color, 4, 2, file_in);
	fwrite(color, 4, 2, new_file);
	if (color[0] == 0)
		image_in->black = 0;
	else
		image_in->black = 1;
}

char is_alive(char byte, int pix, image* image_in)
{
	if ((byte & (1 << (7 - pix))) == (image_in->black << (7 - pix)))
		return 1;
	else
		return 0;
}

void count_if_alife(FILE* file_in, int offset, int pix, int* count, image* image_in)
{
	char byte[1];
	fseek(file_in, offset, SEEK_CUR);
	fread(byte, 1, 1, file_in);
	fseek(file_in, -offset - 1, SEEK_CUR);
	if (is_alive(byte[0], pix, image_in))
		++(*count);
}

int count_alive_neighbors(FILE* file_in, image* image_in, int heihghtp, int widthb, int pix)
{
	int count = 0;
	if (pix + widthb * 8 > 0)
	{
		if (heihghtp > 0)
		{
			if (pix == 0)
			{
				count_if_alife(file_in, -image_in->width_byte[0] - 2, 7, &count, image_in);
			}
			else
			{
				count_if_alife(file_in, -image_in->width_byte[0] - 1, pix - 1, &count, image_in);
			}
		}
		if (heihghtp < image_in->height_pix[0] - 1)
		{
			if (pix == 0)
			{
				count_if_alife(file_in, image_in->width_byte[0] - 2, 7, &count, image_in);
			}
			else
			{
				count_if_alife(file_in, image_in->width_byte[0] - 1, pix - 1, &count, image_in);
			}
		}
		if (pix == 0)
		{
			count_if_alife(file_in, -2, 7, &count, image_in);
		}
		else
		{
			count_if_alife(file_in, -1, pix - 1, &count, image_in);
		}
	}
	if (pix + widthb * 8 < image_in->width_pix[0] - 1)
	{
		if (heihghtp > 0)
		{
			if (pix == 7)
			{
				count_if_alife(file_in, -image_in->width_byte[0], 0, &count, image_in);
			}
			else
			{
				count_if_alife(file_in, -image_in->width_byte[0] - 1, pix + 1, &count, image_in);
			}
		}
		if (heihghtp < image_in->height_pix[0] - 1)
		{
			if (pix == 7)
			{
				count_if_alife(file_in, image_in->width_byte[0], 0, &count, image_in);
			}
			else
			{
				count_if_alife(file_in, image_in->width_byte[0] - 1, pix + 1, &count, image_in);
			}
		}
		if (pix == 7)
		{
			count_if_alife(file_in, 0, 0, &count, image_in);
		}
		else
		{
			count_if_alife(file_in, -1, pix + 1, &count, image_in);
		}
	}
	if (heihghtp > 0)
	{
		count_if_alife(file_in, -image_in->width_byte[0] - 1, pix, &count, image_in);
	}
	if (heihghtp < image_in->height_pix[0] - 1)
	{
		count_if_alife(file_in, image_in->width_byte[0] - 1, pix, &count, image_in);
	}
	return count;
}

void game_life(char* byte, FILE* file_in, image* image_in, int heihghtp, int widthb)
{
	for (int pix = 0; (pix < 8) && (pix + widthb * 8 < image_in->width_pix[0]); ++pix)
	{
		int pix_neighbors = count_alive_neighbors(file_in, image_in, heihghtp, widthb, pix);
		if ((is_alive(byte[0], pix, image_in) == 1) && (pix_neighbors < 2 || pix_neighbors > 3))
		{
			byte[0] = byte[0] ^ (1 << (7 - pix));
		}
		else
		{
			if ((is_alive(byte[0], pix, image_in) == 0) && (pix_neighbors == 3))
			{
				byte[0] = byte[0] ^ (1 << (7 - pix));
			}
		}
	}
}

void make_images(char* file_name, char* dir_name, int max_iter, int dump_freq, int generation)
{
	if (max_iter == 0 || dump_freq == 0)
		return;
	FILE* file_in = fopen(file_name, "rb+");
	if (file_in == NULL)
	{
		printf("Error of file opening\n");
		exit(1);
	}
	char* new_file_name = make_file_name(dir_name, generation);
	FILE* new_file = fopen(new_file_name, "wb+");
	if (new_file == NULL)
	{
		printf("Error of file creating\n");
		exit(1);
	}
	image image_in;
	get_headers(&image_in, file_in, new_file);
	for (int heightp = 0; heightp < image_in.height_pix[0]; ++heightp)
	{
		for (int widthb = 0; widthb < image_in.width_byte[0]; ++widthb)
		{
			char byte[1];
			fread(byte, 1, 1, file_in);
			game_life(byte, file_in, &image_in, heightp, widthb);
			fwrite(byte, 1, 1, new_file);
		}
	}
	fclose(file_in);
	fclose(new_file);
	if ((generation - 1) % dump_freq != 0)
	{
		remove(file_name);
	}
	if (max_iter == -1 || generation < max_iter)
	{
		make_images(new_file_name, dir_name, max_iter, dump_freq, generation + 1);
	}
	if (generation % dump_freq != 0)
		remove(new_file_name);
	free(new_file_name);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc < 5)
	{
		printf("Error\n");
		return 1;
	}
	if (strcmp(argv[1], "--input") == 0 && strcmp(argv[3], "--output") == 0)
	{
		int max_iter = -1, dump_freq = 1;
		if (argc >= 7 && strcmp(argv[5], "--max_iter") == 0)
		{
			max_iter = atoi(argv[6]);
		}
		if (argc == 9 && strcmp(argv[7], "--dump_freq") == 0)
		{
			dump_freq = atoi(argv[8]);
		}
		make_images(argv[2], argv[4], max_iter, dump_freq, 1);
	}
	else
	{
		printf("Commands cannot be recognized\n");
	}
	return 0;
}