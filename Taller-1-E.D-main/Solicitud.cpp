//
// Created by ulloc on 17-09-2024.
//

#include "Solicitud.h"

/**
 *
 *
* @param nickname Nombre del solicitante o identificador del proyecto.
 * @param fecha Fecha de la solicitud (formato: DD/MM/AAAA).
 * @param descripcion Descripción detallada de la solicitud.
 * @param dificultad Nivel de dificultad asociado a la solicitud.
 * @param puntos Puntuación asignada a la solicitud.
 * @param ciudad Ciudad desde la cual se realiza la solicitud.
 */
Solicitud::Solicitud(std::string nickname, std::string fecha, std::string descripcion, std::string dificultad, int puntos, std::string ciudad)
    : Estructura(std::move(nickname), std::move(fecha), std::move(descripcion), dificultad),
      puntos(puntos), ciudad(std::move(ciudad)) {

}



