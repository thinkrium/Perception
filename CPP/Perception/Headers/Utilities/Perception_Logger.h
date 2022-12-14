#ifndef PERCEPTION_LOGGER_H
#define PERCEPTION_LOGGER_H

#include <iostream>

using namespace std;

namespace Utilities {
	class Perception_Logger {
		public:
			Perception_Logger();
			  void Trace();
			  void Debug();
			  void Info();
			  void Warning();
			  void Error();
			  void Fatal();
	};
}

#endif // !PERCEPTION_LOGGER_H
