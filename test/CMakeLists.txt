
set(CMAKE_BUILD_TYPE Debug)

# The test files I care only (create a list)
set(testsources
	test_stl_tri.cpp
	test_obj_read_geo.cpp
	test_conversor_1.cpp
	test_calc_centroid.cpp
	test_translate.cpp
	test_rotate.cpp
	)

# Iterate over the list above
foreach (testfile ${testsources})
	# Delete File extensions (test_i.cpp -> test_i)
	get_filename_component(testname ${testfile} NAME_WE)

	# Create the executable test_i and link.
	add_executable(${testname} ${testfile})
	target_link_libraries(${testname} obj2stl)
endforeach ()

# As some tests will require commands and could be executed in loops we add the
# tests individually here.

add_test(NAME test_stl_tri COMMAND test_stl_tri)
add_test(NAME test_obj_read_geo COMMAND test_obj_read_geo ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_conversor_1 COMMAND test_conversor_1 ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_calc_centroid COMMAND test_calc_centroid ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_translate COMMAND test_translate ${PROJECT_SOURCE_DIR}/geometries/box.obj)
add_test(NAME test_rotate COMMAND test_rotate ${PROJECT_SOURCE_DIR}/geometries/box.obj)

