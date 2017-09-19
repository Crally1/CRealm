TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/user/include/SFML/"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -slfml-network -lsfml-window -lsfml-system

CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system


SOURCES += src/main.cpp \
    src/entity.cpp \
    src/game.cpp \
    src/player_entity.cpp \
    src/texture_holder.cpp \
    src/world.cpp \
    src/scene_node.cpp \
    src/sprite_node.cpp

HEADERS += \
    src/entity.h \
    src/game.h \
    src/texture_holder.h \
    src/world.h \
    src/player_entity.h \
    src/scene_node.h \
    src/sprite_node.h
