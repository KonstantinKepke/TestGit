cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(helloworld)


option(USE_STATIC "Use static library" ON)
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Complete with static library? ${USE_STATIC}")


add_executable(hello2 hello.cpp)

add_library(message-objs
 OBJECT
 	lib/hello.h
	hello.cpp
)
target_compile_options(message-objs
	PRIVATE
		-Wall -fPIC
)

if(USE_STATIC)
	add_library(message-a
	STATIC
		$<TARGET_OBJECTS:message-objs>
	)
else()
	add_library(message-a
	SHARED
		$<TARGET_OBJECTS:message-objs>
	)
endif() 
	