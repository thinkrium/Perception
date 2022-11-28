// Perception.cpp : Defines the entry point for the application.
//

#include "Perception.h"
#include <Layer.h>
#include <gtest/gtest.h>

using namespace std;
using namespace Perception::Layer::Element;

int main(int argc, char** argv)
{

	Layer layer(3);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
