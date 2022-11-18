#ifndef INPUT_H
#define INPUT_H

#include <Root.h>

using namespace Utilities;


namespace Perception {

	namespace Layer {
		class Input : public Root
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
#endif // !INPUT_H
