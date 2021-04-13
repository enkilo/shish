include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Functions.cmake)

if(NOT HAVE_LIBOWFAT)
  file(GLOB LIBOWFAT_HEADERS lib/*.h)

  file(GLOB LIBOWFAT_SOURCES lib/*/*.c)
  set(LIBOWFAT_SOURCES ${LIBOWFAT_HEADERS} ${LIBOWFAT_SOURCES})

  list(APPEND LIBOWFAT_DEBUG_SOURCES ${LIBOWFAT_SOURCES})
  list(FILTER LIBOWFAT_DEBUG_SOURCES INCLUDE REGEX "debug\\.c")
  string(REGEX REPLACE "debug\\.c" ".c" LIBOWFAT_NODEBUG_SOURCES
                       "${LIBOWFAT_DEBUG_SOURCES}")

  # dump(LIBOWFAT_DEBUG_SOURCES LIBOWFAT_NODEBUG_SOURCES)

  if(DEBUG_ALLOC)
    list(REMOVE_ITEM LIBOWFAT_SOURCES ${LIBOWFAT_NODEBUG_SOURCES})
  else(DEBUG_ALLOC)
    list(REMOVE_ITEM LIBOWFAT_SOURCES ${LIBOWFAT_DEBUG_SOURCES})
  endif(DEBUG_ALLOC)

  list(APPEND ALL_SOURCES ${LIBOWFAT_SOURCES})

  add_library(libowfat STATIC ${LIBOWFAT_SOURCES})
  set_target_properties(libowfat PROPERTIES OUTPUT_NAME owfat)

  set(LIBOWFAT_LIBRARY
      libowfat
      CACHE STRING "-lowfat library name" FORCE)
  set(LIBOWFAT_LIBDIR "${CMAKE_CURRENT_BINARY_DIR}"CACHE STRING
                      "-lowfat library directory" FORCE)

endif(NOT HAVE_LIBOWFAT)
