cmake_minimum_required(VERSION 3.16)

# ---- Project ----
project(megamimes VERSION 2.0.0 LANGUAGES C)

include(GNUInstallDirs)  # provides CMAKE_INSTALL_INCLUDEDIR / LIBDIR / BINDIR, etc.

# ---- Options ----
option(MEGA_BUILD_SHARED     "Build shared library"           ON)
option(MEGA_BUILD_STATIC     "Also build static library"      OFF)
option(MEGA_BUILD_CLI        "Build mmime CLI tool"           ON)
option(MEGA_ENABLE_SIMD      "Enable SIMD fast-paths"         OFF)
option(MEGA_ENABLE_TESTS     "Enable tests"                   ON)

# ---- Sources / headers ----
set(MEGAMIMES_PUBLIC_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/megamimes.h
)

set(MEGAMIMES_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/MegaMimes.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/megamagic.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/megaext.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/megautf8.c
)

# ---- Shared library (default) ----
if(MEGA_BUILD_SHARED)
  add_library(megamimes SHARED ${MEGAMIMES_SOURCES} ${MEGAMIMES_PUBLIC_HEADERS})
  target_compile_features(megamimes PRIVATE c_std_99)

  # Public includes: build vs install
  target_include_directories(megamimes
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  # Visibility + versioning
  set_target_properties(megamimes PROPERTIES
    OUTPUT_NAME "megamimes"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    C_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
  )

  # Windows export macro
  target_compile_definitions(megamimes PRIVATE MEGA_BUILD_DLL)

  # Optional SIMD toggles (safe no-ops if arch doesn't match)
  if(MEGA_ENABLE_SIMD)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|i.86)$")
      target_compile_options(megamimes PRIVATE -msse2)
      target_compile_definitions(megamimes PRIVATE MEGA_SIMD_SSE2)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64)$")
      # NEON is baseline on arm64; no special flags needed for clang/gcc
      target_compile_definitions(megamimes PRIVATE MEGA_SIMD_NEON)
    endif()
  endif()

  # Install the shared lib
  install(TARGETS megamimes
    EXPORT megamimesTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

# ---- Static library (optional) ----
if(MEGA_BUILD_STATIC)
  add_library(megamimes_static STATIC ${MEGAMIMES_SOURCES} ${MEGAMIMES_PUBLIC_HEADERS})
  target_compile_features(megamimes_static PRIVATE c_std_99)
  target_include_directories(megamimes_static
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )
  set_target_properties(megamimes_static PROPERTIES OUTPUT_NAME "megamimes")
  install(TARGETS megamimes_static
    EXPORT megamimesTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

# ---- CLI tool (links to shared if available, else static) ----
if(MEGA_BUILD_CLI)
  add_executable(mmime ${CMAKE_CURRENT_SOURCE_DIR}/tools/mmime.c)
  if(TARGET megamimes)
    target_link_libraries(mmime PRIVATE megamimes)
  else()
    target_link_libraries(mmime PRIVATE megamimes_static)
  endif()
  target_compile_features(mmime PRIVATE c_std_99)
  install(TARGETS mmime RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

# ---- Install public headers ----
install(FILES ${MEGAMIMES_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# ---- CMake package export ----
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/megamimesConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(EXPORT megamimesTargets
  FILE megamimesTargets.cmake
  NAMESPACE megamimes::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/megamimes
)

# ---- pkg-config file ----
# Put this template at project root as CMakePkg.pc.in:
#   prefix=@CMAKE_INSTALL_PREFIX@
#   exec_prefix=${prefix}
#   libdir=${exec_prefix}/@CMAKE_INSTALL_LIBDIR@
#   includedir=${prefix}/@CMAKE_INSTALL_INCLUDEDIR@
#
#   Name: megamimes
#   Description: Tiny MIME, text/binary and encoding detector
#   Version: @PROJECT_VERSION@
#   Libs: -L${libdir} -lmegamimes
#   Cflags: -I${includedir}
#
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMakePkg.pc.in
               ${CMAKE_CURRENT_BINARY_DIR}/megamimes.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/megamimes.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

# ---- Tests ----
if(MEGA_ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
