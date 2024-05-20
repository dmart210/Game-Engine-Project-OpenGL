add_executable(Game Source.cpp BasicGame.h BasicGame.cpp)

include_directories("../myEngine/include")

target_link_libraries(Game myEngine)