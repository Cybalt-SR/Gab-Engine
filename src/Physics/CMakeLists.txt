set(CURRENT_CMAKE_LIB gbe_physics)

#SUBDIRECTORY LOADING
add_library(${CURRENT_CMAKE_LIB} STATIC
	"PhysicsPipeline.cpp"
	"PhysicsDatatypes.cpp" 
	"PhysicsBody.cpp"
	"Rigidbody.cpp"
	"TriggerRigidBody.cpp"
	"ColliderData/SphereColliderData.cpp"
	"ColliderData/ColliderData.cpp" 
	"ColliderData/BoxColliderData.cpp"
 "Raycast.cpp" "ColliderData/MeshColliderData.cpp")

find_package(Bullet CONFIG REQUIRED)
target_link_libraries(${CURRENT_CMAKE_LIB} PUBLIC ${BULLET_LIBRARIES})

target_link_libraries(${CURRENT_CMAKE_LIB} PUBLIC gbe_math)

message("[GABENGINE] LOADED: " ${CMAKE_CURRENT_SOURCE_DIR})