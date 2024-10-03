//
// Created by ulloc on 17-09-2024.
//

#include "ListaSolicitudes.h"
#include <sstream>
#include <bits/random.h> // Para generar IDs aleatorios
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "ArregloDinamico.h"
#include "Proyecto.h"

/**
 * @brief Método para generar un ID aleatorio de 6 letras mayúsculas.
 * @return Un ID generado aleatoriamente.
 */
std::string generarIDAleatorio() {
    const int longitud = 6;
    std::string id;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');

    for (int i = 0; i < longitud; ++i) {
        id += static_cast<char>(dis(gen));
    }
    return id;
}

/**
 * @brief Obtiene la fecha actual del sistema en formato DD-MM-YYYY.
 * @return Fecha actual como una cadena de texto.
 */
std::string ListaSolicitudes::obtenerFechaActual() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    return oss.str();
}

/**
 * @brief Añade una nueva solicitud al final de la lista.
 * @param nuevaSolicitud La solicitud que se añadirá.
 */
void ListaSolicitudes::addSolicitud(const Solicitud& nuevaSolicitud) {
    Nodo* nuevoNodo = new Nodo(nuevaSolicitud); // Crear un nuevo nodo con la solicitud
    if (!head) { // Si la lista está vacía
        head = nuevoNodo; // El nuevo nodo es la cabeza
        cola = nuevoNodo; // también es la cola
    } else { // Si ya hay nodos en la lista
        cola->next = nuevoNodo; // Enlazar el último nodo con el nuevo nodo
        cola = nuevoNodo;  // Actualizar la cola al nuevo nodo
    }
}

/**
 * @brief Retorna la cantidad de solicitudes en la lista.
 * @return El número de solicitudes en la lista.
 */
int ListaSolicitudes::cantidadSolicitudes() const {
    int count = 0;
    Nodo* current = this->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

/**
 * @brief Muestra la solicitud actual.
 */
void ListaSolicitudes::mostrarSolicitudActual() const {
    std::cout << "Número de solicitudes: " << this->cantidadSolicitudes() << std::endl;
    if (!nodoActual) {  // Verifica si hay una solicitud actual
        std::cout << "No hay solicitudes en la lista o ya no hay más solicitudes." << std::endl;
        return;
    }

    const Solicitud& solicitud = nodoActual->solicitud;

    std::cout << "Nickname: " << solicitud.getNickname() << std::endl;
    std::cout << "Dificultad: " << solicitud.getDificultad() << std::endl;
    std::cout << "Puntos: " << solicitud.getPuntos() << std::endl;
    std::cout << "Descripción: " << solicitud.getDescripcion() << std::endl;
    // Puedes agregar más detalles aquí si lo deseas
}

/**
 * @brief Elimina la primera solicitud de la lista.
 */
void ListaSolicitudes::eliminarPrimeraSolicitud() {
    if (head == nullptr) {
        std::cout << "No hay solicitudes para eliminar." << std::endl;
        return;
    }

    Nodo* aux = head; // Guardar el nodo a eliminar
    head = head->next; // Mover la cabeza al siguiente nodo

    if (head == nullptr) {
        nodoActual = nullptr;
        cola = nullptr;
    } else {
        nodoActual = head; // Actualizar a la nueva cabeza
    }

    delete aux; // Liberar la memoria del nodo eliminado
}

/**
 * @brief Verifica si la lista está vacía.
 * @return true si la lista está vacía, false en caso contrario.
 */
bool ListaSolicitudes::estaVacia() const {
    return head == nullptr; // Si está vacía retorna true
}

/**
 * @brief Reinicia el puntero de la lista al principio.
 */
void ListaSolicitudes::reiniciarLista() {
    nodoActual = head;  // Reinicia el puntero al principio de la lista
}

/**
 * @brief Muestra la siguiente solicitud en la lista.
 */
void ListaSolicitudes::mostrarSiguienteSolicitud() {
    if (!nodoActual) {  // Si nodoActual es nulo, comenzamos desde el principio
        nodoActual = head;
    } else if (nodoActual->next) {  // Si hay un siguiente nodo
        nodoActual = nodoActual->next;  // Avanzar al siguiente nodo
    } else {
        std::cout << "Ya no hay más solicitudes." << std::endl;
        return;
    }

    mostrarSolicitudActual();  // Mostrar la solicitud actual
}

/**
 * @brief Crea un submenú para gestionar las solicitudes.
 * @param proyectos Referencia al arreglo dinámico de proyectos.
 */
void ListaSolicitudes::gestionarSolicitudes(ArregloDinamico& proyectos) {
    nodoActual = head; // Iniciar con el primer nodo
    while (!this->estaVacia()) {
        mostrarSolicitudActual();

        // Mostrar opciones del submenú
        std::cout << "\nOpciones:" << std::endl;
        std::cout << "1. Aceptar solicitud" << std::endl;
        std::cout << "2. Rechazar solicitud" << std::endl;
        std::cout << "3. Siguiente solicitud" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Aceptar solicitud
                if (nodoActual) {
                    const Solicitud& solicitud = nodoActual->solicitud;
                    std::string id = generarIDAleatorio(); // Genera un ID
                    std::string fechaActual = obtenerFechaActual(); // Obtiene la fecha actual

                    // Crea y agrega un nuevo proyecto al arreglo dinámico
                    Proyecto nuevoProyecto(solicitud.getNickname(), fechaActual, solicitud.getDescripcion(), solicitud.getDificultad(), id, false);
                    proyectos.agregar(nuevoProyecto);

                    std::cout << "Solicitud aceptada y convertida en proyecto." << std::endl;
                    this->eliminarPrimeraSolicitud(); // Elimina la solicitud
                    nodoActual = head; // Actualiza nodoActual al siguiente nodo
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 2: { // Rechazar solicitud
                if (this->getHead()) {
                    this->eliminarPrimeraSolicitud();
                    std::cout << "Solicitud rechazada y eliminada de la lista." << std::endl;
                    if (!this->estaVacia()) {
                        this->mostrarSolicitudActual(); // Mostrar la siguiente solicitud
                    } else {
                        std::cout << "No hay solicitudes en la lista." << std::endl;
                    }
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 3: { // Siguiente solicitud
                if (!this->estaVacia()) {
                    this->mostrarSiguienteSolicitud();
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Saliendo al menú principal..." << std::endl;
                return; // Sale del bucle y regresa al menú principal
            }
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    }
    std::cout << "No hay más solicitudes que gestionar. Intente más tarde." << std::endl;
}

/**
 * @brief Lee las solicitudes desde un archivo y las carga en la lista.
 */
void ListaSolicitudes::leerArchivoSolicitudes() {
    std::fstream file("solicitudes.csv");

    if (file.fail()) {
        std::cout << "Error abriendo el archivo" << "\n";
        return; // Cambia exit(1) a return
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Ignora líneas vacías
        }

        std::stringstream ss(line);
        std::string nickname, dificultadStr, puntosStr, fecha, ciudad, descripcion;

        // Leer los datos del archivo
        std::getline(ss, nickname, ';');
        std::getline(ss, dificultadStr, ';');
        std::getline(ss, puntosStr, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, ciudad, ';');
        std::getline(ss, descripcion, ';');

        if (puntosStr.empty()) {
            std::cout << "Puntos no válidos para la solicitud: " << line << std::endl;
            continue;
        }

        int puntos;
        try {
            puntos = std::stoi(puntosStr);
        } catch (const std::invalid_argument&) {
            std::cout << "Error convirtiendo puntos en la línea: " << line << std::endl;
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "Número fuera de rango en la línea: " << line << std::endl;
            continue;
        }

        Solicitud solicitud(nickname, fecha, descripcion, dificultadStr, puntos, ciudad);
        addSolicitud(solicitud);
    }
}