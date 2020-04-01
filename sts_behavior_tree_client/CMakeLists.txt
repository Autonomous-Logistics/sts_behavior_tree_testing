cmake_minimum_required(VERSION 2.8.3)
project(sts_behavior_tree_client)

## Use C++11
add_definitions(-std=c++11)

# openMP
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# Set to Release in order to speed up the program significantly
#set(CMAKE_BUILD_TYPE Release) #None, Debug, Release, RelWithDebInfo, MinSizeRel
set(CMAKE_BUILD_TYPE Debug)

# Make sure symbols are there, and not fail at runtime
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")


## Find catkin macros and libraries
find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    std_msgs

    #sts libs if needed
    sts_behavior_tree_interface
    sts_virtual_interface_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS
    include ${EXTERNAL_INCLUDE_DIRS}

  LIBRARIES
    #${EXTERNAL_LIBS}
    sts_behavior_tree_interface
    sts_virtual_interface_msgs

  CATKIN_DEPENDS

#  DEPENDS
)

###########
## Build ##
###########

#cascade files recusively - could be usefull if multiple files exist
FILE(GLOB_RECURSE HeaderFiles "include/*.h")
FILE(GLOB_RECURSE SourceFiles "src/*.cpp")

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(${PROJECT_NAME}_core
    ${SourceFiles}
    ${HeaderFiles}
)

## Declare cpp executables
add_executable(${PROJECT_NAME}
  src/${PROJECT_NAME}_node.cpp
  ${SourceFiles}
  ${HeaderFiles}
)

## Specify libraries to link executable targets against
target_link_libraries(${PROJECT_NAME}_core
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}
  ${PROJECT_NAME}_core
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# Mark executables and/or libraries for installation
#install(
#  TARGETS ${PROJECT_NAME}
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

# Mark cpp header files for installation
#install(
#  DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  FILES_MATCHING PATTERN "*.h"
#)

# Mark other files for installation
#install(
#  DIRECTORY doc
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)

#############
## Testing ##
#############

#if(CATKIN_ENABLE_TESTING)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
### Add gtest based cpp test target and link libraries
#catkin_add_gtest(${PROJECT_NAME}-test
#  test/test_sts_behavior_tree_testing.cpp
#  test/BehaviorTreeTest.cpp)
#endif()

#if(TARGET ${PROJECT_NAME}-test)
#  target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}_core)
#endif()
