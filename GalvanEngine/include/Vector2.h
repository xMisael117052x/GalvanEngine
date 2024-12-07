#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que representa un vector 2D con operaciones básicas.
 */
class Vector2
{
public:
    float x, y; ///< Componentes del vector en los ejes X e Y.

    /**
     * @brief Constructor por defecto que inicializa un vector en el origen (0,0).
     */
    Vector2() : x(0), y(0)
    {
    }

    /**
     * @brief Constructor que inicializa el vector con valores dados.
     * @param x Valor en el eje X.
     * @param y Valor en el eje Y.
     */
    Vector2(float x, float y) : x(x), y(y)
    {
    }

    /**
     * @brief Sobrecarga del operador de suma acumulada para vectores.
     * @param other Otro vector que será sumado.
     * @return Referencia al vector actual tras la suma.
     */
    Vector2& operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    /**
     * @brief Sobrecarga del operador de suma para vectores.
     * @param other Otro vector que será sumado.
     * @return Un nuevo vector que es la suma de este vector y el otro.
     */
    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    /**
     * @brief Sobrecarga del operador de resta para vectores.
     * @param other Otro vector que será restado.
     * @return Un nuevo vector que es la resta de este vector y el otro.
     */
    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por un escalar.
     * @param scalar Escalar por el cual multiplicar el vector.
     * @return Un nuevo vector escalado.
     */
    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    /**
     * @brief Calcula la magnitud (longitud) del vector.
     * @return La magnitud del vector.
     */
    float magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    /**
     * @brief Normaliza el vector para que tenga una longitud de 1.
     * @return Un nuevo vector normalizado.
     */
    Vector2 normalize() const
    {
        float mag = magnitude();
        if (mag == 0)
        {
            return Vector2(0, 0);
        }
        return Vector2(x / mag, y / mag);
    }
};
