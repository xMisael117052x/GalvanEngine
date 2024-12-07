#pragma once
#include "Prerequisites.h"

class ResourceManager
{
public:
    /**
     * @brief Obtiene la instancia única de ResourceManager, siguiendo el patrón Singleton.
     * @return Referencia a la instancia única de ResourceManager.
     */
    static ResourceManager& getInstance()
    {
        static ResourceManager instance;
        return instance;
    }

    /**
     * @brief Carga una textura desde un archivo y la almacena si no está previamente cargada.
     * @param fileName Nombre del archivo de la textura.
     * @param extension Extensión del archivo de la textura.
     * @return Verdadero si la textura ya está cargada o si se carga exitosamente, falso si falla.
     */
    bool loadTexture(const std::string& fileName, const std::string& extension)
    {
        // Verificar si la textura ya está cargada
        if (m_textures.find(fileName) != m_textures.end())
        {
            return true;
        }
        // Crear y cargar la textura
        EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>(fileName, extension);
        m_textures[fileName] = texture;
        return true; // Asumimos aquí que siempre se carga correctamente para propósitos del ejemplo
    }

    /**
     * @brief Obtiene una textura ya cargada por su nombre de archivo.
     * @param fileName Nombre del archivo de la textura.
     * @return Puntero compartido a la textura si se encuentra; una textura por defecto si no se encuentra.
     */
    EngineUtilities::TSharedPointer<Texture> getTexture(const std::string& fileName)
    {
        // Verificar si la textura existe
        auto it = m_textures.find(fileName);
        if (it != m_textures.end())
        {
            return it->second; // Devolver la textura
        }
        std::cout << "Texture not found: " << fileName << std::endl;
        // Crear y cargar una textura por defecto
        EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>("default", "png");
        m_textures["Default"] = texture;
        return texture;
    }

private:
    // Mapa para almacenar texturas cargadas, indexadas por nombre de archivo
    std::unordered_map<std::string, EngineUtilities::TSharedPointer<Texture>> m_textures;

    // Constructor privado para evitar instancias múltiples
    ResourceManager() = default;

    // Destructor por defecto
    ~ResourceManager() = default;

    // Eliminar el operador de copia para evitar duplicaciones
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
};
