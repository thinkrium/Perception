#ifndef Derived_Value_H
#define Derived_Value_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Derived_Value : public Perception_Element
			{
			public:
				Derived_Value();
				Derived_Value(float param_value);
				~Derived_Value();
			};
		}
	}
}
#endif // !Derived_Values_H
