set(HEADER_FILES
        include/myEngine.h
        src/EngineApp.h
        src/Utility.h
        src/EngineWindow.h
        src/WindowImpl.h
        src/codeGLFW/WindowGLFW.h
        src/Renderer.h
        src/RendererImplement.h
        src/codeOpenGL/RendererOpenGL.h
        src/Shader.h
        src/ShaderImplement.h
        src/codeOpenGL/ShaderOpenGL.h
        src/Image.h
        src/ImageImplement.h
        src/codeOpenGL/ImageOpenGL.h
        src/HappyEvents.h
        src/HappyKeys.h
        src/Unit.h
)



set(SOURCE_FILES 
        src/EngineApp.cpp
        src/EngineWindow.cpp
        src/codeGLFW/WindowGLFW.cpp
        src/Renderer.cpp
        src/codeOpenGL/RendererOpenGL.cpp
        src/Shader.cpp
        src/codeOpenGL/ShaderOpenGL.cpp
        src/Image.cpp
        src/codeOpenGL/ImageOpenGL.cpp
        src/HappyEvents.cpp
        src/Unit.cpp
    )


add_library(myEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(myEngine 
    PUBLIC
        $<$<CONFIG:Debug>:ENGINE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:ENGINE_DEBUG=1>
    PRIVATE
        ENGINE_LIB
	    ENGINE_GLFW_WINDOW
        ENGINE_OPENGL
)

if(MSVC)
    target_compile_definitions(myEngine PUBLIC ENGINE_MS_COMPILER)
endif()

target_include_directories(myEngine PRIVATE ../glfw/include)
target_include_directories(myEngine PRIVATE ../myEngine/src)
target_include_directories(myEngine PRIVATE ../glad/include)
target_include_directories(myEngine PRIVATE ../stbi)


target_precompile_headers(myEngine PRIVATE src/pch.h)

target_link_libraries(myEngine glfw)
target_link_libraries(myEngine glad)
target_link_libraries(myEngine stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/myEngine)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/myEngine)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/myEngine)

