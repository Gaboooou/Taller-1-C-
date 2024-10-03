//
// Created by ulloc on 17-09-2024.
//
#define LISTASOLICITUDES_H
#include "ArregloDinamico.h"
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <sstream>
#include <random>


#include "Proyecto.h"
#include "Solicitud.h"

/**
 * @struct Nodo
 * @brief Estructura que representa un nodo de la lista enlazada, que contiene una solicitud y un puntero al siguiente nodo.
 */
struct Nodo {

    Solicitud solicitud ; // Cada nodo contiene un objeto de tipo Solicitud
    Nodo * next; // Puntero al siguiente nodo de la lista
    // Constructor del nodo que inicializa con una solicitud

    /**
 * @brief Constructor de Nodo que inicializa con una solicitud.
 * @param solicitud Solicitud que se almacenará en el nodo.
 */
    Nodo(const Solicitud& solicitud) : solicitud(solicitud), next(nullptr) {}



};
/**
 * @class ListaSolicitudes
 * @brief Clase que representa una lista enlazada simple para gestionar las solicitudes.
 */
class ListaSolicitudes {
    /**
     * @brief Retorna el puntero al primer nodo de la lista.
     * @return Puntero al nodo cabeza de la lista.
     */
public:
    [[nodiscard]] Nodo * getHead() const {
        return head;
    }



    /**
 * @brief Constructor por defecto. Inicializa la lista vacía.
 */
    ListaSolicitudes() : head(nullptr), cola(nullptr),nodoActual(nullptr){}

    /**
  * @brief Destructor que libera la memoria de todos los nodos de la lista.
  */
    ~ListaSolicitudes() {
        Nodo * aux = head; // Comenzar desde el primer nodo
        while (aux) {  // Recorrer todos los nodos

            Nodo* next = aux->next; // Guardar el puntero al siguiente nodo
            delete aux;  // Liberar la memoria del nodo actual
            aux = next; // Moverse al siguiente nodo
        }
    }

    /**
 * @brief Metodo que añade una nueva solicitud al final de la lista.
 * @param nuevaSolicitud La solicitud a añadir a la lista.
 */
    void addSolicitud(const Solicitud& nuevaSolicitud);
    /**
     * @brief Retorna la cantidad de solicitudes en la lista.
     * @return La cantidad de solicitudes.
     */
    int cantidadSolicitudes() const;

    /**
 * @brief Muestra la solicitud actual.
 */
    void mostrarSolicitudActual() const;

    /**
 * @brief Elimina la primera solicitud de la lista.
 */
    void eliminarPrimeraSolicitud();

    /**
  * @brief Verifica si la lista está vacía.
  * @return true si la lista está vacía, false en caso contrario.
  */
    bool estaVacia() const;

    /**
  * @brief Reinicia el puntero de la lista a la primera solicitud.
  */
    void reiniciarLista();

    /**
 * @brief Muestra la siguiente solicitud en la lista.
 */
    void mostrarSiguienteSolicitud();

    /**
 * @brief Gestiona las solicitudes en conjunto con un arreglo dinámico de proyectos.
 * @param proyectos Arreglo dinámico que contiene los proyectos.
 */
    void gestionarSolicitudes(ArregloDinamico& proyectos);
    /**
     * @brief Lee las solicitudes desde un archivo y las carga en la lista.
     */
    void leerArchivoSolicitudes();

    /**
   * @brief Metodo para revertir un proyecto ya aceptado y devolverlo a la lista de solicitudes.
   * @param listaSolicitudes Lista en la cual se devolverá el proyecto.
   */
    void RevertirUnProyecto(ListaSolicitudes& listaSolicitudes);
    /**
     * @brief Obtiene la fecha actual del sistema.
     * @return Fecha actual como una cadena de texto.
     */
    std::string obtenerFechaActual();




    private:
    Nodo* head;        ///< Puntero al primer nodo de la lista.
    Nodo* cola;        ///< Puntero al último nodo de la lista.
    Nodo* nodoActual;  ///< Puntero que rastrea la solicitud actual en la lista.





};



#endif //NODE_H
