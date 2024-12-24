file(GLOB_RECURSE TEST_FILES ./*.cpp)

set(TestsName "TESTS")

add_executable(${TestsName} ${TEST_FILES})

target_link_libraries(${TestsName} PRIVATE ${ProjectName} gtest)

enable_testing()
add_test(NAME ${TestsName} COMMAND ${TestsName})