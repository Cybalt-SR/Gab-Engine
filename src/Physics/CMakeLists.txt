set(CURRENT_CMAKE_LIB gbe_physics)

#SUBDIRECTORY LOADING
add_library(${CURRENT_CMAKE_LIB} STATIC
	"PhysicsPipeline.cpp"
 "Collider.h" "Rigidbody.cpp" "PhysicsVector.cpp")

find_package(Bullet CONFIG REQUIRED)
target_link_libraries(${CURRENT_CMAKE_LIB} PRIVATE ${BULLET_LIBRARIES})

target_link_libraries(${CURRENT_CMAKE_LIB} PRIVATE gbe_datatypes)

message("[GABENGINE] LOADED: " ${CMAKE_CURRENT_SOURCE_DIR})