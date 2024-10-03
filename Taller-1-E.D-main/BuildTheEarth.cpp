//
// Created by Gabriel Briones on 9/22/2024.
//

#include "BuildTheEarth.h"

#include <fstream>
#include <iostream>

#include "ArregloDinamico.h"
#include "ListaSolicitudes.h"

ListaSolicitudes listaSolicitudes; // Instancia global de ListaSolicitudes
ArregloDinamico proyectos; // Instancia global de ArregloDinamico para proyectos

/**
 * @brief Muestra el menú de filtros y permite al usuario seleccionar opciones para filtrar proyectos.
 *
 * Este método controla el flujo del menú de filtros, permitiendo al usuario elegir
 * diferentes criterios de filtrado y aplicarlos a la lista de proyectos.
 */
void menuDeFiltro() {
    int opcion;
    bool aplicarFiltros = false; // Controla si se van a aplicar los filtros seleccionados
    bool filtroFinalizado = false;
    bool filtroAnio = false;
    bool filtroMes = false;
    bool filtroNickname = false;
    bool filtroDificultad = false;
    std::string anio;
    std::string mes;
    std::string dificultad;
    std::string nickname;

    do {
        std::cout << "-------------- Menu de filtro --------------" << std::endl;
        std::cout << "[1] Filtro proyecto finalizado" << std::endl;
        std::cout << "[2] Filtro proyecto por año ingresado" << std::endl;
        std::cout << "[3] Filtro proyecto por mes ingresado" << std::endl;
        std::cout << "[4] Filtro proyecto por nickname ingresado" << std::endl;
        std::cout << "[5] Filtro proyecto por dificultad" << std::endl;
        std::cout << "[6] Aplicar filtros y mostrar proyectos" << std::endl;
        std::cout << "[7] Volver al menú principal" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                filtroFinalizado = true;
                std::cout << "Filtro por proyectos finalizados activado." << std::endl;
                break;
            case 2:
                filtroAnio = true;
                std::cout << "Ingrese el año del proyecto que desea buscar: ";
                std::cin >> anio;
                break;
            case 3:
                filtroMes = true;
                std::cout << "Ingrese el mes (como número, 1-12): ";
                std::cin >> mes;
                break;
            case 4:
                filtroNickname = true;
                std::cout << "Ingrese el nickname del proyecto: ";
                std::cin >> nickname;
                break;
            case 5:
                filtroDificultad = true;
                std::cout << "Ingrese la dificultad del proyecto (1-5): ";
                std::cin >> dificultad;
                break;
            case 6:
                // Se aplican los filtros seleccionados
                aplicarFiltros = true;
                break;
        }

        if (aplicarFiltros) {
            proyectos.AplicarFiltro(filtroFinalizado, aplicarFiltros, filtroAnio, filtroMes, filtroNickname, filtroDificultad, anio, mes, nickname, dificultad);

            // Reiniciar los filtros para la siguiente vez
            aplicarFiltros = false;
            filtroFinalizado = filtroAnio = filtroMes = filtroNickname = filtroDificultad = false;
        }

    } while (opcion != 7); // Continuar hasta que el usuario decida salir
}

/**
 * @brief Muestra el menú principal del programa.
 *
 * Este método permite al usuario seleccionar entre varias opciones como
 * revisar solicitudes, buscar proyectos, volver a evaluar proyectos y ver estadísticas.
 */
void menu() {
    int opcion;
    do {
        std::cout << "\nMenu Principal:\n";
        std::cout << "1. Revisar Solicitudes\n";
        std::cout << "2. Busqueda de Proyectos\n";
        std::cout << "3. Volver a Evaluar el Proyecto\n";
        std::cout << "4. Estadisticas\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                // Lógica para la gestión de solicitudes
                listaSolicitudes.gestionarSolicitudes(proyectos);
                break;
            case 2:
                // Lógica para búsqueda de proyectos
                menuDeFiltro();
                break;
            case 3:
                // Lógica para volver a evaluar el proyecto
                proyectos.volverAEvaluarProyecto();
                break;
            case 4:
                // Lógica para estadísticas
                proyectos.Porcentajes();
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5); // Continuar hasta que el usuario decida salir
}

/**
 * @brief Constructor de la clase BuildTheEarth.
 *
 * Inicializa una nueva instancia de la clase BuildTheEarth,
 * lee los archivos de proyectos y solicitudes, y muestra el menú principal.
 */
BuildTheEarth::BuildTheEarth() {
    proyectos.leerArchivoProyectos(); // Lee los proyectos desde un archivo
    listaSolicitudes.leerArchivoSolicitudes(); // Lee las solicitudes desde un archivo

    menu(); // Muestra el menú principal
}

/**
 * @brief Permite volver a evaluar un proyecto basado en su ID.
 *
 * Este método solicita al usuario un ID de proyecto y lo busca en la lista de proyectos.
 * Si se encuentra el proyecto, se crea una nueva solicitud y se agrega a la lista de solicitudes.
 *
 * @return void
 */
void ArregloDinamico::volverAEvaluarProyecto() {
    std::cout << "Ingrese el ID del proyecto que desea volver a evaluar: ";
    std::string id;
    std::cin >> id;

    // Verificar si el ID es válido
    bool proyectoEncontrado = false;

    for (int i = 0; i < this->amount; i++) {
        Proyecto proyecto = arr[i];
        if (proyecto.getID() == id) {
            proyectoEncontrado = true;

            // Crear una nueva solicitud basada en el proyecto encontrado
            Solicitud nuevaSolicitud(proyecto.getNickname(), listaSolicitudes.obtenerFechaActual(), proyecto.getDescripcion(), proyecto.getDificultad(), 1000, "");
            listaSolicitudes.addSolicitud(nuevaSolicitud); // Agregar la solicitud a la lista
            this->eliminar(i); // Eliminar el proyecto de la lista de proyectos

            break;
        }
    }

    if (!proyectoEncontrado) {
        std::cout << "El ID del proyecto no es válido." << std::endl;
        return; // Regresar al menú si el ID no es válido
    }

    std::cout << "El proyecto ha sido revertido y agregado a la lista de solicitudes." << std::endl;
}