add_executable (t_char "main.cpp" "main.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET t_char PROPERTY CXX_STANDARD 20)
endif()