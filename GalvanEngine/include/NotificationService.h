#pragma once
#include "Prerequisites.h"

/**
 * @class NotificationService
 * @brief Servicio singleton para manejar notificaciones y mensajes del programa.
 */
class
NotificationService {
public:
    /**
     * @brief Obtiene la instancia única del servicio de notificaciones.
     * @return Referencia a la instancia de NotificationService.
     */
    static
	NotificationService& getInstance() {
        static NotificationService instance;
        return instance;
    }

    /**
     * @brief Añade un mensaje a la lista de mensajes de un código de error.
     * @param code Código del error.
     * @param message Mensaje a añadir.
     */
    void
	addMessage(ConsolErrorType code, const std::string& message) {
        m_programMessages[code].push_back(message);
    }

    /**
     * @brief Agrega un mensaje informativo.
     * @param message Mensaje informativo a agregar.
     */
    void
	Log(const std::string& message) {
        ConsolErrorType code = ConsolErrorType::INFO;
        m_programMessages[code].push_back(message);
    }

    /**
     * @brief Obtiene todos los mensajes de un código de error específico.
     * @param code Código del error.
     * @return Los mensajes combinados separados por saltos de línea.
     */
    std::string
	getMessage(ConsolErrorType code) const {
        auto it = m_programMessages.find(code);
        if (it != m_programMessages.end()) {
            std::string combinedMessages;
            for (const auto& message : it->second) {
                combinedMessages += message + "\n";
            }
            return combinedMessages;
        }
        else {
            return "Message not found";
        }
    }

    /**
     * @brief Muestra todos los mensajes en la consola.
     */
    void
	showAllMessages() const {
        for (const auto& pair : m_programMessages) {
            std::cout << "Code: " << pair.first << " - Messages: " << std::endl;
            for (const auto& message : pair.second) {
                std::cout << "   " << message << std::endl;
            }
        }
    }

    /**
     * @brief Guarda todos los mensajes en un archivo.
     * @param filename Nombre del archivo donde se guardarán los mensajes.
     */
    void
	saveMessagesToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo para guardar los mensajes." << std::endl;
            return;
        }

        for (const auto& pair : m_programMessages) {
            file << "Code: " << pair.first << " - Messages: " << std::endl;
            for (const auto& message : pair.second) {
                file << "   " << message << "\n";
            }
        }

        file.close();
        std::cout << "Mensajes guardados en el archivo: " << filename << std::endl;
    }

    /**
     * @brief Obtiene el mapa completo de notificaciones.
     * @return Referencia al mapa de notificaciones.
     */
    std::map<ConsolErrorType, std::vector<std::string>>&
    getNotifications() {
        return m_programMessages;
    }

private:

    std::map<ConsolErrorType, std::vector<std::string>> m_programMessages;


    NotificationService() {}


    NotificationService(const NotificationService&) = delete;


    NotificationService& operator=(const NotificationService&) = delete;
};