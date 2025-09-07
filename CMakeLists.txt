cmake_minimum_required(VERSION 3.10)
project(RestaurantBillingSystem)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add executable with multiple source files
add_executable(billing_system 
    main.cpp
    src/MenuItem.cpp
    src/OrderItem.cpp
    src/RestaurantBillingSystem.cpp
)

# Compiler options
if(MSVC)
    target_compile_options(billing_system PRIVATE /W4)
else()
    target_compile_options(billing_system PRIVATE -Wall -Wextra -O2)
endif()