#ifndef ENUMS_H
#define ENUMS_H


namespace Utilities {
	enum  Neural_Node_Activation_Method
	{
		ReLu,
		Softmax,
		Sigmoid
	};

	enum Loss_Calculation_Method {
		CrossEntropy
	};

	enum Logging_Level {
		Trace,
		Debug,
		Info,
		Warning,
		Error,
		Fatal
	};



}


#endif // !ENUMS_H
