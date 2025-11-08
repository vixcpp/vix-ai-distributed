cmake_minimum_required(VERSION 3.20)

#[[
Vix.AI Distributed — assert-based tests (header-only)
]]

add_executable(vix_ai_distrib_test_peer peer_tests.cpp)
target_link_libraries(vix_ai_distrib_test_peer PRIVATE Vix::AI::distributed)
target_compile_features(vix_ai_distrib_test_peer PRIVATE cxx_std_20)
add_test(NAME distrib_peer COMMAND vix_ai_distrib_test_peer)

add_executable(vix_ai_distrib_test_secure secure_tests.cpp)
target_link_libraries(vix_ai_distrib_test_secure PRIVATE Vix::AI::distributed)
target_compile_features(vix_ai_distrib_test_secure PRIVATE cxx_std_20)
add_test(NAME distrib_secure COMMAND vix_ai_distrib_test_secure)

add_executable(vix_ai_distrib_test_fl fl_tests.cpp)
target_link_libraries(vix_ai_distrib_test_fl PRIVATE Vix::AI::distributed)
target_compile_features(vix_ai_distrib_test_fl PRIVATE cxx_std_20)
add_test(NAME distrib_fl COMMAND vix_ai_distrib_test_fl)

add_executable(vix_ai_distrib_test_sync sync_tests.cpp)
target_link_libraries(vix_ai_distrib_test_sync PRIVATE Vix::AI::distributed)
target_compile_features(vix_ai_distrib_test_sync PRIVATE cxx_std_20)
add_test(NAME distrib_sync COMMAND vix_ai_distrib_test_sync)
