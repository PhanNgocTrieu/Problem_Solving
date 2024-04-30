#ifndef __MATH_H__
#define __MATH_H__

#include "common.h"

namespace tpn
{
    class Problems_Of_Math
    {
        /**
         * @brief Including images folder: 
         * problems of finding the inversion or point reflection of p point accress q point to be a 180 degree rotation of point p around q
         * 
         * @param px position x of p on x co-ordinate
         * @param py position y of p on y co-ordinate
         * @param qx position x of q on x co-ordinate
         * @param qy position y of p on y co-ordinate
         * @return vector<int> {x,y} of r point
         */
        vector<int> findPoint(int px, int py, int qx, int qy)
        {
            // int rx = (qx - px) + qx;

            return vector<int>() = {(qx - px) + qx, (qy - py) + qy};
        }
    };

};

#endif //__MATH_H__