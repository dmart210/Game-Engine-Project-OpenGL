set(HEADER_FILES
        src/EngineApp.h
        include/myEngine.h
        src/Utility.h
        src/EngineWindow.h
        src/WindowImpl.h
        src/codeGLFW/WindowGLFW.h
)



set(SOURCE_FILES 
        src/EngineApp.cpp
        src/EngineWindow.cpp
        src/codeGLFW/WindowGLFW.cpp
    )


add_library(myEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(myEngine 
    PUBLIC
        $<$<CONFIG:Debug>:ENGINE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:ENGINE_DEBUG=1>
    PRIVATE
        ENGINE_LIB
	SUN_GLFW_WINDOW
)

if(WIN32)
    target_compile_definitions(myEngine PUBLIC ENGINE_MS_COMPILER)
endif()

target_include_directories(myEngine PRIVATE ../glfw/include)
target_include_directories(myEngine PRIVATE ../myEngine)

target_precompile_headers(myEngine PRIVATE src/pch.h)
target_link_libraries(myEngine glfw)
