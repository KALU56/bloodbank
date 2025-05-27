cmake_minimum_required(VERSION 3.16)

project(BloodBankApp VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# Enable Qt automatic processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Specify where to find .ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# Include directories
include_directories(headers)

# Source files
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

# Header files
set(HEADERS
    headers/Donor.h
    headers/MedicalHistory.h
    headers/HealthHistory.h
    headers/DatabaseManager.h
    headers/DonorDashboardWindow.h
    headers/DonorLoginWindow.h
    headers/DonorRegisterWindow.h
    headers/SupervisorDashboardWindow.h
    headers/SupervisorFormsWindow.h
    headers/SupervisorLoginWindow.h
    headers/WelcomeWindow.h
)

# UI files
set(UIS
    ui/DonorDashboardWindow.ui
    ui/DonorLoginWindow.ui
    ui/DonorRegisterWindow.ui
    ui/SupervisorDashboardWindow.ui
    ui/SupervisorFormsWindow.ui
    ui/SupervisorLoginWindow.ui
    ui/WelcomeWindow.ui
)

# Database schema file
set(DATABASE_FILES
    database/schema_postgres.sql
)

# Create executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}

)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Sql)

# Copy database folder to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/database
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/database
)

# Install commands
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/database DESTINATION .)
