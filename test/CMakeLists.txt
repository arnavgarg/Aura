project(Aura)

set(gtestdir ${CMAKE_SOURCE_DIR}/3rdparty/gtest)
include_directories(${gtestdir}/include)
link_directories(${gtestdir}/lib)

set(lexertest lexer/lexer-test.cpp)

add_executable(tests test.cpp ${lexertest})
add_test(all tests)
target_link_libraries(tests util gtest)
