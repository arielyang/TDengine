CMAKE_MINIMUM_REQUIRED(VERSION 2.8...3.20)
PROJECT(TDengine)

FIND_PATH(HEADER_GTEST_INCLUDE_DIR gtest.h /usr/include/gtest /usr/local/include/gtest)
FIND_LIBRARY(LIB_GTEST_STATIC_DIR libgtest.a /usr/lib/ /usr/local/lib /usr/lib64)
FIND_LIBRARY(LIB_GTEST_SHARED_DIR libgtest.so /usr/lib/ /usr/local/lib /usr/lib64)

IF (HEADER_GTEST_INCLUDE_DIR AND (LIB_GTEST_STATIC_DIR OR LIB_GTEST_SHARED_DIR))
    MESSAGE(STATUS "gTest library found, build unit test")

    INCLUDE_DIRECTORIES(${HEADER_GTEST_INCLUDE_DIR})
    AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_LIST)

    LIST(REMOVE_ITEM SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/trefTest.c)
    ADD_EXECUTABLE(utilTest ${SOURCE_LIST})
    TARGET_LINK_LIBRARIES(utilTest util common os gtest pthread)

    LIST(REMOVE_ITEM SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/cacheTest.cpp)
    LIST(APPEND SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/hashTest.cpp)
    ADD_EXECUTABLE(hashTest ${SOURCE_LIST})
    TARGET_LINK_LIBRARIES(hashTest util common os gtest pthread)
    
    LIST(APPEND BIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/trefTest.c)
    ADD_EXECUTABLE(trefTest ${BIN_SRC})
    TARGET_LINK_LIBRARIES(trefTest common util)

ENDIF()

#IF (TD_LINUX)
#    ADD_EXECUTABLE(trefTest ./trefTest.c)
#    TARGET_LINK_LIBRARIES(trefTest util common)
#ENDIF ()

INCLUDE_DIRECTORIES(${TD_SOURCE_DIR}/src/util/inc)

# # freelistTest
# add_executable(freelistTest "")
# target_sources(freelistTest
#     PRIVATE
#     "freelistTest.cpp"
# )
# target_link_libraries(freelistTest os util gtest gtest_main)

# # encodeTest
# add_executable(encodeTest "encodeTest.cpp")
# target_link_libraries(encodeTest os util gtest gtest_main)

# queueTest
# add_executable(procTest "procTest.cpp")
# target_link_libraries(procTest os util transport sut gtest_main)   
# add_test(
#     NAME procTest
#     COMMAND procTest
# )

# cfgTest
add_executable(cfgTest "cfgTest.cpp")
target_link_libraries(cfgTest os util gtest_main)   
add_test(
    NAME cfgTest
    COMMAND cfgTest
)

# bloomFilterTest
add_executable(bloomFilterTest "bloomFilterTest.cpp")
target_link_libraries(bloomFilterTest os util gtest_main)   
add_test(
    NAME bloomFilterTest
    COMMAND bloomFilterTest
)

# taosbsearchTest
add_executable(taosbsearchTest "taosbsearchTest.cpp")
target_link_libraries(taosbsearchTest os util gtest_main)   
add_test(
    NAME taosbsearchTest
    COMMAND taosbsearchTest
)

# trbtreeTest
add_executable(rbtreeTest "trbtreeTest.cpp")
target_link_libraries(rbtreeTest os util gtest_main)   
add_test(
    NAME rbtreeTest
    COMMAND rbtreeTest
)