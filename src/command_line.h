#pragma once

#include <jinja2cpp/template.h>

#include <string>

namespace j2cli {

struct ICommands {
  virtual ~ICommands() = default;

  virtual std::string Help() = 0;
  virtual std::string Version() = 0;
  virtual void RenderTemplate(const std::string &fileName) = 0;
};

/**
 *  * CommandLine is analog CLI of python jinja2-cli
 *   */
class CommandLine : protected ICommands {
public:
  explicit CommandLine(
      std::unique_ptr<jinja2::Template> tpl = std::make_unique<jinja2::Template>());

  int Execute(int argc, char **argv);

protected:
  std::string Help() override;
  std::string Version() override;
  void RenderTemplate(const std::string &fileName) override;

private:
  std::unique_ptr<jinja2::Template> m_tpl;
};

} // namespace j2cli
