file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(sample_stack ${srcs} ${hdrs})
