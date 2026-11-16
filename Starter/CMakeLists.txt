add_executable(Starter src/main.cpp
        game.cpp
        src/game.h
        src/joueur.cpp
        src/joueur.h

)

target_link_libraries(Starter PUBLIC SFML::Graphics)