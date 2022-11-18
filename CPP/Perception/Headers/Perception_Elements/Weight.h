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
			Weight(float param_value);
			void Set_Value(float param_value);
			float Get_Value();
			~Weight();

		private:
			float value;
		};

	}
}
#endif // !WEIGHT_H
