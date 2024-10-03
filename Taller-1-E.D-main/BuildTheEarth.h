//
// Created by Gabriel Briones on 9/22/2024.
//

#ifndef BUILDTHEEARTH_H
#define BUILDTHEEARTH_H

#include <string>


/**
 * @class BuildTheEarth
 * @brief Clase que gestiona la lógica y las operaciones para el proyecto "Build The Earth".
 *
 * Esta clase proporciona métodos para filtrar y analizar los proyectos,
 * así como para gestionar la evaluación de solicitudes y realizar
 * estadísticas sobre la dificultad y la aceptación de los usuarios.
 */
class BuildTheEarth {
public:
    /**
     * @brief Constructor de la clase BuildTheEarth.
     *
     * Inicializa una nueva instancia de la clase BuildTheEarth.
     */
    BuildTheEarth();



    /**
     * @brief Devuelve un proyecto a evaluación basado en el nickname del usuario.
     *
     * @param nickname El nickname del usuario para identificar el proyecto a volver a evaluar.
     */
    void volverEvaluacion(std::string nickname);



};

#endif //BUILDTHEEARTH_H