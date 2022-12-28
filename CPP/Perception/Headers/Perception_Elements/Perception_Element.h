#ifndef PERCEPTION_ELEMENT_H
#define PERCEPTION_ELEMENT_H

#include <Root.h>
using namespace Utilities;

namespace Perception {
    namespace Layer {
        namespace Element {
            class Perception_Element {
                public:
                    Perception_Element();

                    Perception_Element(float param_value);

                    void Set_Value(float param_value);

                    float Get_Value();

                    ~Perception_Element();

                private:
                    float value;

            };
        }
    }
}
#endif