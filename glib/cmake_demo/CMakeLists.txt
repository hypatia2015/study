project (Demo)
#set(CMAKE_BUILD_TYPE Release)


#########################################################################
#set (Tutorial_VERSION_MAJOR 1)
#set (Tutorial_VERSION_MINOR 0)

execute_process(COMMAND	git log -1 --format="%H" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} OUTPUT_VARIABLE GIT_VERSION)
execute_process(COMMAND	git log -1 --format="%ct" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} OUTPUT_VARIABLE GIT_TIME)
string (REGEX REPLACE "[\n\t\r\"]" "" GIT_TIME ${GIT_TIME})
execute_process(COMMAND date -d@${GIT_TIME} +"%Y-%m-%d %H:%M:%S" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} OUTPUT_VARIABLE GIT_DATETIME)
execute_process(COMMAND date +"%Y-%m-%d %H:%M:%S" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} OUTPUT_VARIABLE BUILD_DATETIME)
# 对得到的结果进行处理，尤其注意 \n,\t,\r之类的特殊字符，在cmake时没问题，但是生成的.cmake文件有问题，导致make出错。
string (REGEX REPLACE "[\n\t\r]" "" GIT_VERSION ${GIT_VERSION})
string (REGEX REPLACE "[\n\t\r]" "" GIT_DATETIME ${GIT_DATETIME})
string (REGEX REPLACE "[\n\t\r]" "" BUILD_DATETIME ${BUILD_DATETIME})
message("git版本:" ${GIT_VERSION} ";  git日期:" ${GIT_DATETIME} ";  编译日期:" ${BUILD_DATETIME})
# 增加编译选项，把宏导入源码
add_definitions(-DGIT_VERSION=${GIT_VERSION})
add_definitions(-DGIT_DATETIME=${GIT_DATETIME})
add_definitions(-DBUILD_DATETIME=${BUILD_DATETIME})

########################################################################

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

###########################################################################
set(BIN demo)
add_executable(${BIN} ${SOURCES})
target_link_libraries(${BIN} ${LIBS})
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin/)

#aux_source_directory(. DIR_LIB_SRCS)
#add_library(testStudent SHARED ${SOURCES})
