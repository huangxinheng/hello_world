class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);
        int total_area=area1+area2;
        int maxLeft=(A>E)?A:E;
        int minRight=(G>C)?C:G;
        if(minRight<maxLeft)
            return total_area;
        int maxBot=(B>F)?B:F;
        int minTop=(D>H)?H:D;
        if(maxBot>minTop)
            return total_area;
        return total_area-(minRight-maxLeft)*(minTop-maxBot);
    }
};