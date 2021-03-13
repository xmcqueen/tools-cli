#include "param_resolver.h"

// #include <jinja2cpp/template.h>
#include <jinja2cpp/binding/nlohmann_json.h>

using json = nlohmann::json;

namespace jinja2 {

const ValuesMap JsonParamResolver::ParamsFromFile(const std::string &filePath)
{
    nlohmann::json values = {
            {"message", "Hello World from Parser!"},
{"name", "name1"},
{"asleep", false}
    };
    auto x = Reflect(std::move(values));
    //return {{"params", x}};
    return x;

    //ValuesMap params {
        //{"name", "name1"},
        //{"asleep", false},
    //};
    //return params;
}

} // namespace jinja2
