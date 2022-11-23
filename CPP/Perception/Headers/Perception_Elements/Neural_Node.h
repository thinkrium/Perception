#ifndef Neural_Node_H
#define Neural_Node_H

#include <Input.h>
#include <Weight.h>
#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {

			class Neural_Node : public Perception_Element
 			{
				public:

					/*
						Instantiates an empty Neural Node which can be populated with
						content later
					 */
					Neural_Node();

					/*
					   Instantiate a Neural Node and assigns it a value for input
					   Param=param_input
					 */
					Neural_Node(float param_input);

					/*
					   Sets the input value of a Neural Node
					   Param=param_input
					*/
					void Set_Input(float param_input);
					/*
					Gets the input value of the Neural Node
					returns float input value
					*/
					float Get_Input();

					/*
					Destructor
					*/
					~Neural_Node();

				private:

					/*
					   The value of the node
					*/
					float input;
			};
		}
	}
}

#endif // !Neural_Node_H
