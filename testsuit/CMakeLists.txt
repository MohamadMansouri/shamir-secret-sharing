add_executable(test_fields test_fields.cpp)
add_executable(test_shamirss test_shamirss.cpp ../src/shamirss/shamirss.cpp)

target_link_libraries(test_fields fields)
target_link_libraries(test_shamirss fields)


add_test(NAME Fields COMMAND test_fields)
add_test(NAME ShamirSS COMMAND test_shamirss)