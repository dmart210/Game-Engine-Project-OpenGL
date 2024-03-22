add_executable(Game Source.cpp)

include_directories("../myEngine/include")

target_link_libraries(Game myEngine)