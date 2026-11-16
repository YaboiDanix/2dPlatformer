add_executable(Box2D_Starter main.cpp
        src/object.cpp
        include/object.h
        src/Entity.cpp
        include/Entity.h
        include/constants.h
        include/sensor.h
        src/sensor.cpp
        include/contacts.h
        include/danger.h
        src/danger.cpp
        src/Obstacle.cpp
        include/Obstacle.h
        include/game.h
        src/game.cpp)

target_link_libraries(Box2D_Starter PUBLIC SFML::Graphics SFML::Audio box2d::box2d)