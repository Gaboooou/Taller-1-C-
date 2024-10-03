cmake_minimum_required(VERSION 3.29)
project(Taller_E_Datos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_E_Datos main.cpp
        Estructura.cpp
        Estructura.h
        Solicitud.cpp
        Solicitud.h
        Proyecto.cpp
        Proyecto.h
        BuildTheEarth.h
        BuildTheEarth.cpp
        ArregloDinamico.cpp
        ArregloDinamico.h
        ListaSolicitudes.cpp
)
