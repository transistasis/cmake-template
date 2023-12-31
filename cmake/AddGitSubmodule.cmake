function( add_git_submodule dir )
  find_package( Git REQUIRED )

  if ( NOT EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt )
    execute_process( COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive -- ${dir} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} )
  endif()

  if ( EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt )
    message( "CMakeLists.txt exists at ${CMAKE_SOURCE_DIR}/${dir}" )
    add_subdirectory( ${CMAKE_SOURCE_DIR}/${dir} )
  else()
    message( "CMakeLists.txt does not exist at ${CMAKE_SOURCE_DIR}/${dir}" )
  endif()


endfunction( add_git_submodule )
