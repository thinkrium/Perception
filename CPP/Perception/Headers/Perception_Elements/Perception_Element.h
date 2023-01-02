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

                    /*
                    * Calls the set_value function to set the value
                    * of the element
                    */
                    Perception_Element(float param_value);

                    /*
                       Sets the value current element
                       param_value: float to set by
                    */
                    void Set_Value(float param_value);

                    /*
                    *  Gets the value of the current element
                    */
                    float Get_Value();

                    /*
                       Washes the value of the float to give a precision of expected amount
                    */
                    float Limit_Precision(float param_value_to_limit);
  
                    /*
                       Checks the value for floating point math failures by accountig
                       for fractional percentages below a certain threshhold and compares
                       elements for boolean equality
                    */
                    bool operator==(const Perception_Element element) const;

                    /*
                    * Multiplies the value of the elements
                    */
                    Perception_Element operator*(const Perception_Element element) const;


                    /*
                    * Adds the value of the elements
                    */
                    Perception_Element operator+(const Perception_Element element) const;

                    /*
                       Obligatory Destructor
                    */
                    ~Perception_Element();

                private:
                    float value;

            };
        }
    }
}
#endif