#include <iostream>

#include "param_resolver.h"
#include <fstream>

// #include <jinja2cpp/template.h>
#include <jinja2cpp/binding/nlohmann_json.h>

using json = nlohmann::json;

namespace j2cli {

const jinja2::ValuesMap JsonParamResolver::ParamsFromFile(const std::string &filePath) {

  std::ifstream ifs(filePath);
  json jf = json::parse(ifs);
  //auto p2 = jf.get<params>();
  //return p2.params;
  auto x = jinja2::Reflect(std::move(jf));
  return {{"params", x}};
  // return jf.get<jinja2::ValuesMap>();

  // return jf;

  // nlohmann::json values = {
  //{"message", "Hello World from Parser!"},
  //{"name", "name1"},
  //{"asleep", false}
  //};
  // return Reflect(std::move(values));
  // auto x = Reflect(std::move(values));
  // return {{"params", x}};
  // return x;

  // ValuesMap params {
  //{"name", "name1"},
  //{"asleep", false},
  //};
  // return params;

  // std::map<std::string, std::vector<int>> m = { {"a", {1, 2}}, {"b", {2, 3}}
  // }; json j = m; std::cout << j << std::endl;
}

} // namespace j2cli
