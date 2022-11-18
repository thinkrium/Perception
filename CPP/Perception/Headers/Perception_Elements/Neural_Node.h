#ifndef Neural_Node_H
#define Neural_Node_H

#include <Root.h>
#include <Input.h>
#include <Weight.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		class Neural_Node : public Root
		{
			public:
				Neural_Node();
				Neural_Node(float param_input);
				Neural_Node(float param_input, float param_weight);
				void Set_Input(float param_input);
				float Get_Input();
				void Set_Weight(float param_weight);
				float Get_Weight();
				~Neural_Node();

			private:
				float input;
				float weight;

		};

	}
}

#endif // !Neural_Node_H
