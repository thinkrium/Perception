#ifndef WEIGHT_H
#define WEIGHT_H

#include <Root.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		class Weight : public Root
		{
		public:
			Weight();
			Weight(short param_value);
			void Set_Value(short param_value);
			short Get_Value();
			~Weight();

		private:
			short value;
		};

	}
}
#endif // !WEIGHT_H
