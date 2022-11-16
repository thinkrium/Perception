#ifndef Neural_Node_H
#define Neural_Node_H

namespace Cognition {

	namespace Layer {
		class Neural_Node
		{
			public:
				Neural_Node();
				Neural_Node(short param_input);
				void Set_Input(short param_input);
				short Get_Input();
				~Neural_Node();

			private:
				short input;

		};

	}
}

#endif // !Neural_Node_H
