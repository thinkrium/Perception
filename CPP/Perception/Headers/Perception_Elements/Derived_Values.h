#ifndef Derived_Values_H
#define Derived_Values_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Derived_Values : public Perception_Element
			{
			public:
				Derived_Values();
				Derived_Values(float param_value);
				~Derived_Values();
			};
		}
	}
}
#endif // !Derived_Values_H
