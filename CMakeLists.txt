cmake_minimum_required (VERSION 2.6) 
project (glamour_math) 

include_directories (include)

aux_source_directory(src SRC)
add_library (gla_math ${SRC})
