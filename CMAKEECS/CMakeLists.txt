cmake_minimum_required(VERSION 3.10)
project(GameEngine)

# Spécifiez les fichiers source
set(SOURCES src/collide_system.cpp src/controller_system.cpp src/draw_system.cpp src/Entity.cpp src/GameEngine.cpp src/gravity_system.cpp src/onclickloadscene_system.cpp src/position_system.cpp src/quit_system.cpp src/Scene.cpp src/shoot_system.cpp)

# Ajoutez les fichiers source à la bibliothèque
add_library(mylib STATIC ${SOURCES})

# Spécifiez les dossiers d'inclusion
target_include_directories(mylib PUBLIC include)

# Trouvez SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Liez SFML à la bibliothèque
target_link_libraries(mylib sfml-graphics sfml-audio)

# Ajoutez l'exécutable main.cpp
add_executable(main main.cpp)

# Liez l'exécutable à la bibliothèque
target_link_libraries(main mylib)
