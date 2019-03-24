
set(CMAKE_BUILD_TYPE Debug)

# The test files I care only (create a list)
set(testsources
	test_conversor.cpp
	test_obj_read_geo.cpp
	test_obj_calc_centroid.cpp
	test_obj_translate.cpp
	test_obj_rotate.cpp
	test_obj_scale.cpp
	test_stl_triangle_ascii.cpp
	test_stl_triangle_binary.cpp
	test_stl_calc_surface.cpp
	test_stl_calc_volume.cpp
	test_stl_is_point_inside.cpp
	test_stl_calc_centroid.cpp
	)

# Iterate over the list above
foreach (testfile ${testsources})
	# Delete File extensions (test_i.cpp -> test_i)
	get_filename_component(testname ${testfile} NAME_WE)

	# Create the executable test_i and link.
	add_executable(${testname} ${testfile})
	target_link_libraries(${testname} gconversor)
endforeach ()

# As some tests will require commands and could be executed in loops we add the
# tests individually here.

add_test(NAME test_conversor COMMAND test_conversor ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_obj_read_geo COMMAND test_obj_read_geo ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_obj_calc_centroid COMMAND test_obj_calc_centroid ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_obj_translate COMMAND test_obj_translate ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_obj_rotate COMMAND test_obj_rotate ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_obj_scale COMMAND test_obj_scale ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_stl_triangle_ascii COMMAND test_stl_triangle_ascii)
add_test(NAME test_stl_triangle_binary COMMAND test_stl_triangle_binary)
add_test(NAME test_stl_calc_surface COMMAND test_stl_calc_surface ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_stl_calc_volume COMMAND test_stl_calc_volume ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_stl_is_point_inside COMMAND test_stl_is_point_inside ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_stl_calc_centroid COMMAND test_stl_calc_centroid ${PROJECT_SOURCE_DIR}/geometries/box.obj)

