#ifndef Expected_Results_H
#define Expected_Results_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Expected_Results : public Perception_Element
			{
			public:
				Expected_Results();
				Expected_Results(float param_value);
				~Expected_Results();
			};
		}
	}
}
#endif // !Expected_Results_H
