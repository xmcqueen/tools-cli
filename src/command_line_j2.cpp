#include "command_line.h"
#include <version.h>

#include "j2cli.h"

namespace jinja2
{

CommandLineJ2::CommandLineJ2(std::unique_ptr<Template> tpl) : m_tpl(std::move(tpl)) { }

int CommandLineJ2::Execute(int argc, char* argv[])
{
    // todo: implement me
    return 0;
}

std::string CommandLineJ2::Help()
{
    return "Usage: j2cpp-cli [options] <input template> <input data>";
}

std::string CommandLineJ2::Version()
{
    return J2CLI_VERSION_STR;
}


void CommandLineJ2::RenderTemplate(const std::string& fileName)
{
    // todo: implement me
}

} // namespace jinja2
