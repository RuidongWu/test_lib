project(protobuf_example)

find_package(Protobuf REQUIRED)

if(PROTOBUF_FOUND)
    message ("protobuf found")
else()
    message (FATAL_ERROR "Cannot find Protobuf")
endif()

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS Book.proto)

message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")

add_executable(
    protobuf_example
    proto.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

target_include_directories(
    protobuf_example
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
    protobuf_example
    PUBLIC
    ${PROTOBUF_LIBRARIES}
)

