# Add source to this project's executable.
add_executable(
    Engine 
    
    "Main.cpp"

    "System/Window.cpp"
    
    "System/Types.hpp"
    "System/Assert.hpp"
    "System/Event.cpp"

    "Math/Vector2.hpp"
 "Graphics/Renderer/Renderer.cpp" )

target_link_libraries(Engine 
        ${EXTERNAL_LIBRARIES}
)

# Copy DLLS
foreach(DLL ${EXTERNAL_DLLS})
    add_custom_command(
        TARGET Engine POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DLL}              
        $<TARGET_FILE_DIR:Engine>
    )
endforeach()