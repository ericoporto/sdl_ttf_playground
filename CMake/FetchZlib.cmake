FetchContent_Declare(
        zlib_content
        URL https://github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz
        URL_HASH MD5=4df8ccfbd8f637d556f56da8ad348c19
)

FetchContent_GetProperties(zlib_content)
if(NOT zlib_content)
    FetchContent_Populate(zlib_content)

    message("Including zlib ...")
    message("zlib_content_SOURCE_DIR: ${zlib_content_SOURCE_DIR}")
    add_subdirectory("${zlib_content_SOURCE_DIR}" "${zlib_content_BINARY_DIR}" EXCLUDE_FROM_ALL)
    include_directories("${zlib_content_SOURCE_DIR}/src/")

   # set(ZLIB_LIBRARY zlibstatic)
    set(ZLIB_INCLUDE_DIR "${zlib_content_SOURCE_DIR}")
endif()