# Estructuras de Datos - Tarea Colas / Pilas

Este proyecto fue creado como un programa de consola escrito en el lenguaje C++ en el cual se realizará una simulación de casos donde se inicializarán los “page-fault” utilizando los métodos de remplazo de marco de página: **FIFO (Colas), LIFO (Pilas) y Optimo**, con el fin de averiguar cuál de los tres métodos resulta ser el más optimo al ingresar una secuencia de dígitos (números) y una cantidad de marco de páginas.

## Tabla de Contenido
* [Objetivos](#objetivos)
* [Descripción](#descripción)
* [Instalación](#instalación)
* [Desarrolladores](#desarrolladores)

## Objetivos
- El objetivo general y principal de este manual de usuario es buscar otorgar un soporte del desarrollo hacia los usuarios que tengan la intención de utilizar el proyecto dándole como apoyo un control e información sobre la creación del proyecto y su desarrollo.
- Un objetivo específico del programa es que tiene como propósito analizar ciertas técnicas de memoria utilizadas por el sistema operativo, así como la eficiencia de cada una de dichas técnicas.

## Descripción
Cuando inicies el programa serás recibido con una pantalla de inicio, se te solicitará pulsar cualquier tecla para avanzar, después se te presentará un menú en donde tendrás dos opciones, ya sea, realizar el procedimiento de simulación o salir del programa, te podrás desplazar pulsando las fechas de arriba y abajo del teclado, y pulsas Enter para ingresar a la opción seleccionada.
- Si seleccionas la primera opción se te solicitará ingresar una secuencia de números, cada número debe estar separado por un espacio, una vez que hayas terminado de ejecutar la secuencia, se te pedirá la cantidad de marcos de página. Una vez llenado esa información, el programa realizar los procedimientos correspondientes y averiguar cuál método de remplazo de marco de páginas resulta ser el más eficiente con la menor cantidad de page-faults.
- En caso de seleccionar la segunda opción se te preguntará si deseas salir del programa o deseas continuar en él.

## Instalación
Para la ejecución de este programa se necesita un editor como Visual Studio Community 2022 o Visual Studio Code.

Para Visual Studio Community 2022 necesitas tener descargado la carga de trabajo **Desarrollo para el escritorio con C++**, ya con esto será suficiente para poder ejecutar el programa.

![VSWorkloads](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/9c66f062-e5f0-4618-8d0f-b274f8914515)

En el caso de Visual Studio Code necesitas tener instalado en tu computadora un compilador de C++ que te permita correr el programa, los más recomendados son [g++](https://www.msys2.org/) o [clang](https://clang.llvm.org/get_started.html).

Se recomienda tener instalado también la extensión de C++ en Visual Studio Code para la detección de errores de sintaxis y ayudas con las librerías. 

![VSCCppExtension](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/591a293a-9b7a-4106-84c7-79a5f4433640)

Una vez instalado, pulsas en el botón de ejecutar en la esquina superior derecha.

<img src="https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/2bba3329-eb49-497a-ac8b-26e3ea452a2f" width="50%">

Si es tu primer programa de C++ corriendo en Visual Studio Code se te abrirá la paleta de comando pidiendote que selecciones un compilador para debugear el programa...
Te recomiendo que selecciones alguno de los 2 compiladores que están marcados.

![VSCCppSelectDebug](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/1dc39b84-695f-4fb4-a1b4-cc8c3d479e96)

Ya que lo tengas seleccionado, Visual Studio Code empezará a compílar el programa. El archivo principal del programa se llama ```main.cpp```

## Desarrolladores:

* Aaron Steve Alfaro Zamora
* Maria Stephanie Araya Solano
* Michelle José Arrieta Zamora
* Keilyn Morera Vargas
