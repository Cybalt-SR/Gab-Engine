set(CURRENT_CMAKE_LIB gbe_gui)

#SUBDIRECTORY LOADING
add_library(${CURRENT_CMAKE_LIB} STATIC
	"gb_canvas.cpp"
 "gb_rect.cpp" 
 "gbuiPipeline.cpp"
 
 "rect_types/gb_root.cpp"
 "rect_types/gb_button.cpp"
 "rect_types/gb_image.cpp"

 "interfaces/gb_onClick.h"
 "interfaces/gb_onExit.h"
)

target_link_libraries(${CURRENT_CMAKE_LIB} PUBLIC gbe_math)
target_link_libraries(${CURRENT_CMAKE_LIB} PUBLIC gbe_asset)

find_package(glad CONFIG REQUIRED)
target_link_libraries(${CURRENT_CMAKE_LIB} PRIVATE glad::glad)

message("[GABENGINE] LOADED: " ${CMAKE_CURRENT_SOURCE_DIR})