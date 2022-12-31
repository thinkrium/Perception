#ifndef Prediction_H
#define Prediction_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Prediction : public Perception_Element
			{
			public:
				Prediction();
				Prediction(float param_value);
				~Prediction();
			};
		}
	}
}
#endif // !Prediction_H
