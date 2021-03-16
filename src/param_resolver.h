#pragma once

#include <jinja2cpp/value.h>

namespace j2cli {

struct IParamResolver {
  virtual ~IParamResolver() = default;

  virtual const jinja2::ValuesMap ParamsFromFile(const std::string &filePath) = 0;
};

class JsonParamResolver : public IParamResolver {
public:
  const jinja2::ValuesMap ParamsFromFile(const std::string &filePath) override;
};

} // namespace j2cli
