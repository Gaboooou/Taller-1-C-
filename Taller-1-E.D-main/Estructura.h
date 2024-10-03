//
// Created by ulloc on 17-09-2024.
//

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <string>

/**
 * @class Estructura
 * @brief Clase base que representa una estructura con información común.
 *
 * Esta clase contiene información general que es compartida por otras
 * clases derivadas, como Solicitud y Proyecto. Proporciona métodos
 * para acceder a los atributos básicos de la estructura.
 */
class Estructura {
public:
    /**
     * @brief Constructor de la clase Estructura.
     *
     * @param nickname Nombre de usuario o apodo asociado a la estructura.
     * @param fecha Fecha relacionada con la estructura.
     * @param descripcion Descripción de la estructura.
     * @param dificultad Dificultad asociada a la estructura.
     */
    Estructura(std::string nickname, std::string fecha, std::string descripcion, std::string dificultad);

    /**
     * @brief Obtiene el nickname de la estructura.
     *
     * @return std::string El nickname de la estructura.
     */
    [[nodiscard]] std::string getNickname() const {
        return nickname;
    }

    /**
     * @brief Obtiene la fecha de la estructura.
     *
     * @return std::string La fecha de la estructura.
     */
    [[nodiscard]] std::string getFecha() const {
        return fecha;
    }

    /**
     * @brief Obtiene la descripción de la estructura.
     *
     * @return std::string La descripción de la estructura.
     */
    [[nodiscard]] std::string getDescripcion() const {
        return descripcion;
    }

    /**
     * @brief Obtiene la dificultad de la estructura.
     *
     * @return std::string La dificultad de la estructura.
     */
    [[nodiscard]] std::string getDificultad() const {
        return dificultad;
    }

    /**
 * @brief Operador de igualdad para comparar dos estructuras.
 *
 * @param estructura La estructura a comparar.
 * @return true Si las estructuras son iguales.
 * @return false Si las estructuras son diferentes.
 */
    bool operator==(const Estructura &estructura) const = default;

private:
    std::string nickname;     ///< Nombre de usuario o apodo.
    std::string fecha;        ///< Fecha relacionada.
    std::string descripcion;  ///< Descripción.
    std::string dificultad;    ///< Dificultad.
};

#endif //ESTRUCTURA_H