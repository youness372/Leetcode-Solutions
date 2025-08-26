class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        double max = 0;
    int result = 0;

    for (int i = 0; i < dimensions.length; i++) {
        double res = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
        double diagonal = Math.sqrt(res);

        if (diagonal > max) {
            max = diagonal;
            result = dimensions[i][0] * dimensions[i][1];
        } else if (diagonal == max && dimensions[i][0] * dimensions[i][1] > result) {
            result = dimensions[i][0] * dimensions[i][1];
        }
    }

    return result;
    }
}
