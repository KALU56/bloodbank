cmake_minimum_required(VERSION 3.16)

project(BloodBankApp VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# Enable Qt automatic processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# --- Critical Fixes ---
# 1. Set explicit paths for UIC processing
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

# 2. Use GLOB to automatically find all UI files
file(GLOB UI_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui"
)

# 3. Use GLOB for source files
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp"
)

# 4. Include directories with full path
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

# Add the executable target
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${UI_FILES}
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Sql
)

# --- Optional But Recommended ---
# 1. Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 2. Database handling
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/database
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/database
)

# 3. Installation (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/database DESTINATION .)
