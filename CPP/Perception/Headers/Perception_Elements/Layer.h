#ifndef LAYER_H
#define LAYER_H

#include <Root.h>
#include <Neural_Node.h>
#include <vector>

using namespace Utilities;
using namespace std;

namespace Perception {
    namespace Layer {
		class Layer
		{
			public:
				Layer();
				~Layer();

			private:
		
				vector<Neural_Node> Node;
			};    
    }
}

#endif // !LAYER_H
