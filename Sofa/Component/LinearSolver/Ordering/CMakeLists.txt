cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.LinearSolver.Ordering LANGUAGES CXX)

set(SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR "src/sofa/component/linearsolver/ordering")

set(HEADER_FILES
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/config.h.in
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/init.h
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/AMDOrderingMethod.h
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/BaseEigenOrderingMethod.h
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/COLAMDOrderingMethod.h
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/NaturalOrderingMethod.h
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/OrderingMethodAccessor.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/init.cpp
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/AMDOrderingMethod.cpp
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/COLAMDOrderingMethod.cpp
    ${SOFACOMPONENTLINEARSOLVERDIRECT_SOURCE_DIR}/NaturalOrderingMethod.cpp
)

sofa_find_package(Sofa.Core REQUIRED)
add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Core)

sofa_create_package_with_targets(
    PACKAGE_NAME ${PROJECT_NAME}
    PACKAGE_VERSION ${Sofa_VERSION}
    TARGETS ${PROJECT_NAME} AUTO_SET_TARGET_PROPERTIES
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR "${PROJECT_NAME}"
)
