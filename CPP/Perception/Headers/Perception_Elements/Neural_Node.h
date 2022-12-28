#ifndef Neural_Node_H
#define Neural_Node_H

 #include <Weight.h>
#include <Perception_Element.h>

using namespace Utilities;

namespace Perception {

	namespace Layer {
		namespace Element {

			class Neural_Node  : public Perception_Element
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
					Destructor
					*/
					~Neural_Node();

			 
			};
		}
	}
}

#endif // !Neural_Node_H
