#ifndef WEIGHT_H
#define WEIGHT_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Weight  : public Perception_Element
			{
			public:
				Weight();
				Weight(float param_value);
				~Weight();
			};
		}
	}
}
#endif // !WEIGHT_H
