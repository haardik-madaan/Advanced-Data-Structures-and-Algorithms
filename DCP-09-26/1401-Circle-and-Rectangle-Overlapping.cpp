class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xClosest;
        int yClosest;
        if(xCenter >= x1 && xCenter <= x2){
            xClosest = xCenter;
        }
        else if(xCenter <= x1 && xCenter < x2){
            xClosest = x1;
        }
        else if(xCenter > x1 && xCenter >= x2){
            xClosest = x2;
        }
        if(yCenter >= y1 && yCenter <= y2){
            yClosest = yCenter;
        }
        else if(yCenter <= y1 && yCenter < y2){
            yClosest = y1;
        }
        else if(yCenter > y1 && yCenter >= y2){
            yClosest = y2;
        }

        return ((xClosest - xCenter)*(xClosest - xCenter) + (yClosest - yCenter)*(yClosest - yCenter)) <= (radius)*(radius);
    }
};