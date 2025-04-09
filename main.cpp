#include <iostream>
#include "grafo.h"
#include "list.h"

using namespace std;

/*El problema consiste en modelar y gestionar una red de navegación urbana. En este contexto, se representan:
    Intersecciones (vértices): Cada vértice del grafo contiene el nombre de una intersección
    Calles (aristas): Cada arista conecta dos intersecciones y representa una calle entre ellas.

El objetivo es poder agregar y eliminar intersecciones y calles en tiempo de ejecución y visualizar la estructura del grafo. 
Esto es útil, por ejemplo, para simular cambios en la red vial (por cierres, modificaciones en el tráfico, etc).*/

int main() {
    Graph<string> cityGraph;
    
    // Agregar intersecciones
    cityGraph.addVertex("Plaza");
    cityGraph.addVertex("Avenida");
    cityGraph.addVertex("Boulevard");
    cityGraph.addVertex("Calle 1");
    cityGraph.addVertex("Calle 2");
    
    // Conectar intersecciones mediante aristas (representando las calles)
    cityGraph.addEdge("Plaza", "Avenida");
    cityGraph.addEdge("Avenida", "Boulevard");
    cityGraph.addEdge("Boulevard", "Calle 1");
    cityGraph.addEdge("Calle 1", "Calle 2");
    cityGraph.addEdge("Calle 2", "Plaza");
    
    cout << "Grafo inicial:" << endl;
    cityGraph.print();
    
    // Llamada a modifyVertex: modificar "Plaza" a "Plazo"
    cout << "\nModificando vertice 'Plaza' a 'Plazo'" << endl;
    cityGraph.modifyVertex("Plaza", "Plazo");
    
    cout << "\nGrafo despues de modificar el vertice:" << endl;
    cityGraph.print();
    
    // También puedes probar remover alguna arista o vértice para ver el efecto completo
    cityGraph.removeEdge("Calle 2", "Plazo"); // Ahora la arista desde "Calle 2" a "Plazo" (antes "Plaza") se elimina
    cityGraph.removeVertex("Boulevard");
    
    cout << "\nGrafo final tras eliminar la arista entre 'Calle 2' y 'Plazo' y remover 'Boulevard':" << endl;
    cityGraph.print();
    
    return 0;
}
