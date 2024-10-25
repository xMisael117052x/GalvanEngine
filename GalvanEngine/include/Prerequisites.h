#pragma once

// Librerias STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>

// Third Parties
#include <SFML/Graphics.hpp>
#include <TSharedPointer.h>
#include <TWeakPointer.h>
#include <TStaticPtr.h>
#include <TUniquePtr.h>

#include <imgui.h>
#include <imgui-SFML.h>

// Enums
enum
ShapeType {
    EMPTY = 0,
    CIRCLE = 1,
    RECTANGLE = 2,
    TRIANGLE = 3
};

// MACRO for safe release of resources
#define SAFE_PTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

#define MESSAGE(classObj, method, state)                      \
{                                                             \
std::ostringstream os_;                                   \
os_ << classObj << "::" << method << " : "                \
<< "[CREATION OF RESOURCE" << ": " << state "] \n";\
std::cerr << os_.str();                                   \
}

#define ERROR(classObj, method, errorMSG)                         \
{                                                                 \
std::ostringstream os_;                                       \
os_ << "ERROR : " << classObj << "::" << method << " : "      \
<< "  Error in data from params [" << errorMSG"] \n"; \
std::cerr << os_.str();                                       \
exit(1);                                                      \
}