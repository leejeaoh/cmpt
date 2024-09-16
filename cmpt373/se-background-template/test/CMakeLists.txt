
add_library(doctest-main OBJECT
  doctest.cpp
)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldWhite   "${Esc}[1;37m")
endif()

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


function(can_compile_unit unit_path)
  try_compile(
    CAN_COMPILE
    ${CMAKE_CURRENT_BINARY_DIR}/trials
    ${unit_path}
    CMAKE_FLAGS
      "-DINCLUDE_DIRECTORIES=${CMAKE_CURRENT_SOURCE_DIR}"
  ) 
  set(CAN_COMPILE ${CAN_COMPILE} PARENT_SCOPE)
endfunction(can_compile_unit)


function(compile_unit_test unit_name unit_path)
  add_executable(${unit_name})
  target_sources(${unit_name}
    PRIVATE
      ${unit_path}
  )
  target_link_libraries(${unit_name}
    doctest-main
    solutions
    support
  )
  target_compile_features(${unit_name}
    PUBLIC
      cxx_std_23
  )
  
  add_test(NAME ${unit_name}
    COMMAND ${unit_name}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  )
endfunction(compile_unit_test)

compile_unit_test(unit01 unit01.cpp)
compile_unit_test(unit02 unit02.cpp)
compile_unit_test(unit03 unit03.cpp)
compile_unit_test(unit04 unit04.cpp)
compile_unit_test(unit05 unit05.cpp)
compile_unit_test(unit06 unit06.cpp)
compile_unit_test(unit07 unit07.cpp)
compile_unit_test(unit08 unit08.cpp)


