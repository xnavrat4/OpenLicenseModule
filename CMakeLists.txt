cmake_minimum_required(VERSION 3.14)

project(OpenLicenseModule LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

if(MSVC)
    include_directories(OpenLicenseCommunication/win64/includes)
    link_directories(OpenLicenseCommunication/win64)
endif()


add_subdirectory(OpenLicenseCommunication/)

add_library(OpenLicenseModule STATIC
  openlicensemodule.cpp
  openlicensemodule.h
)



if(MSVC)
    target_link_libraries(OpenLicenseModule PRIVATE
        Qt6::Core
        OpenLicenseCommunication
        botan
    )
else()
    target_link_libraries(OpenLicenseModule PRIVATE
        Qt6::Core
        OpenLicenseCommunication
    )
endif()
