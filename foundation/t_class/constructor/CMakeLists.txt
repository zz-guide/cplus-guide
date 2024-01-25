add_executable (constructor "main.cpp" "main.h"  "people.cpp" "people.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET t_long PROPERTY CXX_STANDARD 20)
endif()