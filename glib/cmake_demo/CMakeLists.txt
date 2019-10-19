project (Demo)
#set(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

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
add_definitions( -DGIT_VERSION=${GIT_VERSION})
add_definitions( -DGIT_DATETIME=${GIT_DATETIME})
add_definitions( -DBUILD_DATETIME=${BUILD_DATETIME})

########################################################################
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(SOURCES demo_main.c)

file(GLOB SOURCES "*.c")

set (INCLUDE_DIR /usr/include/glib-2.0
        /usr/lib64/glib-2.0/include
        /usr/include/gio-unix-2.0/
	/home/code/debug/study/glib/cmake_demo/include)

set (LIBS gio-2.0 gobject-2.0 glib-2.0)

#link_directories(src)
#link_libraries(LIBSRC)
#aux_source_directory(. SRC)

#ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
add_subdirectory(src)
include_directories(${INCLUDE_DIR} include src)
###########################################################################
set(BIN demo)

add_executable(${BIN} ${SOURCES})
target_link_libraries(${BIN} ${LIBS} LIBSRC)
