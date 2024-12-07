#pragma once
#include "Prerequisites.h"

class Quaternion {
public:
    float w, x, y, z; ///< Componentes del cuaternión.
   
    /**
     * @brief Constructor por defecto que inicializa el cuaternión como una identidad.
     */
    Quaternion() : w(1), x(0), y(0), z(0) {}

    /**
     * @brief Constructor parametrizado para inicializar el cuaternión.
     * @param w Componente escalar del cuaternión.
     * @param x Componente x del vector del cuaternión.
     * @param y Componente y del vector del cuaternión.
     * @param z Componente z del vector del cuaternión.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Sobrecarga del operador * para multiplicar dos cuaterniones.
     * @param other Cuaternión con el que se multiplicará el cuaternión actual.
     * @return Resultado de la multiplicación de los cuaterniones.
     */
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Devuelve la magnitud del cuaternión.
     * @return Magnitud del cuaternión.
     */
    float magnitude() const {
        return std::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Normaliza el cuaternión.
     * @return Cuaternión normalizado.
     */
    Quaternion normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return Quaternion(1, 0, 0, 0);
        }
        return Quaternion(w / mag, x / mag, y / mag, z / mag);
    }

    /**
     * @brief Convierte el cuaternión a una matriz de rotación.
     * @param matrix Arreglo de 16 elementos para almacenar la matriz de rotación resultante.
     */
    void toRotationMatrix(float matrix[16]) const {
        matrix[0] = 1 - 2 * y * y - 2 * z * z;
        matrix[1] = 2 * x * y - 2 * z * w;
        matrix[2] = 2 * x * z + 2 * y * w;
        matrix[3] = 0;

        matrix[4] = 2 * x * y + 2 * z * w;
        matrix[5] = 1 - 2 * x * x - 2 * z * z;
        matrix[6] = 2 * y * z - 2 * x * w;
        matrix[7] = 0;

        matrix[8] = 2 * x * z - 2 * y * w;
        matrix[9] = 2 * y * z + 2 * x * w;
        matrix[10] = 1 - 2 * x * x - 2 * y * y;
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;
    }

    /**
     * @brief Crea un cuaternión a partir de un ángulo y un eje de rotación.
     * @param angle Ángulo de rotación en radianes.
     * @param ax Componente x del eje de rotación.
     * @param ay Componente y del eje de rotación.
     * @param az Componente z del eje de rotación.
     * @return Cuaternión que representa la rotación.
     */
    static Quaternion fromAxisAngle(float angle, float ax, float ay, float az) {
        float half_angle = angle / 2;
        float s = std::sin(half_angle);
        return Quaternion(std::cos(half_angle), ax * s, ay * s, az * s);
    }
};