cmake_minimum_required(VERSION 3.20)

project(vix-ai-distributed
  VERSION 0.1.0
  DESCRIPTION "Vix.AI Distributed: P2P, secure channels, federated learning (header-only v0)"
  LANGUAGES CXX)

option(VIX_AI_DISTRIB_BUILD_TESTS "Build vix-ai-distributed tests" ON)
option(VIX_AI_DISTRIB_INSTALL     "Install vix-ai-distributed targets" ON)
option(VIX_AI_DISTRIB_WARNINGS    "Enable extra warnings" ON)

add_library(vix_ai_distributed INTERFACE)
add_library(Vix::AI::distributed ALIAS vix_ai_distributed)

target_include_directories(vix_ai_distributed INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_distributed INTERFACE cxx_std_20)

if (DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()
target_compile_definitions(vix_ai_distributed INTERFACE VIX_AI_DISTRIB_VERSION="${PROJECT_VERSION}")

if (VIX_AI_DISTRIB_WARNINGS)
  if (MSVC)
    target_compile_options(vix_ai_distributed INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_distributed INTERFACE -Wall -Wextra -Wpedantic)
  endif()
endif()

# Tests
if (VIX_AI_DISTRIB_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Install / package
if (VIX_AI_DISTRIB_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  install(TARGETS vix_ai_distributed
          EXPORT vix_ai_distributedTargets)

  install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

  install(EXPORT vix_ai_distributedTargets
          FILE vix_ai_distributedTargets.cmake
          NAMESPACE Vix::AI::
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed)

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfig.cmake
"include(\"\${CMAKE_CURRENT_LIST_DIR}/vix_ai_distributedTargets.cmake\")\n")

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed
  )
endif()
