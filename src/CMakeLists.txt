set(SOURCES
        ExampleClass.cpp
        Board.cc
        Pixel.cc
        Activity.cc
        )


set(HEADERS
        ExampleClass.h
        Board.h
        Pixel.h
        Activity.h
        )

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})