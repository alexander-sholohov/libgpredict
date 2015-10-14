cmake_minimum_required(VERSION 2.6)

include(GenerateExportHeader)

if(UNIX)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

  find_package(PHPLibs REQUIRED)
  include_directories(${PHP_INCLUDE_DIRS})
endif()


include( ${CMAKE_SOURCE_DIR}/../common.cmake )

set( SWIG_WRAP_SRC ./out_cpp/satpredict_wrap.cpp )

add_library(satpredict SHARED ${SRC_COMMON} ${SWIG_WRAP_SRC})
target_link_libraries(satpredict gpredict ${EXTRA_LIBS})



if(UNIX)

SET(COPY_TO_PATH satpredict.so)
ADD_CUSTOM_COMMAND(TARGET satpredict POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  libsatpredict.so
  ${COPY_TO_PATH}
  COMMENT "Copying library to '${COPY_TO_PATH}'")

endif()
