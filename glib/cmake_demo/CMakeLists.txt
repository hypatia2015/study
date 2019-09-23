project (Demo)
#set(CMAKE_BUILD_TYPE Release)

#set (Tutorial_VERSION_MAJOR 1)
#set (Tutorial_VERSION_MINOR 0)

#ADD_SUBDIRECTORY(src temp)
#ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(SOURCES gbus_demo.c)
file(GLOB SOURCES "*.c")

set (INCLUDE_DIR /usr/include/glib-2.0
        /usr/lib64/glib-2.0/include
        /usr/include/gio-unix-2.0/)
include_directories(${INCLUDE_DIR})

set (LIBS gio-2.0 gobject-2.0 glib-2.0)
#link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )
#set ( PROJECT_LINK_LIBS libtestStudent.a )
#link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )

include_directories( ${INCLUDE_DIR})

#aux_source_directory(. SRC)
#add_subdirectory(Child)

set(BIN demo)
add_executable(${BIN} ${SOURCES})
target_link_libraries(${BIN} ${LIBS})
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin/)

#aux_source_directory(. DIR_LIB_SRCS)
#add_library(testStudent SHARED ${SOURCES})
