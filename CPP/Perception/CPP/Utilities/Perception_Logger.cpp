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

  string Perception_Logger::Log_Level_To_String(Logging_Level param_logging_level) {
      switch (param_logging_level) {
          case Logging_Level::Trace:
              return "Trace";
              break;
          case Logging_Level::Debug:
              return "Debug";
              break;
          case Logging_Level::Info:
              return "Info";
              break;
          case Logging_Level::Warning:
              return "Warning";
              break;
          case Logging_Level::Error:
              return "Error";
              break;
          case Logging_Level::Fatal:
              return "Fatal";
              break;
          default:
              return "That is not a Log Level!";
      }
  }

  void Perception_Logger::Message(string param_message, Logging_Level param_logging_level) {
        time_t result = std::time(nullptr);
        string time_stamp = asctime(std::localtime(&result));
        string time_stamped_message ="Log Level: " + this->Log_Level_To_String(param_logging_level ) + " - [" + time_stamp + "] " + param_message;
        if (this->toFile) {
            this->file << time_stamped_message << endl;
        }
  }