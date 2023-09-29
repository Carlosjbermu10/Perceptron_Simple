// CARLOS BERMUDEZ 29668441

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Matrices_vocales
{
	int matrices[10][16];
	int array_vocales[5];
} vocales[25];

// Prototipos de las funciones

void llenado_matrices();
void mostrar_matrices();
int funcion_activacion(float pesos[][16], int a1[][16], float umbral);
float funcion_activacion_FINAL(float pesos[][16], int a1[][16], float umbral);

void entrenamiento();

int main()
{

	llenado_matrices();
	mostrar_matrices();

	entrenamiento();

	getch();
	return 0;
}

void llenado_matrices()
{

	vocales[0] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{1, 0, 0, 0, 0}};
	vocales[1] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{1, 0, 0, 0, 0}};
	vocales[2] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{1, 0, 0, 0, 0}};
	vocales[3] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{1, 0, 0, 0, 0}};
	vocales[4] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{1, 0, 0, 0, 0}};
	vocales[5] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 1, 0, 0, 0}};
	vocales[6] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 1, 0, 0, 0}};
	vocales[7] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, // 10
		},
		{0, 1, 0, 0, 0}};
	vocales[8] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 1, 0, 0, 0}};
	vocales[9] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, // 9
			{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 1, 0, 0, 0}};
	vocales[10] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 1, 0, 0}};
	vocales[11] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 1, 0, 0}};
	vocales[12] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 1, 0, 0}};
	vocales[13] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 1, 0, 0}};
	vocales[14] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 1, 0, 0}};
	vocales[15] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 1, 0}};
	vocales[16] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 1, 0}};
	vocales[17] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 4
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, // 5
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 1, 0}};
	vocales[18] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1}, // 3
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0}, // 4
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 6
			{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, // 7
			{0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 8
			{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 1, 0}};
	vocales[19] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0}, // 3
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 1, 0}};
	vocales[20] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 0, 1}};
	vocales[21] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 0, 1}};
	vocales[22] = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // 7
			{0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0}, // 8
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 0, 1}};
	vocales[23] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0}, // 8
			{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 0, 1}};
	vocales[24] = {
		{
			//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 2
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 3
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 4
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 5
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // 6
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
			{0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 8
			{0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0}, // 9
			{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
		},
		{0, 0, 0, 0, 1}};
}

void mostrar_matrices()
{

	for (int a = 0; a < 11; a++)
	{
		// cout<<"La vocal: "<<endl;
		for (int i = 0; i < 10; i++)
		{
			// cout<<vocales[a].array_vocales[i]<<", ";
			for (int j = 0; j < 16; j++)
			{
				// cout<<vocales[a].matrices[i][j];
			}
			// cout<<endl;
		}
		// cout<<endl;
	}
}

int funcion_activacion(float pesos[][16], int a1[][16], float umbral)
{

	float z = 0;
	float z_total = 0;
	float matriz3[10][16];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matriz3[i][j] = ((a1[i][j]) * (pesos[i][j]));
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			z += matriz3[i][j];
		}
	}

	z_total = z + umbral;

	// cout << "z total a: " << z_total << endl;

	if (z_total > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Funcion de Activacion que se utiliza al final para comprobar mas exactamente
float funcion_activacion_FINAL(float pesos[][16], int a1[][16], float umbral)
{

	float z = 0;
	float z_total = 0;
	float matriz3[10][16];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			matriz3[i][j] = ((a1[i][j]) * (pesos[i][j]));
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			z += matriz3[i][j];
		}
	}

	z_total = z + umbral;

	return z_total;

	// cout << "z total e: " << z_total << endl;
}

void entrenamiento()
{

	// Variables para el entrenamiento

	float tasa_de_aprendizaje = 0.002;
	int epocas = 100;
	int cantidad_matrices = 25;
	srand(time(0));

	// PERCEPTRON AAAAAAA

	float umbral_a = 0.5;
	int error_a = 0;

	// Genera una matriz 10x16 de pesos aleatorios
	float pesos_a[10][16];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			pesos_a[i][j] = (float)((-25) + rand() % ((1) - (-25))) / 100;
		}
	}

	// recorrer las epocas
	for (int b = 0; b < epocas; b++)
	{

		int error_total_a = 0;

		for (int a = 0; a < cantidad_matrices; a++)
		{
			int aa[10][16];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					int aux = 0;
					aux = vocales[a].matrices[i][j];
					aa[i][j] = aux;
				}
			}

			int valor_esperado = 0;
			int prediccion = 0;

			prediccion = funcion_activacion(pesos_a, aa, umbral_a); // Se llama a la funcion de Activacion

			if (vocales[a].array_vocales[0] == 1)
			{
				valor_esperado = 1;
			}
			else
			{
				valor_esperado = 0;
			}

			error_a = valor_esperado - prediccion;
			error_total_a += pow(error_a, 2);

			// Calculo de errores
			umbral_a += tasa_de_aprendizaje * error_a;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					pesos_a[i][j] += tasa_de_aprendizaje * aa[i][j] * error_a;
				}
			}
		}
		// cout << "error total a: " << error_total_a << endl;
	}

	// PERCEPTRON EEEEEEE

	float umbral_e = 0.5;
	int error_e = 0;

	// Genera una matriz 10x16 de pesos aleatorios
	float pesos_e[10][16];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			pesos_e[i][j] = (float)((-25) + rand() % ((1) - (-25))) / 100;
		}
	}

	// recorrer las epocas
	for (int b = 0; b < epocas; b++)
	{
		int error_total_e = 0;

		for (int a = 0; a < cantidad_matrices; a++)
		{
			int ee[10][16];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					int aux = 0;
					aux = vocales[a].matrices[i][j];
					ee[i][j] = aux;
				}
			}

			int valor_esperado = 0;
			int prediccion = 0;

			prediccion = funcion_activacion(pesos_e, ee, umbral_e); // Se llama a la funcion de Activacion

			if (vocales[a].array_vocales[1] == 1)
			{
				valor_esperado = 1;
			}
			else
			{
				valor_esperado = 0;
			}

			error_e = valor_esperado - prediccion;
			error_total_e += pow(error_e, 2);

			// Calculo de errores
			umbral_e += tasa_de_aprendizaje * error_e;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					pesos_e[i][j] += tasa_de_aprendizaje * ee[i][j] * error_e;
				}
			}
		}
		// cout << "error total e: " << error_total_e << endl;
	}

	// PERCEPTRON IIIIIII

	float umbral_i = 0.5;
	int error_i = 0;

	// Genera una matriz 10x16 de pesos aleatorios
	float pesos_i[10][16];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			pesos_i[i][j] = (float)((-25) + rand() % ((1) - (-25))) / 100;
		}
	}

	// recorrer las epocas
	for (int b = 0; b < epocas; b++)
	{
		int error_total_i = 0;

		for (int a = 0; a < cantidad_matrices; a++)
		{
			int ii[10][16];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					int aux = 0;
					aux = vocales[a].matrices[i][j];
					ii[i][j] = aux;
				}
			}

			int valor_esperado = 0;
			int prediccion = 0;

			prediccion = funcion_activacion(pesos_i, ii, umbral_i); // Se llama a la funcion de Activacion

			if (vocales[a].array_vocales[2] == 1)
			{
				valor_esperado = 1;
			}
			else
			{
				valor_esperado = 0;
			}

			error_i = valor_esperado - prediccion;
			error_total_i += pow(error_i, 2);

			// Calculo de errores
			umbral_i += tasa_de_aprendizaje * error_i;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					pesos_i[i][j] += tasa_de_aprendizaje * ii[i][j] * error_i;
				}
			}
		}

		// cout << "error total i: " << error_total_i << endl;
	}

	// PERCEPTRON OOOOOOOOO

	float umbral_o = 0.5;
	int error_o = 0;

	// Genera una matriz 10x16 de pesos aleatorios
	float pesos_o[10][16];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			pesos_o[i][j] = (float)((-25) + rand() % ((1) - (-25))) / 100;
		}
	}

	// recorrer las epocas
	for (int b = 0; b < epocas; b++)
	{
		int error_total_o = 0;

		for (int a = 0; a < cantidad_matrices; a++)
		{
			int oo[10][16];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					int aux = 0;
					aux = vocales[a].matrices[i][j];
					oo[i][j] = aux;
				}
			}

			int valor_esperado = 0;
			int prediccion = 0;

			prediccion = funcion_activacion(pesos_o, oo, umbral_o); // Se llama a la funcion de Activacion

			if (vocales[a].array_vocales[3] == 1)
			{
				valor_esperado = 1;
			}
			else
			{
				valor_esperado = 0;
			}

			error_o = valor_esperado - prediccion;
			error_total_o += pow(error_o, 2);

			// Calculo de errores
			umbral_o += tasa_de_aprendizaje * error_o;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					pesos_o[i][j] += tasa_de_aprendizaje * oo[i][j] * error_o;
				}
			}
		}

		// cout << "error total o: " << error_total_o << endl;
	}

	// PERCEPTRON UUUUUUUU

	float umbral_u = 0.5;
	int error_u = 0;

	// Genera una matriz 10x16 de pesos aleatorios
	float pesos_u[10][16];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			pesos_u[i][j] = (float)((-25) + rand() % ((1) - (-25))) / 100;
		}
	}

	// recorrer las epocas
	for (int b = 0; b < epocas; b++)
	{
		int error_total_u = 0;

		for (int a = 0; a < cantidad_matrices; a++)
		{
			int uu[10][16];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					int aux = 0;
					aux = vocales[a].matrices[i][j];
					uu[i][j] = aux;
				}
			}

			int valor_esperado = 0;
			int prediccion = 0;

			prediccion = funcion_activacion(pesos_u, uu, umbral_u); // Se llama a la funcion de Activacion

			if (vocales[a].array_vocales[4] == 1)
			{
				valor_esperado = 1;
			}
			else
			{
				valor_esperado = 0;
			}

			error_u = valor_esperado - prediccion;
			error_total_u += pow(error_u, 2);

			// Calculo de errores
			umbral_u += tasa_de_aprendizaje * error_u;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					pesos_u[i][j] += tasa_de_aprendizaje * uu[i][j] * error_u;
				}
			}
		}

		// cout << "error total u: " << error_total_u << endl;
	}

	//------ PEDIR DATOS A EL USUARIO ----------

	int nueva_matriz[10][16];

	cout << "Ingrese la vocal que quiere comprabar: " << endl;
	cout << "---LO HARA EN FORMA DE MATRIZ--- " << endl;
	cout << " " << endl;

	// LLENAR MATRIZ
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << "Digite un numero [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> nueva_matriz[i][j];
		}
	}

	// MOSTRAR MATRIZ

	cout << " " << endl;
	cout << "El resultado de la matriz ingresada es la siguiente: " << endl;
	cout << " " << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << nueva_matriz[i][j];
		}
		cout << "\n";
	}

	float resultado_A = 0;
	float resultado_E = 0;
	float resultado_I = 0;
	float resultado_O = 0;
	float resultado_U = 0;

	resultado_A = funcion_activacion_FINAL(pesos_a, nueva_matriz, umbral_a);
	cout << "\n";
	cout << resultado_A << endl;

	resultado_E = funcion_activacion_FINAL(pesos_e, nueva_matriz, umbral_e);
	cout << "\n";
	cout << resultado_E << endl;

	resultado_I = funcion_activacion_FINAL(pesos_i, nueva_matriz, umbral_i);
	cout << "\n";
	cout << resultado_I << endl;

	resultado_O = funcion_activacion_FINAL(pesos_o, nueva_matriz, umbral_o);
	cout << "\n";
	cout << resultado_O << endl;

	resultado_U = funcion_activacion_FINAL(pesos_u, nueva_matriz, umbral_u);
	cout << "\n";
	cout << resultado_U << endl;
	cout << " " << endl;

	if (resultado_A <= 0 && resultado_E <= 0 && resultado_I <= 0 && resultado_O <= 0 && resultado_U <= 0)
	{
		cout << "La matriz recien ingresada no es de ninguna vocal";
	}
	else
	{
		if (resultado_A > resultado_E && resultado_A > resultado_I && resultado_A > resultado_O && resultado_A > resultado_U)
		{
			cout << "El valor de la Matriz de la vocal ingresa es la:  AAAAAAAA";
		}

		if (resultado_E > resultado_A && resultado_E > resultado_I && resultado_E > resultado_O && resultado_E > resultado_U)
		{
			cout << "El valor de la Matriz de la vocal ingresa es la:  EEEEEEEE";
		}

		if (resultado_I > resultado_A && resultado_I > resultado_A && resultado_I > resultado_O && resultado_I > resultado_U)
		{
			cout << "El valor de la Matriz de la vocal ingresa es la:  IIIIIIII";
		}

		if (resultado_O > resultado_A && resultado_O > resultado_E && resultado_O > resultado_I && resultado_O > resultado_U)
		{
			cout << "El valor de la Matriz de la vocal ingresa es la:  OOOOOOOOO";
		}

		if (resultado_U > resultado_A && resultado_U > resultado_E && resultado_U > resultado_I && resultado_U > resultado_O)
		{
			cout << "El valor de la Matriz de la vocal ingresa es la:  UUUUUUUUU";
		}
	}
}
