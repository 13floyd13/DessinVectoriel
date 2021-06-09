cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(skeleton skeleton.cpp view/myApp.cpp view/myDrawingPanel.cpp view/myControlPanel.cpp view/myFrame.cpp modele/cercle.cpp
        modele/forme.cpp modele/rectangle.cpp modele/draw.cpp modele/point.cpp )
target_link_libraries(skeleton ${wxWidgets_LIBRARIES})
