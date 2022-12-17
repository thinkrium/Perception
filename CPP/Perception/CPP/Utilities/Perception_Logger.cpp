#include <Perception_Logger.h>

using namespace Utilities;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

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

  string Perception_Logger::Determine_Log_Level_Color(Logging_Level param_logging_level) {
      switch (param_logging_level) {
      case Logging_Level::Trace:
          return  RESET;
          break;
      case Logging_Level::Debug:
          return YELLOW;
          break;
      case Logging_Level::Info:
          return RESET;
          break;
      case Logging_Level::Warning:
          return YELLOW;
          break;
      case Logging_Level::Error:
          return RED;
          break;
      case Logging_Level::Fatal:
          return MAGENTA;
          break;
      default:
          return "That is not a Log Level!";
      }
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
      auto tt = time(nullptr);
      auto* ti = localtime(&tt);
      std::stringstream time_stamp;
      time_stamp << std::put_time(ti, "%c");
        string time_stamped_message = this->Determine_Log_Level_Color(param_logging_level) + "Log Level: " + this->Log_Level_To_String(param_logging_level ) + RESET + " - [" + time_stamp.str() + "] " + param_message;

        cout << time_stamped_message << endl;
        if (this->toFile) {
            this->file << time_stamped_message << endl;
        }
  }

  Perception_Logger::~Perception_Logger() {}