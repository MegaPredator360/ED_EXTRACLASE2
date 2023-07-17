#pragma once
#include <string>			// Para poder usar el tipo de dato "string"
#include <iostream>			// Permite al usuario interactuar con la aplicacion de consola
#include <wchar.h>			// Para caracteres especiales
#include <conio.h>			// Para obtener caracter en formato ASCII
#include <queue>			// Para poder realizar listas en colas
#include <Windows.h>		// Libreria de C++ exclusiva para Windows
#include <unordered_set>	// Para hacer uso del "unordened_set"

#pragma comment (lib, "winmm.lib")	// Vincular las funciones multimedia de Windows con el programa

// Colores de letra para la consola
#define RED     "\033[31m"
#define YELLOW	"\x1B[33m"
#define GREEN	"\x1B[32m"
#define WHITE   "\033[0m"

using namespace std;