cmake_minimum_required(VERSION 3.2)

project(light-stax)

add_library(light-stax INTERFACE)
target_include_directories(light-stax INTERFACE
    include/ref-stax/
    include/lit-stax/
)
