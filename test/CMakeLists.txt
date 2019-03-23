
set(CMAKE_BUILD_TYPE Debug)

# The test files I care only (create a list)
set(testsources
	test_stl_tri.cpp
	test_obj_read_geo.cpp
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
add_test(NAME test_obj_read_geo COMMAND test_obj_read_geo)
