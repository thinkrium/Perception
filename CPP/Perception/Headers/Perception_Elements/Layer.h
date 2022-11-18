#ifndef LAYER_H
#define LAYER_H

#include <Root.h>
#include <Neural_Node.h>
#include <vector>
#include <random>

using namespace Utilities;
using namespace std;

namespace Perception {
    namespace Layer {
		class Layer
		{
			public:
				Layer();
				Layer(int param_node_count);
				void Set_Node_Count(int param_node_count);
				int Get_Node_Count();
				void Create_Layer_Nodes();
				void Create_Nodes_By_Count();
				void Create_Nodes_By_Count(int param_node_count);
				float Generate_Random_Numerical_Value();
				~Layer();

			private:
		
				int Neural_Node_Count;
				vector<Neural_Node> Neural_Nodes;
			};    
    }
}

#endif // !LAYER_H
