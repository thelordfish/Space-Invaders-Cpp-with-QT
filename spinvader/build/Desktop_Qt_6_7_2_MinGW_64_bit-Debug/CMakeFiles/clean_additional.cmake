# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\spinvader_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\spinvader_autogen.dir\\ParseCache.txt"
  "spinvader_autogen"
  )
endif()
