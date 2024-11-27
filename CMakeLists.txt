cmake_minimum_required(VERSION 3.10)
project(SO_I_24_FacundoGuerrero2 C)

set(CMAKE_C_STANDARD 99)

# Directorios donde están las cabeceras
include_directories(include)

# Enlaza la biblioteca prom, que ya se instaló con make install
find_library(PROM_LIB prom)

# Añadir los subdirectorios de las bibliotecas (lib)
add_subdirectory(lib/promhttp)

# Archivos fuente de tu proyecto
set(SOURCES
    src/main.c
    src/metrics.c
    src/expose_metrics.c
)

# Crear el ejecutable con los archivos fuente
add_executable(METRICAS ${SOURCES})

# Enlazar las bibliotecas que están en prom y promhttp
target_link_libraries(METRICAS ${PROM_LIB} promhttp pthread microhttpd)
