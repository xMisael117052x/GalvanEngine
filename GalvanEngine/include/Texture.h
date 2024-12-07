#pragma once
#include "Prerequisites.h"

class Texture : public Component
{
public:
    /**
     * @brief Constructor por defecto de la textura.
     */
    Texture() = default;

    /**
     * @brief Constructor que inicializa la textura con nombre y extensión de archivo.
     * @param textureName Nombre del archivo de textura sin extensión.
     * @param extension Extensión del archivo de textura.
     */
    Texture(std::string textureName, std::string extension)
        : m_textureName(textureName),
          m_extension(extension),
          Component(ComponentType::TEXTURE)
    {
        if (!m_texture.loadFromFile(m_textureName + "." + m_extension))
        {
            std::cout << "Error de carga de textura: " << m_textureName << "." << m_extension << std::endl;
        }
    }

    /**
     * @brief Destructor virtual por defecto.
     */
    virtual ~Texture() = default;

    /**
     * @brief Obtiene la textura de SFML.
     * @return Referencia a la textura de SFML cargada.
     */
    sf::Texture& getTexture()
    {
        return m_texture;
    }

    /**
     * @brief Actualiza el estado de la textura.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void update(float deltaTime) override
    {
        // Lógica de actualización de la textura (si es necesario)
    }

    /**
     * @brief Renderiza la textura en la ventana proporcionada.
     * @param window Ventana para operaciones gráficas.
     */
    void render(Window window) override
    {
        // Lógica de renderizado de la textura (si es necesario)
    }

private:
    std::string m_textureName; ///< Nombre del archivo de textura.
    std::string m_extension; ///< Extensión del archivo de textura.
    sf::Texture m_texture; ///< Textura de SFML gestionada.
};
