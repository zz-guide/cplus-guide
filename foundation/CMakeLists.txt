# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("foundation")

# 包含子项目。
add_subdirectory ("t_data_type/t_int")
add_subdirectory ("t_data_type/t_char")
add_subdirectory ("t_data_type/t_short")
add_subdirectory ("t_data_type/t_long")
add_subdirectory ("t_class/introduce")
add_subdirectory ("t_class/constructor")
add_subdirectory ("t_class/copy_constructor")
add_subdirectory ("t_class/const_function")
add_subdirectory ("t_class/const_object")
add_subdirectory ("t_class/friend_function")
add_subdirectory ("t_class/friend_global_function")
add_subdirectory ("t_class/friend_class")
add_subdirectory ("t_class/virtual_function")
add_subdirectory ("t_class/function_template")