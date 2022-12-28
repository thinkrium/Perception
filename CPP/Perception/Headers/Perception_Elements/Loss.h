#ifndef LOSS_H
#define LOSS_H

#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {
			class Loss : public Perception_Element
			{
			public:
				Loss();
				Loss(float param_value);
				~Loss();
			};
		}
	}
}
#endif // !LOSS_H
