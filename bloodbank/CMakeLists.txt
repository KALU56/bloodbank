cmake_minimum_required(VERSION 3.14)

project(BloodBankSystem LANGUAGES CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt automatic features: moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Tell AUTOUIC where to find .ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

# Find Qt6 packages
find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)

# List UI files explicitly (optional, AUTOUIC picks them up automatically if included in sources)
set(UI_FILES
    ui/LoginWindow.ui
    ui/DonorDashboard.ui
    ui/SupervisorDashboard.ui
    ui/RegistrationForm.ui
    ui/AppointmentForm.ui
    ui/HealthHistoryView.ui
    ui/MainWindow.ui
)

# Source files only
set(SOURCES
    main.cpp
    controllers/MainWindow.cpp
    controllers/AuthController.cpp
    controllers/DonorController.cpp
    controllers/DonorDashboard.cpp
    controllers/SupervisorController.cpp
    controllers/SupervisorDashboard.cpp
    models/Appointment.cpp
    models/Donor.cpp
    models/HealthRecord.cpp
    models/Supervisor.cpp
    db/DatabaseManager.cpp
    utils/Helpers.cpp
    utils/Validators.cpp
)

# Header files (optional, for IDEs)
set(HEADERS
    controllers/MainWindow.h
    controllers/AuthController.h
    controllers/DonorController.h
    controllers/DonorDashboard.h
    controllers/SupervisorController.h
    controllers/SupervisorDashboard.h
    models/Appointment.h
    models/Donor.h
    models/HealthRecord.h
    models/Supervisor.h
    db/DatabaseManager.h
    utils/Helpers.h
    utils/Validators.h
)

# Qt resource files (add if you have .qrc)
set(RESOURCES
    # resources/resources.qrc
)

# Create executable, include UI files explicitly (optional)
add_executable(bloodbank
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}    # optional: explicit UI files, usually not required with AUTOUIC
    ${RESOURCES}
)

# Link Qt libraries
target_link_libraries(bloodbank PRIVATE Qt6::Widgets Qt6::Sql)

# Include directories for your source code
target_include_directories(bloodbank PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/models
    ${CMAKE_CURRENT_SOURCE_DIR}/db
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

# Windows GUI executable flag (optional)
set_target_properties(bloodbank PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# Install rules (optional)
install(TARGETS bloodbank
    RUNTIME DESTINATION bin
)
