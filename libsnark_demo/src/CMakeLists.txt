include_directories(.)

add_executable(
  main

  main.cpp
)
target_link_libraries(
  main

  snark
)
target_include_directories(
  main

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)

add_executable(
  fc

  fc.cpp
)
target_link_libraries(
  fc

  snark
)
target_include_directories(
  fc

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)

add_executable(
  range

  range.cpp
)
target_link_libraries(
  range

  snark
)
target_include_directories(
  range

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)

add_executable(
  conv

  conv.cpp
)
target_link_libraries(
  conv

  snark
)
target_include_directories(
  conv

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)
add_executable(
  relu

  relu.cpp
)
target_link_libraries(
  relu

  snark
)
target_include_directories(
  relu

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)
add_executable(
  maxpool

  maxpool.cpp
)
target_link_libraries(
  maxpool

  snark
)
target_include_directories(
  maxpool

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)
add_executable(
  softmax

  softmax.cpp
)
target_link_libraries(
  softmax

  snark
)
target_include_directories(
  softmax

  PUBLIC
  ${DEPENDS_DIR}/libsnark
  ${DEPENDS_DIR}/libsnark/depends/libfqfft
)

