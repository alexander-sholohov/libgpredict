cmake_minimum_required(VERSION 2.6)

include(GenerateExportHeader)


include( ${CMAKE_SOURCE_DIR}/../common.cmake )

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})



set( SWIG_WRAP_SRC ./out_cpp/satpredict_wrap.cxx )

add_library(satpredict SHARED ${SRC_COMMON} ${SWIG_WRAP_SRC})
target_link_libraries(satpredict gpredict ${EXTRA_LIBS} ${PYTHON_LIBRARIES})



if(UNIX)

SET(COPY_TO_PATH _satpredict.so)
ADD_CUSTOM_COMMAND(TARGET satpredict POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  libsatpredict.so
  ${COPY_TO_PATH}
  COMMENT "Copying library to '${COPY_TO_PATH}'")

endif()
