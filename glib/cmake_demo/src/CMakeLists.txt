set(SUPER_INCLUDE_DIR ${INCLUDE_DIR})
set(SUPER_LIBS ${LIBS})

include_directories(${SUPER_INCLUDE_DIR})
link_libraries(${SUPER_LIBS})

MESSAGE(STATUS "INCLUDE_DIR :${INCLUDE_DIR} SUPER_INCLUDE_DIR:${SUPER_INCLUDE_DIR}")
MESSAGE(STATUS "LIBS :${LIBS} SUPER_LIBS:${SUPER_LIBS}")

aux_source_directory(. DIR_LIB_SRCS)

add_library (LIBSRC ${DIR_LIB_SRCS})
