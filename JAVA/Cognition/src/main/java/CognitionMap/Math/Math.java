package CognitionMap.Math;

public class Math {

    public static float DotProduct(float[][] list1, float[][] list2) {
        float sum = 0;

        for (int x_index = 0; x_index < list1.length; x_index++) {
            for (int y_index = 0; y_index < list2.length; y_index++) {
                sum += list1[x_index][y_index] * list2[x_index][y_index];
            }
        }
       return  sum;
    }
}
