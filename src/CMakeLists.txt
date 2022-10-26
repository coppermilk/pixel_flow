set(SOURCES
        Board.cc
        Pixel.cc
        Activity.cc
        ControllerBoard.cc
        CsvParser.cc
        )


set(HEADERS
        Board.h
        Pixel.h
        Activity.h
        ControllerBoard.h
        CsvParser.h
        )

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})