
class Knapsack {


    public static void SelectionSort(int weight[], int value[]) {

        int n = weight.length;

        for (int i = 0; i < n; i++) {
            int maxIndex = i;

            for (int j = i + 1; j < n; j++) {
                double ratio1 = (double) value[j] / weight[j];
                double ratio2 = (double) value[maxIndex] / weight[maxIndex];

                if (ratio1 < ratio2) {
                    maxIndex = j;
                }

                int temp1 = value[j];
                value[j] = value[maxIndex];
                value[maxIndex] = temp1;

                int temp2 = weight[j];
                weight[j] = weight[maxIndex];
                weight[maxIndex] = temp2;
            }
        }
    
    }

    public static double getMaxValue(int[] weight, int[] values, int capacity) {
        double totalValue = 0.0;
        SelectionSort(weight, values);

        for (int i = 0; i < weight.length; i++) {
            int taken = Math.min(weight[i], capacity);
            totalValue += (double) (taken / weight[i]) * values[i];
            capacity -= taken;
        }
        return totalValue;
    }

    public static void main(String args[]) {
        int weight[] = { 10, 20, 30 };
        int values[] = { 100, 60, 120 };
        int capacity = 40;

        double ans = getMaxValue(weight, values, capacity);

        System.out.println("Max value : " + ans);
    }
}