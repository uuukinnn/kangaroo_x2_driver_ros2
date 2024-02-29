cmake_minimum_required(VERSION 3.16)
project(kangaroo_x2_driver LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(-Wall -Wextra)
endif()

# find dependencies
set(THIS_PACKAGE_INCLUDE_DEPENDS
#  pluginlib
  rclcpp
  serial
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()


set(kangaroo_SRCS
    include/Kangaroo/KangarooChannel.cpp
    include/Kangaroo/KangarooCommandWriter.cpp
    include/Kangaroo/KangarooCRC.cpp
    include/Kangaroo/KangarooMonitor.cpp
    include/Kangaroo/KangarooReplyReader.cpp
    include/Kangaroo/KangarooReplyReceiver.cpp
    include/Kangaroo/KangarooSerial.cpp
    include/Kangaroo/KangarooStatus.cpp
    include/Kangaroo/KangarooTimeout.cpp
    include/Arduino/Arduino.cpp
    src/kangaroo_x2_driver/test.cpp
)

set(kangaroo_HEADERS
    #include
    include/Kangaroo/Kangaroo.h
    include/Arduino/Arduino.h
)

## COMPILE
add_library(${PROJECT_NAME}
  SHARED
   ${kangaroo_SRCS}
   ${kangaroo_HEADERS}
  )

add_executable(Test 
${kangaroo_SRCS}
)

target_compile_features(kangaroo_x2_driver PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

target_include_directories(Test PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

ament_target_dependencies(
  kangaroo_x2_driver PUBLIC
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
  #${PROJECT_NAME}
)

ament_target_dependencies(
  Test
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(${PROJECT_NAME} PRIVATE "kangaroo_x2_driver_BUILDING_DLL")

# INSTALL
install(
  DIRECTORY include/
  DESTINATION include
)

install(TARGETS kangaroo_x2_driver
  EXPORT export_kangaroo_x2_driver
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(TARGETS 
  Test
  DESTINATION lib/${PROJECT_NAME}
)

## EXPORTS
ament_export_targets(export_kangaroo_x2_driver HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_export_libraries(${PROJECT_NAME})
#ament_export_include_directories(${PROJECT_NAME})
ament_package()
