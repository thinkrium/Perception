#ifndef PERCEPTION_LOGGER_H
#define PERCEPTION_LOGGER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <Enums.h>

using namespace std;

namespace Utilities {
	class Perception_Logger {
		public:
			  Perception_Logger();
			  void Trace(string param_message);
			  void Debug(string param_message);
			  void Info(string param_message);
			  void Warning(string param_message);
			  void Error(string param_message);
			  void Fatal(string param_message);
			  void Message(string param_message, Logging_Level param_logging_level);
	    private:
			string Log_Level_To_String(Logging_Level param_logging_level);
			fstream file;
			string fileName;
			bool toFile;
			string filePath;

	};
}

#endif // !PERCEPTION_LOGGER_H
