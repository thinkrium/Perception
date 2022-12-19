#ifndef EXPECTED_RESULTS_H
#define	EXPECTED_RESULTS_H

#include <Perception_Element.h>
#include <vector>

using namespace std;
using namespace Perception::Layer::Element;

namespace Perception {
    namespace Layer {

		class Expected_Results : public Perception_Element
		{
		public:
			Expected_Results();
			~Expected_Results();

		private:
			vector<int> oneHotEncodingExpectation;
		};

		Expected_Results::Expected_Results()
		{
		}

		Expected_Results::~Expected_Results()
		{
		}
    }
}
#endif // EXPECTED_RESULTS_H