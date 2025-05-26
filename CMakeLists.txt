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
set(CMAKE_AUTOUIC ON) # Keep this ON

# --- ADD THIS LINE TO TELL AUTOUIC WHERE TO FIND .ui FILES ---
# This tells AUTOUIC to look in the 'ui' directory for .ui files
# corresponding to includes like "ui_WelcomeWindow.h"
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)


# Include directories
include_directories(headers)

# Collect source files
set(SOURCES
    main.cpp
    sources/DatabaseManager.cpp
    sources/DonorDashboardWindow.cpp
    sources/DonorLoginWindow.cpp
    sources/DonorRegisterWindow.cpp
    sources/SupervisorDashboardWindow.cpp
    sources/SupervisorFormsWindow.cpp
    sources/SupervisorLoginWindow.cpp
    sources/WelcomeWindow.cpp
)

# Collect header files
set(HEADERS
    headers/DatabaseManager.h
    headers/DonorDashboardWindow.h
    headers/DonorLoginWindow.h
    headers/DonorRegisterWindow.h
    headers/SupervisorDashboardWindow.h
    headers/SupervisorFormsWindow.h
    headers/SupervisorLoginWindow.h
    headers/WelcomeWindow.h
)

# Collect UI files (Qt Designer)
# Keep this as it's still good practice to explicitly list them,
# although the CMAKE_AUTOUIC_SEARCH_PATHS might make it redundant for simple cases.
set(UIS
    ui/DonorDashboardWindow.ui
    ui/DonorLoginWindow.ui
    ui/DonorRegisterWindow.ui
    ui/SupervisorDashboardWindow.ui
    ui/SupervisorFormsWindow.ui
    ui/SupervisorLoginWindow.ui
    ui/WelcomeWindow.ui
)

# Database and schema files (optional for packaging, not compilation)
set(DATABASE_FILES
    database/schema_postgres.sql
)

# Add the executable target
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    database/schema_postgres.sql # Ensure .ui files are still part of the target's sources
)

# Link the necessary Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Sql)

# Copy the database folder to the build output directory after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/database
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/database
)

# Install commands (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/database DESTINATION .)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources DESTINATION .)
