# Tarea 3. Técnicas de diseño de algoritmos

---

##### Integrantes:
1. Katia Yareth Bellido López - A01023638 - Campus CSF.

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

Para los dos ejercicios se utilizó el BackTracking. En el programa para resolver y jugar el juego gato se resolvió iterativamente, mientras que el laberinto cuenta con recursividad. Esto se debe al tamaño de su tablero y sus posibles resultados. 

En el problema del juego "Gato", utilice una función iterativa para poder ordenar los resultados debido a que las posibles soluciones se encontrarían en las mismas posiciones. Tomando en cuenta que la función iterativa con complejidad O(n) llama a varias funciones con complejidad O(n^2). El código para poder jugar al gato cuenta con una complejidad **O(n^3)**;

El backtracking se aplica en la función de selección de casilla en donde se analizan los movimientos de ambos jugadores para evitar o generar un movimiento ganador según de quien sea el turno. Se mueve por Columna o fila y analiza si hay dos posiciones consecutivas en la misma columna o fila con el mismo simbolo. Como ejemplo de esta comparación en el código, si ocurre esto: **tablerogato[move][i]==tablerogato[move+1][i]**, como estrategia se realizará el siguiente movimiento: **tablerogato[move+2][i].**

En el problema de laberinto primero se buscó crear el mismo de forma aleatoria por lo que su complejidad de creación fue de O(n^3). Sin embargo para encontrar el camino solución se implementó una función de recursividad la que analizaba si podía seguir su camino ya sea hacia delante, arriba o abajo. Por lo tanto debido a las 3 posibilidades en el algoritmo la complejidad sería en el peor de los casos **O(3^n*m)** siendo n el numero de filas y m el de columnas. 

El backtracking se aplica en la función de recursividad goAheadInTheGame y la función verificar, donde según dependa el caso se verifica si hay un espacio en blanco donde avanzar y permitirá volver a llamar a la función y continuar con el camino en una posible solución. En el caso que un camino ya haya sido visitado se guardara en una lista de estructura que se implementa en la función de verificar. Ejemplo de backtracking en la función: 
    **if(laberinto[i][j+1]==' ' && re==0 && Verificar(i,j+1))**
    **{**
        **re=goAheadInTheMaze(i,j+1);//hacia adelante**    
    **}**

### 2.1 Pasos a seguir para utilizar la aplicación

#### Requisitos:

* Contar con acceso a internet
* Contar con una terminal
	* La terminal debe tener gcc instalado
	* La terminal debe tener git instalado
	* La terminal debe poder clonar un repositorio de git (cuenta con acceso a la red)

#### Para clonar el repositorio
1. Crear una carpeta en la que se vaya a clonar el repositorio
2. Mediante la terminal, navegar a dicha carpeta
3. Correr el comando `git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-KatiaBellido.git`

#### Para correr el programa
1. Mediante la terminal, navegar a la carpeta sources
2. Para el primer problema correr el comando: `g++  gato.cpp -o check -std=c++17`
3. Correr el comando: `./check`
4. Para el segundo problema correr el comando: `g++  laberinto.cpp -o maze -std=c++17`
5. Correr el comando: `./maze`

## 3. Referencias

> http://www.lcc.uma.es/~av/Libro/

> https://www.geeksforgeeks.org/backtracking-algorithms/

> https://www.geeksforgeeks.org/structures-in-cpp/
