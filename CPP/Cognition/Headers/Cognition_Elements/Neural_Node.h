#ifndef Neural_Node_H
#define Neural_Node_H

#include <Root.h>
using namespace Utilities;

namespace Cognition {

	namespace Layer {
		class Neural_Node : public Root
		{
			public:
				Neural_Node();
				Neural_Node(short param_input);
				Neural_Node(short param_input, short param_weight);
				void Set_Input(short param_input);
				short Get_Input();
				void Set_Weight(short param_weight);
				short Get_Weight();
				~Neural_Node();

			private:
				short input;
				short weight;

		};

	}
}

#endif // !Neural_Node_H
