

project ( mongoose )
cmake_minimum_required ( VERSION 2.8 )

set (mongoose_version $ENV{MONGOOSE_VERSION})

if ("${mongoose_version}" STREQUAL "")
  set(mongoose_version 4.1)
endif()

include(ExternalProject)
ExternalProject_Add(
    Mongoose
    URL https://github.com/besport/mongoose/archive/${mongoose_version}.tar.gz
    PREFIX "3rd"
    UPDATE_COMMAND ""
    PATCH_COMMAND
      ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/mongoose.cmake" <SOURCE_DIR>/CMakeLists.txt &&
      ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/test.c" <SOURCE_DIR>/test.c
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/mongoose-${mongoose_version}
)

ExternalProject_Get_Property(Mongoose install_dir)

install(DIRECTORY ${install_dir}/lib/ DESTINATION lib)
install(DIRECTORY ${install_dir}/include/ DESTINATION include)