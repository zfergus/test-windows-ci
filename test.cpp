#include <catch2/catch_test_macros.hpp>

#include <nlohmann/json.hpp>

TEST_CASE("test json", "[json]")
{
    nlohmann::json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    CHECK(j["happy"].get<bool>());
    CHECK(j["pi"] == 3.141);
    CHECK(j.value("/test/pointer"_json_pointer, true));
    CHECK(j.value("/test/pointer"_json_pointer, false) == false);
}