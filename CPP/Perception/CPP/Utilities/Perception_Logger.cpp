#include <Perception_Logger.h>

using namespace Utilities;

Perception_Logger::Perception_Logger() {

    this->toFile = false;
}
  void Perception_Logger::Trace(string param_message) {
      this->Message(param_message, Logging_Level::Trace);
}

  void Perception_Logger::Debug(string param_message) {
      this->Message(param_message, Logging_Level::Debug);
  }

  void Perception_Logger::Info(string param_message) {
      this->Message(param_message, Logging_Level::Info);
  }

  void Perception_Logger::Warning(string param_message) {
      this->Message(param_message, Logging_Level::Warning);
  }

  void Perception_Logger::Error(string param_message) {
      this->Message(param_message, Logging_Level::Error);
  }

  void Perception_Logger::Fatal(string param_message) {
      this->Message(param_message, Logging_Level::Fatal);
  }

void Perception_Logger::Message(string param_message, Logging_Level param_logging_level) {
    cout << param_message << endl;
    if (this->toFile) {
        this->file << param_message << endl;
    }
}