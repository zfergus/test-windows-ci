#include <catch2/catch_test_macros.hpp>

#include <nlohmann/json.hpp>

TEST_CASE("test json", "[json]")
{
    using json = nlohmann::json;
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    CHECK(j["happy"].get<bool>());
    CHECK(j["pi"] == 3.141);
    CHECK(j.value("/test/pointer"_json_pointer, true));
    CHECK(j.value("/test/pointer"_json_pointer, false) == false);

    // Fallback to default linear solver if the specified solver is invalid
    if (j.value("/solver/linear/enable_overwrite_solver"_json_pointer, false)) {
        const json::json_pointer ptr = "/solver/linear/solver"_json_pointer;
        const std::vector<std::string> ss = { { "A", "B", "C" } };
        std::string s_json = "null";
        if (!j.contains(ptr) || !j[ptr].is_string()
            || std::find(ss.begin(), ss.end(), j[ptr].get<std::string>())
                == ss.end()) {
            if (j.contains(ptr) && j[ptr].is_string())
                s_json = j[ptr].get<std::string>();
            j[ptr] = "A";
        }
    }
}