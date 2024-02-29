#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "kangaroo_x2_driver::kangaroo_x2_driver" for configuration ""
set_property(TARGET kangaroo_x2_driver::kangaroo_x2_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(kangaroo_x2_driver::kangaroo_x2_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkangaroo_x2_driver.so"
  IMPORTED_SONAME_NOCONFIG "libkangaroo_x2_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS kangaroo_x2_driver::kangaroo_x2_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_kangaroo_x2_driver::kangaroo_x2_driver "${_IMPORT_PREFIX}/lib/libkangaroo_x2_driver.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
