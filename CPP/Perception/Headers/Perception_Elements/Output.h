#ifndef Output_H
#define Output_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Output : public Perception_Element
			{
			public:
				Output();
				Output(float param_value);
				~Output();
			};
		}
	}
}
#endif // !Output_H
