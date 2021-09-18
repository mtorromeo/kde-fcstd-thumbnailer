cmake_minimum_required(VERSION 3.10)

project(FcstdThumbnailer
  DESCRIPTION "FreeCAD thumbnail generator for KDE")

set(QT_MIN_VERSION "5.3.0")
set(KF5_MIN_VERSION "5.2.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)
include(WriteBasicConfigVersionFile)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Gui)
find_package(KF5 REQUIRED COMPONENTS KIO Archive)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(FcstdThumbnailer_SRCS src/fcstdcreator.cpp)

add_library(fcstdthumbnailer MODULE ${FcstdThumbnailer_SRCS})

target_link_libraries(fcstdthumbnailer Qt5::Gui KF5::KIOWidgets KF5::Archive)

install(TARGETS fcstdthumbnailer DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES   src/fcstdthumbnailer.desktop DESTINATION ${SERVICES_INSTALL_DIR})
