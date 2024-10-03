//
// Created by ulloc on 22-09-2024.
//

#ifndef PROYECTO_H
#define PROYECTO_H
#include "Estructura.h"

/**
 * @class Proyecto
 * @brief Clase que representa un proyecto, hereda de la clase Estructura.
 */
class Proyecto: public Estructura{

public:
    /**
   * @brief Constructor por defecto de Proyecto.
   * Inicializa los valores por defecto para los atributos.
   */
    Proyecto()
        : Estructura("default_nickname", "default_fecha", "default_descripcion", "default_dificultad"),
          id("default_id"), finalizado(false) {}
    /**
        * @brief Constructor parametrizado de Proyecto.
        * @param id Identificador único del proyecto.
        * @param nickname Apodo o identificador del creador del proyecto.
        * @param fecha Fecha de creación del proyecto.
        * @param descripcion Descripción breve del proyecto.
        * @param dificultad Nivel de dificultad del proyecto.
        * @param finalizado Estado del proyecto (true si está finalizado, false en caso contrario).
        */
    Proyecto(std::string id, std::string nickname, std::string fecha, std::string descripcion, std::string dificultad, bool finalizado)
        : Estructura(nickname, fecha, descripcion, dificultad), id(id), finalizado(finalizado) {
    }

    /**
        * @brief Obtiene el ID del proyecto.
        * @return El ID del proyecto como una cadena de texto.
        */
    [[nodiscard]] std::string getID() const {
        return id;
    }
    /**
      * @brief Verifica si el proyecto está finalizado.
      * @return true si el proyecto está finalizado, false en caso contrario.
      */
    [[nodiscard]] bool getFinalizado() const {
        return finalizado;
    }
    // Operador de igualdad
    friend bool operator==(const Proyecto & lhs, const Proyecto & rhs) = default;



private:
    std::string id;  ///< Identificador único del proyecto.
    bool finalizado; ///< Indica si el proyecto está finalizado.

};





#endif //PROYECTO_H
