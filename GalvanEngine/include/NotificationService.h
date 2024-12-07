#pragma once
#include "Prerequisites.h"

class NotificationService
{
public:
    /**
     * @brief Obtiene la instancia única de NotificationService (patrón Singleton).
     * @return Referencia a la instancia única de NotificationService.
     */
    static NotificationService& getInstance()
    {
        static NotificationService instance;
        return instance;
    }

    /**
     * @brief Añade un mensaje a la lista de mensajes de un código de error.
     * @param code Código de error al que se añadirá el mensaje.
     * @param message Mensaje que se agregará al código de error correspondiente.
     */
    void addMessage(ConsolErrorType code, const std::string& message)
    {
        m_programMessages[code].push_back(message);
    }

    /**
     * @brief Registra un mensaje informativo.
     * @param message Mensaje informativo a añadir.
     */
    void Log(const std::string& message)
    {
        ConsolErrorType code = ConsolErrorType::INFO;
        m_programMessages[code].push_back(message);
    }

    /**
     * @brief Obtiene todos los mensajes asociados a un código de error específico.
     * @param code Código de error para el cual se obtendrán los mensajes.
     * @return Cadena de texto con los mensajes combinados del código de error especificado.
     */
    std::string getMessage(ConsolErrorType code) const
    {
        auto it = m_programMessages.find(code);
        if (it != m_programMessages.end())
        {
            std::string combinedMessages;
            for (const auto& message : it->second)
            {
                combinedMessages += message + "\n";
            }
            return combinedMessages;
        }
        else
        {
            return "Message not found";
        }
    }

    /**
     * @brief Muestra todos los mensajes almacenados en la consola.
     */
    void showAllMessages() const
    {
        for (const auto& pair : m_programMessages)
        {
            std::cout << "Code: " << pair.first << " - Messages: " << std::endl;
            for (const auto& message : pair.second)
            {
                std::cout << "   " << message << std::endl;
            }
        }
    }

    /**
     * @brief Guarda todos los mensajes en un archivo especificado.
     * @param filename Nombre del archivo donde se guardarán los mensajes.
     */
    void saveMessagesToFile(const std::string& filename) const
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "No se pudo abrir el archivo para guardar los mensajes." << std::endl;
            return;
        }

        for (const auto& pair : m_programMessages)
        {
            file << "Code: " << pair.first << " - Messages: " << std::endl;
            for (const auto& message : pair.second)
            {
                file << "   " << message << "\n";
            }
        }

        file.close();
        std::cout << "Mensajes guardados en el archivo: " << filename << std::endl;
    }

    /**
     * @brief Obtiene el mapa completo de notificaciones.
     * @return Referencia al mapa que contiene las notificaciones.
     */
    std::map<ConsolErrorType, std::vector<std::string>>& getNotifications()
    {
        return m_programMessages;
    }

private:
    std::map<ConsolErrorType, std::vector<std::string>> m_programMessages;
    ///< Mapa de mensajes del programa por código de error.

    // Constructor privado para implementar el patrón Singleton evitando instancias múltiples.
    NotificationService()
    {
    }

    // Eliminar el operador de copia para evitar duplicaciones.
    NotificationService(const NotificationService&) = delete;

    // Eliminar el operador de asignación para evitar duplicaciones.
    NotificationService& operator=(const NotificationService&) = delete;
};
