//
// Created by ulloc on 17-09-2024.
//

#ifndef SOLICITUDES_H
#define SOLICITUDES_H
#include "Estructura.h"

/**
 * @file Solicitud.h
 * @brief Declaración de la clase Solicitud, que hereda de Estructura.
 *
 * Esta clase representa una solicitud que hereda de la clase Estructura. Contiene
 * atributos específicos como puntos y ciudad, además de otros heredados.
 * La clase proporciona métodos para acceder a estos atributos.
 */

/**
 * @class Solicitud
 * @brief Clase que representa una solicitud dentro del sistema.
 *
 * La clase `Solicitud` hereda de la clase base `Estructura` y añade atributos específicos
 * como puntos y ciudad. Además, proporciona métodos para obtener estos valores.
 */
class Solicitud: public Estructura{


public:
    /**
    * @brief Constructor de la clase Solicitud.
    *
    * Inicializa una nueva instancia de la clase `Solicitud` con el nickname, fecha,
    * descripción, dificultad, puntos y ciudad proporcionados.
    *
    * @param nickname Nombre del solicitante o identificador del proyecto.
    * @param fecha Fecha de la solicitud (formato: DD/MM/AAAA).
    * @param descripcion Descripción detallada de la solicitud.
    * @param dificultad Nivel de dificultad asociado a la solicitud.
    * @param puntos Puntuación asignada a la solicitud.
    * @param ciudad Ciudad desde la cual se realiza la solicitud.
    */
    Solicitud(std::string nickname, std::string fecha,std::string descripcion, std::string dificultad, int puntos, std::string ciudad);
    /**
* @brief Obtiene los puntos asociados a la solicitud.
*
* @return Un entero que representa la puntuación de la solicitud.
*/
    [[nodiscard]] int getPuntos()const  {
        return puntos;
    }
    /**
    * @brief Obtiene la ciudad desde la cual se realiza la solicitud.
    *
    * @return Una cadena de texto que representa la ciudad.
    */
    [[nodiscard]] std::string getCiudad()  const{
        return ciudad;
    }

private:
    int puntos; ///< Puntuación asignada a la solicitud.
    std::string ciudad; ///< Ciudad de origen de la solicitud.







};



#endif //SOLICITUDES_H
