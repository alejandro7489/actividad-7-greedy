# Actividad 7: Algoritmos voraces (Greedy)

Implementaciones en C++ de mochila fraccionaria y colocación de antenas. Ambos
programas leen los datos desde la entrada estándar, por lo que se pueden probar
con cualquier caso válido.

## Requisitos

- Compilador compatible con C++11 o posterior (por ejemplo, `g++`).

## Compilar

Desde la carpeta del proyecto:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic Mochila.cpp -o Mochila.exe
g++ -std=c++11 -Wall -Wextra -pedantic Antenas.cpp -o Antenas.exe
```

## Ejecutar: mochila fraccionaria

La entrada contiene la cantidad de objetos, la capacidad de la mochila y una
línea por objeto con su nombre, valor y peso. Los pesos deben ser positivos y
los valores no negativos.

```text
3 50
A 60 10
B 100 20
C 120 30
```

En PowerShell, guarda esos datos en un archivo, por ejemplo `mochila.txt`, y
ejecuta:

```powershell
.\Mochila.exe < mochila.txt
```

El programa ordena los objetos por valor/peso y toma primero los de mayor
rendimiento, permitiendo una fracción del último objeto.

## Ejecutar: colocación de antenas

La entrada contiene la cantidad de casas, el radio de cobertura y las
posiciones de las casas. El radio debe ser no negativo.

```text
7 5
1 2 7 11 20 21 30
```

En PowerShell, guarda esos datos en `antenas.txt` y ejecuta:

```powershell
.\Antenas.exe < antenas.txt
```

El programa ordena las posiciones y coloca cada antena en `casa no cubierta
más a la izquierda + radio`, cubriendo así tantas casas consecutivas como sea
posible en cada paso.

## Complejidad

- **Mochila fraccionaria:** ordenar toma `O(n log n)` y recorrer los objetos
  `O(n)`. El tiempo total es `O(n log n)` y el espacio adicional es `O(n)`,
  considerando la copia del vector para ordenar.
- **Antenas:** ordenar toma `O(n log n)` y el recorrido greedy `O(n)`. El
  tiempo total es `O(n log n)` y el espacio adicional es `O(n)` para las
  posiciones ordenadas y el resultado.
