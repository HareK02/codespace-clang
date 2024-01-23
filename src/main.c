#include <stdio.h>

typedef struct
{
	char type[2];
	int size[2];
	int max_pixel_value;
} header;

int SaveImage(char *filename, header h, int *pixels)
{
	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return 1;
	}

	fprintf(fp, "%c%c\n", h.type[0], h.type[1]);
	fprintf(fp, "%d\n", h.size[0]);
	fprintf(fp, "%d\n", h.size[1]);
	fprintf(fp, "%d\n", h.max_pixel_value);

	for (int i = 0; i < h.size[0] * h.size[1]; i++)
	{
		fprintf(fp, "%d\n", pixels[i]);
	}

	return 0;
}

int pos(int x, int y)
{
	return x + y * 256;
}

void DrawCircle(int *pixels)
{
	int r = 50;
	int c = 256 / 2;
	int x = r, y = 0;
	int F = -2 * r + 3;
	while (x >= y)
	{
		pixels[pos(c + x, c + y)] = 255;
		pixels[pos(c - x, c + y)] = 255;
		pixels[pos(c + x, c - y)] = 255;
		pixels[pos(c - x, c - y)] = 255;
		pixels[pos(c + y, c + x)] = 255;
		pixels[pos(c - y, c + x)] = 255;
		pixels[pos(c + y, c - x)] = 255;
		pixels[pos(c - y, c - x)] = 255;
		if (F >= 0)
			F -= 4 * x--;
		F += 4 * y++ + 2;
	}
}

void Gradient(int *pixels)
{
	for (int x = 0; x < 256; x++)
	{
		for (int y = 0; y < 256; y++)
		{
			pixels[pos(x, y)] = y;
		}
	}
}

int main(void)
{
	header h = {
			{'P', '2'},
			{256, 256},
			255};
	int pixels[256 * 256];

	Gradient(pixels);
	if (SaveImage("Gradient.pgm", h, pixels))
		return 1;

	for (int i = 0; i < 256 * 256; i++)
	{
		pixels[i] = 0;
	}

	DrawCircle(pixels);
	if (SaveImage("Circle.pgm", h, pixels))
		return 1;

	return 0;
}