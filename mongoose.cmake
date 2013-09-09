
cmake_minimum_required(VERSION 2.8)
project(mongoose)

add_library(mongoose mongoose.c)

find_package (Threads)
target_link_libraries (mongoose ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})

# add_executable(mongoose_test test.c)
# target_link_libraries(mongoose_test mongoose)

install(TARGETS mongoose DESTINATION lib)
install(FILES mongoose.h DESTINATION include)