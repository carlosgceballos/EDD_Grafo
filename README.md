Un grafo es una estructura de datos compuesta por un conjunto de vértices (o nodos) y aristas (o enlaces) que conectan pares de vértices. Esta estructura se utiliza para representar relaciones o conexiones entre distintos elementos. Por ejemplo, en un sistema de navegación urbana, los vértices pueden representar intersecciones de calles y las aristas las vías o calles que las conectan.

Implementación de los Grafos en el Problema:

El problema consiste en modelar y gestionar de forma dinámica una red de navegación urbana. En este contexto, se representan:
- Intersecciones (vértices): Cada vértice del grafo contiene el nombre de una intersección (por ejemplo, "Plaza", "Avenida", "Boulevard", etc.).
- Calles (aristas): Cada arista conecta dos intersecciones y representa una calle entre ellas.

El objetivo es poder agregar y eliminar intersecciones y calles en tiempo de ejecución y visualizar la estructura del grafo. Esto es útil, por ejemplo, para simular cambios en la red vial (por cierres, modificaciones en el tráfico, etc.).

Organización del Proyecto y Estructuras.

La solución se ha implementado sin usar la STL, utilizando plantillas personalizadas para listas enlazadas. El código se ha distribuido en varios archivos:

a) nodelist.h
Propósito: Define la clase Node<T>, que es la unidad básica de cualquier lista enlazada.

Características:
- Almacena un dato de tipo T y un puntero al siguiente nodo.
- Usa listas de inicialización en los constructores para inicializar los miembros.
- El método getData() retorna una referencia al dato, de modo que cualquier modificación realizada afecte al objeto original en la lista.

b) list.h
Propósito: Implementa la plantilla List<T>, la cual permite manejar listas enlazadas genéricas utilizando nodos definidos en nodelist.h.

En este proyecto las listas se usan para gestionar la estructura dinámica del grafo. Concretamente:
- Lista de Vértices: Se utiliza una lista enlazada para almacenar todos los vértices del grafo. Cada nodo de esta lista contiene un vértice. Esta lista permite agregar o eliminar vértices de manera dinámica sin tener que definir un tamaño fijo de antemano.
- Lista de Aristas (Lista de Adyacencia): Cada vértice, a su vez, posee una lista enlazada para almacenar sus aristas. Es decir, para cada vértice se guarda una lista de conexiones que apuntan a otros vértices, lo que representa las rutas o calles que conectan las intersecciones. De esta forma, cada nodo (vértice) del grafo tiene asociada una lista de sus nodos adyacentes.

c) structs.h

Propósito: Se ha separado en un archivo nuevo (structs.h) todas las estructuras específicas del grafo:

	- Edge<T>: Representa una arista. Solo contiene el destino dest (por ejemplo, el nombre de la intersección de llegada). Se sobrecargan operator< y operator== para facilitar la inserción y búsqueda dentro de las listas.
	- Vertex<T>: Representa un vértice (intersección) que contiene:
			- Un dato data (nombre de la intersección).
			- Una lista de aristas (edges), de tipo List<Edge<T>>, que es la lista de adyacencia del vértice.

Las definiciones de estos operadores permiten que la lista de vértices y de aristas se pueda mantener en orden si se desea, y que sean comparables para las operaciones de inserción y eliminación.

d) grafo.h
Propósito: Este archivo ahora contiene la clase Graph<T>, que se encarga de gestionar el grafo completo.

Funciones Principales:

	- Almacenamiento de vértices: Se utiliza la plantilla List<Vertex<T>> para mantener la colección de vértices.
	- Método findVertexNode: Recorre la lista de vértices para encontrar uno cuyo dato coincida con el proporcionado.
	- addVertex: Agrega un vértice (si no existe) usando la estructura Vertex<T> definida en structs.h.
	- addEdge: Se asegura que tanto el vértice origen como destino existen. Luego, inserta una arista en la lista de adyacencia del vértice origen. Si el grafo es no dirigido, se inserta una arista de forma recíproca en el destino.
	- removeEdge: Remueve la arista entre dos vértices.
	- removeVertex: Elimina un vértice y, en consecuencia, se recorre el resto de los vértices para eliminar en sus listas de aristas cualquier referencia a este vértice.
	- print: Recorre la lista de vértices y para cada uno imprime su nombre junto con la lista de sus vértices adyacentes (las intersecciones conectadas).
	-modifyVertex: cumple con el objetivo de modificar dinámicamente el grafo.

e) main.cpp
Funcionalidad:

1. Se instancia un objeto Graph<string> para modelar la red vial.
2. Se agregan vértices que representan distintas intersecciones: "Plaza", "Avenida", "Boulevard", "Calle 1" y "Calle 2".
3. Se crean aristas (calles) que conectan estas intersecciones:
- "Plaza" se conecta con "Avenida".
- "Avenida" con "Boulevard".
- "Boulevard" con "Calle 1".
- "Calle 1" con "Calle 2".
- "Calle 2" con "Plaza".

4. Se muestra en pantalla la red de navegación tras la inserción.
5. Se realizan modificaciones:
	- Plaza se cambia a Plazo modificando este vertice.
Se muestra en pantalla la red de navegación tras la modificacion.
	- Se elimina la arista entre "Calle 2" y "Plazo".
	- Se elimina el vértice "Boulevard" (lo que provoca que todas las aristas que apuntaban a él sean eliminadas de las demás intersecciones).

Finalmente se vuelve a imprimir el grafo para evidenciar los cambios.

----------------------------------------------------------------------------

Clase Grafo:
Esta clase utiliza nuestra plantilla personalizada List para almacenar los vértices, y cada vértice (definido en structs.h como Vertex<T>) posee su propia lista de aristas (List<Edge<T>>). Este diseño permite crear, modificar y eliminar dinámicamente vértices y aristas.

- Constructor de Graph: Inicializa el grafo con una lista vacía de vértices.
- findVertexNode: Recorre la lista de vértices usando el método getHead() y compara el dato de cada vértice con el parámetro data. Permite determinar si un vértice existe y, de ser así, retorna el nodo que lo contiene. Esto se utiliza en otras funciones para evitar duplicados o para modificar los vértices.
- addVertex: Antes de agregar, se busca si el vértice ya existe. Si no se encuentra, se inserta un nuevo objeto Vertex<T> con el dato->data mediante el método insert de la lista.
- addEdge: Primero se asegura de que los vértices fuente (src) y destino (dest) existan; si no, se crean usando addVertex. Se obtiene el nodo del vértice fuente y se inserta una nueva arista en su lista de aristas utilizando Edge<T>(dest).
- removeEdge: Busca el vértice fuente con findVertexNode(src) y elimina de su lista de aristas la conexión que tenga como destino dest mediante remove(Edge<T>(dest)).
- removeVertex: Elimina el vértice cuyo dato sea data de la lista de vértices, usando el método remove de la lista. Luego recorre la lista de vértices restantes y elimina de cada uno la arista que tenga como destino data para limpiar las referencias que apunten al vértice eliminado.
- print: Recorre la lista de vértices, imprimiendo para cada uno su dato (nombre de la intersección) y la lista de sus conexiones (destinos de las aristas).
-------------------------------------------------------------------------------------------------------
Struct Edge: 
- Miembro:
  - T dest: Es el dato que almacena la "identificación" del vértice destino.

- Constructor:
  - Edge(T d) : dest(d) {}: Inicializa el atributo dest con el valor proporcionado en d. Esto asegura que cada vez que se crea una arista, se especifique el destino de inmediato.

- Operador <:
  - bool operator<(const Edge<T>& other) const { return dest < other.dest; }: Permite comparar dos aristas mediante el atributo dest. Esto es útil para insertar las aristas de forma ordenada en la lista enlazada y para realizar búsquedas, ya que el método de inserción de la lista depende de operator< para decidir la posición.

- Operador ==:
  - bool operator==(const Edge<T>& other) const { return dest == other.dest; }: Compara dos aristas para determinar si apuntan al mismo destino. Se utiliza en los métodos de eliminación (por ejemplo, en List::remove) para identificar y quitar la arista correspondiente.
 ---------------------------------------------------------------------------------------------------------
Struct Vertex:
- Miembros:
  - T data: Almacena el dato o identificador del vértice.
  - List<Edge<T>> edges: Es una lista enlazada que contiene las aristas salientes del vértice, es decir, todas las conexiones que tiene este vértice con otros vértices del grafo.

- Constructor:
  - Vertex(T d) : data(d), edges(nullptr) {}: Inicializa el vértice con el dato d y crea su lista de aristas inicializada en vacío (usando nullptr en el constructor de la lista, lo que indica que no hay aristas al comenzar).

- Operador <:
  - bool operator<(const Vertex<T>& other) const { return data < other.data; }: Permite ordenar o comparar vértices según su dato. Esta función es útil para mantener la lista de vértices ordenada y facilitar búsquedas o eliminaciones.

- Operador ==:
  - bool operator==(const Vertex<T>& other) const { return data == other.data; }: Compara dos vértices para determinar si son iguales (es decir, si tienen el mismo dato). Se utiliza en los métodos de inserción y eliminación para asegurarse de que no se insertan duplicados y para eliminar el vértice correcto.
