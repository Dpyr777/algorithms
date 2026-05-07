#include <math.h>
#include "types.h"

Point derivative(double x, double y, int choice){
        Point ans;
        switch(choice){
            case 1:
                ans.x = 2 * x - 2 - 400 * x * y + 400 * x * x * x;  
                ans.y = 200 * y - 200 * x * x;
                break;
            case 2:
                ans.x = 4 * x * (x * x + y - 11) + 2 * (x + y * y - 7);
                ans.y = 2 * (x * x + y - 11) + 4 * y * (x + y * y - 7);
                break;
            case 3:
                ans.x = 2 * x + 20 * M_PI * sin(2 * x * M_PI);
                ans.y = 2 * y + 20 * M_PI * sin(2 * y * M_PI);
                break;
        }
        return ans;
}
