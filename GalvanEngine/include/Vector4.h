#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que representa un vector 4D con operaciones básicas.
 */
class Vector4
{
public:
    float x, y, z, w; ///< Componentes del vector en los ejes X, Y, Z y W.

    /**
     * @brief Constructor por defecto que inicializa un vector en el origen (0,0,0,0).
     */
    Vector4() : x(0), y(0), z(0), w(0)
    {
    }

    /**
     * @brief Constructor que inicializa el vector con valores dados.
     * @param x Valor en el eje X.
     * @param y Valor en el eje Y.
     * @param z Valor en el eje Z.
     * @param w Valor en el eje W.
     */
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
    {
    }

    /**
     * @brief Sobrecarga del operador de suma para vectores.
     * @param other Otro vector que será sumado.
     * @return Un nuevo vector que es la suma de este vector y el otro.
     */
    Vector4 operator+(const Vector4& other) const
    {
        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /**
     * @brief Sobrecarga del operador de resta para vectores.
     * @param other Otro vector que será restado.
     * @return Un nuevo vector que es la resta de este vector y el otro.
     */
    Vector4 operator-(const Vector4& other) const
    {
        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por un escalar.
     * @param scalar Escalar por el cual multiplicar el vector.
     * @return Un nuevo vector escalado.
     */
    Vector4 operator*(float scalar) const
    {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /**
     * @brief Calcula la magnitud (longitud) del vector.
     * @return La magnitud del vector.
     */
    float magnitude() const
    {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Normaliza el vector para que tenga una longitud de 1.
     * @return Un nuevo vector normalizado.
     */
    Vector4 normalize() const
    {
        float mag = magnitude();
        if (mag == 0)
        {
            return Vector4(0, 0, 0, 0);
        }
        return Vector4(x / mag, y / mag, z / mag, w / mag);
    }
};
