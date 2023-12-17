add_library(jeans STATIC Jeans.cpp)


target_include_directories(jeans PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
                                      
                            )                       
