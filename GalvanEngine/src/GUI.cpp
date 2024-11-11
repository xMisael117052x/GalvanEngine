#include "GUI.h"

#include "ShapeFactory.h"
#include "Transform.h"
#include "Actor.h"

class
    ShapeFactory;

/**
 * @brief Inicializa la GUI y configura el estilo.
 */
void
GUI::init() {
    // Configurar estilo de GUI
    setupGUIStyle();
}

/**
 * @brief Actualiza la GUI. Este método puede ser extendido para incluir lógica de actualización en cada frame.
 */
void
GUI::update() {
}

/**
 * @brief Renderiza la GUI. Método utilizado para añadir lógica de renderizado.
 */
void
GUI::render() {
}

/**
 * @brief Destruye la GUI y libera los recursos asociados.
 */
void
GUI::destroy() {
}

/**
 * @brief Configura el estilo de la GUI utilizando colores y espaciamiento específicos.
 */
void
GUI::setupGUIStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Configuración general de estilo
    style.WindowRounding = 6.0f;
    style.FrameRounding = 4.0f;
    style.PopupRounding = 4.0f;
    style.ScrollbarRounding = 3.0f;
    style.GrabRounding = 3.0f;
    style.TabRounding = 4.0f;
    style.ChildRounding = 4.0f;
    style.FrameBorderSize = 1.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;
    style.TabBorderSize = 1.0f;

    // Definición de colores con un tema de interfaz de "Halo"
    ImVec4 black = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 darkGray = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    ImVec4 gray = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 lightGray = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    ImVec4 neonGreen = ImVec4(0.0f, 1.0f, 0.5f, 1.0f);
    ImVec4 neonBlue = ImVec4(0.0f, 0.7f, 1.0f, 1.0f);
    ImVec4 neonRed = ImVec4(1.0f, 0.2f, 0.2f, 1.0f);

    // Fondo de la ventana y elementos
    colors[ImGuiCol_WindowBg] = darkGray;
    colors[ImGuiCol_ChildBg] = darkGray;
    colors[ImGuiCol_PopupBg] = black;

    // Texto y bordes
    colors[ImGuiCol_Text] = neonGreen;
    colors[ImGuiCol_Border] = neonGreen;
    colors[ImGuiCol_BorderShadow] = gray;

    // Botones
    colors[ImGuiCol_Button] = gray;
    colors[ImGuiCol_ButtonHovered] = neonBlue;
    colors[ImGuiCol_ButtonActive] = neonRed;

    // Marcos y campos de entrada
    colors[ImGuiCol_FrameBg] = lightGray;
    colors[ImGuiCol_FrameBgHovered] = gray;
    colors[ImGuiCol_FrameBgActive] = darkGray;

    // Títulos y encabezados
    colors[ImGuiCol_TitleBg] = darkGray;
    colors[ImGuiCol_TitleBgActive] = gray;
    colors[ImGuiCol_TitleBgCollapsed] = darkGray;

    colors[ImGuiCol_Header] = neonGreen;
    colors[ImGuiCol_HeaderHovered] = neonBlue;
    colors[ImGuiCol_HeaderActive] = neonRed;

    // Tabs
    colors[ImGuiCol_Tab] = gray;
    colors[ImGuiCol_TabHovered] = neonBlue;
    colors[ImGuiCol_TabActive] = neonGreen;
    colors[ImGuiCol_TabUnfocused] = lightGray;
    colors[ImGuiCol_TabUnfocusedActive] = neonGreen;

    // Scrollbar
    colors[ImGuiCol_ScrollbarBg] = black;
    colors[ImGuiCol_ScrollbarGrab] = gray;
    colors[ImGuiCol_ScrollbarGrabHovered] = neonBlue;
    colors[ImGuiCol_ScrollbarGrabActive] = neonRed;

    // Sliders
    colors[ImGuiCol_SliderGrab] = gray;
    colors[ImGuiCol_SliderGrabActive] = neonGreen;

    // Checkbox y radio buttons
    colors[ImGuiCol_CheckMark] = neonGreen;

    // Separadores y líneas
    colors[ImGuiCol_Separator] = gray;
    colors[ImGuiCol_SeparatorHovered] = neonBlue;
    colors[ImGuiCol_SeparatorActive] = neonRed;

    // Menú
    colors[ImGuiCol_MenuBarBg] = darkGray;

    // Tooltip
    colors[ImGuiCol_TextSelectedBg] = neonBlue;
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.5f);

    // Ajustes de alineación y espaciado
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.ItemSpacing = ImVec2(8, 4);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.FramePadding = ImVec2(4, 2);
}

/**
 * @brief Muestra una consola con los mensajes del programa.
 * @param programMessages Mapa de mensajes del programa categorizados por tipo de error.
 */
void
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
    ImGui::Begin("Console");

    static ImGuiTextFilter filter;
    filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);

    ImGui::Separator();

    ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    for (const auto& [type, messages] : programMessages) {
        ImVec4 color;
        switch (type) {
        case ConsolErrorType::ERROR:
            color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
            break;
        case ConsolErrorType::WARNING:
            color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);
            break;
        case ConsolErrorType::INFO:
        default:
            color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
            break;
        }

        ImGui::PushStyleColor(ImGuiCol_Text, color);
        for (const std::string& message : messages) {
            if (filter.PassFilter(message.c_str())) {
                ImGui::Text("[%d] %s", static_cast<int>(type), message.c_str());
            }
        }
        ImGui::PopStyleColor();
    }

    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        ImGui::SetScrollHereY(1.0f);

    ImGui::EndChild();
    ImGui::End();
}

/**
 * @brief Inserta actores en la escena.
 */
void
GUI::placeActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
    ImGui::Begin("Place Actors", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::Text("Create a New Actor");

    static ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_CharsNoBlank;
    static char actorName[128] = "";
    ImGui::InputTextWithHint("##name", "Enter actor name", actorName, IM_ARRAYSIZE(actorName), input_text_flags);
    ImGui::Spacing();

    static int shapeType = 0;
    const char* shapeTypes[] = { "NONE", "CIRCLE", "RECTANGLE", "TRIANGLE" };
    ImGui::Combo("Shape Type", &shapeType, shapeTypes, IM_ARRAYSIZE(shapeTypes));
    ImGui::Spacing();

    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::Button("Create Actor", ImVec2(120, 0))) {
        EngineUtilities::TSharedPointer<Actor> newActor = EngineUtilities::MakeShared<Actor>(actorName);

        auto shapeFactory = newActor->getComponent<ShapeFactory>();
        if (shapeFactory) {
            switch (shapeType) {
            case 1:
                shapeFactory->createShape(ShapeType::CIRCLE);
                break;
            case 2:
                shapeFactory->createShape(ShapeType::RECTANGLE);
                break;
            case 3:
                shapeFactory->createShape(ShapeType::TRIANGLE);
                break;
            }
        }
        else {
            ImGui::TextColored(ImVec4(1.0f, 0.4f, 0.4f, 1.0f), "ShapeFactory component not found.");
        }

        actors.push_back(newActor);
        ImGui::TextColored(ImVec4(0.4f, 1.0f, 0.4f, 1.0f), "Actor created successfully.");
    }

    ImGui::End();
}

/**
 * @brief Muestra el outliner con la lista de actores.
 * @param actors Vector de actores a mostrar en el outliner.
 */
void
GUI::jerarquia(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
    ImGui::Begin("Jerarquia");

    for (size_t i = 0; i < actors.size(); ++i) {
        auto& actor = actors[i];
        if (actor.isNull())
            continue;

        ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;
        if (actor == m_actors)
            node_flags |= ImGuiTreeNodeFlags_Selected;

        bool node_open = ImGui::TreeNodeEx((void*)(intptr_t)i, node_flags, actor->getName().c_str());

        if (ImGui::IsItemClicked()) {
            m_actors = actor;
        }

        if (node_open) {
            const auto& components = actor->getComponents();
            for (const auto& component : components) {
                if (!component.isNull()) {
                    ImGui::BulletText("%s", component->getTypeName().c_str());
                }
            }
            ImGui::TreePop();
        }
    }

    ImGui::End();
}



/**
 * @brief Muestra el inspector que permite ver y editar las propiedades de los actores y sus componentes.
 * @param actors Vector de actores a mostrar en el inspector.
 */
void
GUI::inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
    ImGui::Begin("Inspector");

    if (m_actors) {
        auto& actor = m_actors;

        char actorName[128];
        snprintf(actorName, sizeof(actorName), "%s", actor->getName().c_str());
        if (ImGui::InputText("Name", actorName, sizeof(actorName))) {
            actor->setName(actorName);
        }

        const auto& components = actor->getComponents();
        for (size_t j = 0; j < components.size(); ++j) {
            auto& component = components[j];
            if (!component.isNull()) {
                ImGui::Text("%s", component->getTypeName().c_str());

                if (component->getTypeName() == "Transform") {
                    auto transform = actor->getComponent<Transform>();

                    if (transform) {
                        sf::Vector2f pos = transform->getPosition();
                        if (ImGui::DragFloat2("Position", &pos.x)) {
                            transform->setPosition(pos);
                        }

                        sf::Vector2f scale = transform->getScale();
                        if (ImGui::DragFloat2("Scale", &scale.x)) {
                            transform->setScale(scale);
                        }

                        sf::Vector2f rot = transform->getRotation();
                        if (ImGui::DragFloat2("Rotation", &rot.x)) {
                            transform->setRotation(rot);
                        }
                    }
                }
            }
        }
    }

    ImGui::End();
}