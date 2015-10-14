
project(satpredict)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake")

if(UNIX)
  find_package(Glib REQUIRED)
  include_directories(${GLIB_INCLUDE_DIR})
  include_directories(${GLIBCONFIG_INCLUDE_DIR})
endif()

set(EXTRA_LIBS "")

if(WIN32)
  include_directories( $ENV{CUSTOM_GLIB_INCLUDE_DIR} )
  find_library(MY_LIB_GLIB glib-1.1 HINTS $ENV{CUSTOM_GLIB_LIB_DIR} )
  list(APPEND EXTRA_LIBS ${MY_LIB_GLIB})
endif()


#-- include gpredict cmake generated variables 
include( ${CMAKE_SOURCE_DIR}/../gpredict-exports.cmake  )


include_directories("../.." "../../sgpsdp")


set( SRC_COMMON ../src/PassItem.cpp ../src/SatCalc.cpp ../src/SatPosition.cpp ../src/TQth.cpp ../src/TSat.cpp ../src/TTime.cpp )


if(WIN32)
  add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

