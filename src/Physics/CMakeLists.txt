set(CURRENT_CMAKE_LIB gbe_physics)

#SUBDIRECTORY LOADING
add_library(${CURRENT_CMAKE_LIB} STATIC
	"PhysicsPipeline.cpp"
	"PhysicsDatatypes.cpp" 
	"Rigidbody.cpp"
	"ColliderData/SphereColliderData.cpp"
 "ColliderData/ColliderData.cpp" "ColliderData/BoxColliderData.h" "ColliderData/BoxColliderData.cpp" "gbe_physics.h")

find_package(Bullet CONFIG REQUIRED)
target_link_libraries(${CURRENT_CMAKE_LIB} PRIVATE ${BULLET_LIBRARIES})

target_link_libraries(${CURRENT_CMAKE_LIB} PRIVATE gbe_math)

message("[GABENGINE] LOADED: " ${CMAKE_CURRENT_SOURCE_DIR})