file(GLOB MY_FONTS "${CMAKE_SOURCE_DIR}/Fonts/*.ttf")
file(COPY ${MY_FONTS} DESTINATION "${CMAKE_BINARY_DIR}")
message("copying ${MY_FONTS} \n    from ${CMAKE_SOURCE_DIR}/Fonts/*.ttf\n    to ${CMAKE_BINARY_DIR} ...")