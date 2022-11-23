#ifndef INPUT_H
#define INPUT_H

#include <Perception_Element.h>

using namespace Utilities;


namespace Perception {

	namespace Layer {
		namespace Element {
			class Input : public Perception_Element
			{
			public:
				Input();
				Input(float param_value);
				void Set_Value(float param_value);
				float Get_Value();
				~Input();

			private:
				float value;
			};
		}
	}
}
#endif // !INPUT_H
