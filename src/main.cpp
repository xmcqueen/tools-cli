#include "command_line.h"

int main(int argc, char *argv[]) {
  j2cli::CommandLine cli;

  return cli.Execute(argc, argv);
}
