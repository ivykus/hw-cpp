cmake_minimum_required(VERSION 3.28)

set(ProjName TODO)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")


# Use git version detect to obtain a project version based on tags
include(GitVersionDetect)
set(PROJECT_VERSION_MAJOR ${GITVERSIONDETECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${GITVERSIONDETECT_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${GITVERSIONDETECT_VERSION_PATCH})
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

project(${ProjName} VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

include_directories(src)

set(TargetName TODOapp) #TODO set app name

add_executable(${TargetName} 
    src/main.cpp
    # TODO add src/.cpp files
)

set(LibName ) # TODO: setLibname


set_target_properties(${TargetName} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${TargetName}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if(DEFINED LibName)
    add_library(${LibName} STATIC
        # TODO add src/.pp files
    )
    target_link_libraries(${TargetName} PRIVATE
        ${LibName} 
    )
endif()


add_subdirectory(tests)

include(CTest)

install(TARGETS ${TargetName} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
