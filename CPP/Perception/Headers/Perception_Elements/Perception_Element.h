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

                    /*
                       Washes the value of the float to give a precision of expected amount
                    */
                    float Limit_Precision(float param_value_to_limit);

                    bool Is_A_Reasonable_Approximation(float param_value_to_approximate);

                    bool operator==(const Perception_Element element) const;

                    Perception_Element operator*(const Perception_Element element) const;

                    Perception_Element operator+(const Perception_Element element) const;

                    ~Perception_Element();

                private:
                    float value;

            };
        }
    }
}
#endif