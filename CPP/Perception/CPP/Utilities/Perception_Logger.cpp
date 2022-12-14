#include <Perception_Logger.h>

using namespace Utilities;

Perception_Logger::Perception_Logger() {
}
  void Perception_Logger::Trace() {
    cout << "This is a trace severity message";
}

  void Perception_Logger::Debug() {
    cout << "This is a debug severity message";
}

  void Perception_Logger::Info() {
    cout << "This is an informational severity message";
}

  void Perception_Logger::Warning() {
    cout << "This is a warning severity message";
}

  void Perception_Logger::Error() {
    cout << "This is an error severity message";
}

  void Perception_Logger::Fatal() {
    cout << "and this is a fatal severity message";
}