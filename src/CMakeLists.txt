
# Generic main to use as a sandbox 
add_executable(BiblePlanMaker main.cpp)
target_link_libraries(BiblePlanMaker PRIVATE fmt::fmt projectWarnings)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/BibleStats.csv
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/BookStats.csv
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)