#ifndef BIAS_H
#define BIAS_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Bias : public Perception_Element
			{
			public:
				Bias();
				Bias(float param_value);
				~Bias();
			};
		}
	}
}
#endif // !BIAS_H
