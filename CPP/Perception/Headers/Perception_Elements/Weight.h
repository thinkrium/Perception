#ifndef WEIGHT_H
#define WEIGHT_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Weight : public Perception_Element
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
}
#endif // !WEIGHT_H
