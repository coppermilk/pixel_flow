set(SOURCES
        Board.cc
        Pixel.cc
        Activity.cc
        ControllerBoard.cc
        GoogleSheetsDataExporter.cc
        GitHubDataExporter.cc
        Data.cc
        )


set(HEADERS
        Board.h
        Pixel.h
        Activity.h
        ControllerBoard.h
        GoogleSheetsDataExporter.h
        GitHubDataExporter.h
        Data.h
        )
#----------------
find_package(Boost COMPONENTS program_options log log_setup REQUIRED)
set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
#-----------------
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})

#////////////#////
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")
#///////////////