class Solution {
public:
    bool checkOverlap(int radius, int xcenter, int ycenter,
                      int x1, int y1, int x2, int y2) {

        int xi;
        int yi;                

       if(x1 > xcenter){
         xi = x1;
       }else if( x2 < xcenter){
          xi = x2;
       }else{
         xi = xcenter;
       }

          if(y1 > ycenter){
         yi = y1;
       }else if( y2 < ycenter){
          yi = y2;
       }else{
         yi = ycenter;
       }
        // Check whether closest point lies inside circle
        return sqrt ((xi - xcenter)*(xi - xcenter) + (yi - ycenter)*(yi - ycenter)) <= radius;
    }
};