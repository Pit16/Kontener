
project(Kontener)
cmake_minimum_required(VERSION 2.8)
file(GLOB PLIKI_ZRODLOWE *.cpp)
file(GLOB PLIKI_NAGLOWKOWE *.h)
add_executable(Kontener ${PLIKI_ZRODLOWE} ${PLIKI_NAGLOWKOWE})

