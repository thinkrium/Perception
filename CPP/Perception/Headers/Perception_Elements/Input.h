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
			Input(short param_value);
			void Set_Value(short param_value);
			short Get_Value();
			~Input();

		private:
			short value;
		};

	}
}
#endif // !INPUT_H
