//
// Created by Gabriel Briones on 9/27/2024.
//

#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include "Proyecto.h"

/**
 * @class ArregloDinamico
 * @brief Clase que representa un arreglo dinámico de objetos Proyecto.
 *
 * Esta clase proporciona métodos para agregar, eliminar y filtrar proyectos,
 * así como para gestionar el tamaño del arreglo dinámico.
 */
class ArregloDinamico {

public:
    ArregloDinamico(); // Constructor que inicializa el arreglo dinámico.
    ~ArregloDinamico(); // Destructor que libera la memoria utilizada por el arreglo.

    /**
     * @brief Obtiene la cantidad de elementos en el arreglo.
     * @return Número de elementos almacenados en el arreglo.
     */
    int getAmount();

    /**
     * @brief Agrega un nuevo proyecto al final del arreglo.
     * @param data Proyecto a agregar.
     */
    void agregar(Proyecto data);

    /**
     * @brief Elimina un proyecto del arreglo en la posición especificada.
     * @param index Índice del proyecto a eliminar.
     */
    void eliminar(int index);

    /**
     * @brief Obtiene la posición de un proyecto específico en el arreglo.
     * @param data Proyecto cuya posición se desea obtener.
     * @return Índice del proyecto en el arreglo o -1 si no se encuentra.
     */
    int obtenerPosicion(const Proyecto &data);

    /**
     * @brief Aplica filtros a los proyectos almacenados en el arreglo.
     *
     * Permite filtrar proyectos basándose en diferentes criterios, como finalizados,
     * año, mes, nickname y dificultad.
     *
     * @param filtroFinalizado Indica si se aplica el filtro de proyectos finalizados.
     * @param aplicarFiltros Controla si se deben aplicar los filtros seleccionados.
     * @param filtroAnio Indica si se aplica el filtro por año.
     * @param filtroMes Indica si se aplica el filtro por mes.
     * @param filtroNickname Indica si se aplica el filtro por nickname.
     * @param filtroDificultad Indica si se aplica el filtro por dificultad.
     * @param anio Año para el filtro por año.
     * @param mes Mes para el filtro por mes.
     * @param nickname Nickname para el filtro por nickname.
     * @param dificultad Dificultad para el filtro por dificultad.
     */
    void AplicarFiltro(bool filtroFinalizado, bool aplicarFiltros, bool filtroAnio, bool filtroMes, bool filtroNickname, bool filtroDificultad, std::string anio, std::string mes, std::string nickname, std::string dificultad);

    /**
     * @brief Calcula y muestra los porcentajes de proyectos según su dificultad.
     */
    void Porcentajes();

    /**
     * @brief Muestra la información de todos los proyectos en el arreglo.
     */
    void mostrarInformacion();

    /**
     * @brief Recorre el arreglo dinámico y realiza una acción con cada proyecto.
     * @param arr Puntero al arreglo de proyectos a recorrer.
     */
    void recorrerArregloDinamico(Proyecto *arr);

    /**
     * @brief Inserta un proyecto en el arreglo en la posición especificada.
     * @param data Proyecto a insertar.
     * @param index Índice donde se desea insertar el proyecto.
     */
    void insertar(Proyecto data, int index);

    /**
     * @brief Expande el tamaño del arreglo dinámico cuando se alcanza su capacidad máxima.
     */
    void expandir();

    /**
     * @brief Reduce el tamaño del arreglo dinámico si hay espacio sobrante.
     */
    void shrink();

    /**
     * @brief Lee proyectos desde un archivo y los agrega al arreglo dinámico.
     */
    void leerArchivoProyectos();

    void volverAEvaluarProyecto();

   private:
    int size; // Tamaño actual del arreglo.
    int amount; // Cantidad de elementos en el arreglo.
    Proyecto *arr; // Puntero al arreglo de proyectos.
};

#endif //ARREGLODINAMICO_H