package CognitionMap;

import CognitionMap.Elements.Cognition_Element;

public class Layer_Activation {


    public static Cognition_Element[][] Activate_By_ReLU(Cognition_Element [][] outputs) {

        for(int output_row_index = 0; output_row_index < outputs.length; output_row_index++) {
            for(int output_col_index = 0; output_col_index < outputs[output_row_index].length; output_col_index++) {
                if(outputs[output_row_index][output_col_index].value <= 0) {
                    outputs[output_row_index][output_col_index].value = 0;
                }
            }
        }
        return outputs;
    }

    /**
     * For every output index by row and column
     * Exponentiate the index
     *
     * For Every Row Sum the Exponentiated individual Values
     *
     * For every column in Each Row Divide that exponentiated value by the sum
     *
     * Set the new output index value ot the normalized value of the exponentiated output
     *
     * @param outputs
     * @return outputs
     */
    public static Cognition_Element[][] Activate_By_Softmax(Cognition_Element[][] outputs) {

        boolean test_summation;

        boolean output_row_has_been_summated;

        for(int output_row_index = 0; output_row_index < outputs.length; output_row_index++) {

            output_row_has_been_summated = false;
            test_summation = false;

            double exponentiated_sum = 0;

            for(int output_col_index = 0; output_col_index < outputs[output_row_index].length; output_col_index++) {

                 if(!output_row_has_been_summated) {
                    for (int normalizing_index = 0; normalizing_index < outputs[output_row_index].length; normalizing_index++) {

                        double output_value = (double) outputs[output_row_index][output_col_index].value;

                        output_value =
                                  Math.pow(
                                        Math.E,
                                        output_value
                                );

                        exponentiated_sum += output_value;

                        outputs[output_row_index][normalizing_index].value = (float) output_value;
                    }
                     output_row_has_been_summated = true;
                }
                outputs[output_row_index][output_col_index].value = (float) (outputs[output_row_index][output_col_index].value / exponentiated_sum);
            }
            output_row_has_been_summated = false;

        }
        return outputs;
    }
}
