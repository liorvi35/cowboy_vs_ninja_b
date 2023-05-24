/**
 * @brief declarations for point object
 * @authors Lior Vinman
 */

#ifndef POINT_HPP

    #define POINT_HPP

    #include <iostream>
    using namespace std;

    namespace ariel
    {
        class Point
        {
            private:
                /**
                 * @brief x value
                 */
                double _x;

                /**
                 * @brief y value
                 */
                double _y;

            public:

                /**
                 * @brief default ctor - makes (0,0)
                 */
                Point();

                /**
                 * @brief standard ctor
                 * @param double x val
                 * @param double y val
                 */
                Point(double , double);

                /**
                 * @brief print point method as : (x,y)
                 */
                void Print();

                /**
                 * @brief moves players between points
                 * @param Point start
                 * @param Point end
                 * @param double distance
                 * @return shortest distance
                 */
                static Point moveTowards(const Point &, const Point &, double);

                /**
                 * @brief gets distance between two 2d points
                 * @return distance in CM
                 */
                double distance(const Point &) const;

                /**
                 * @brief getter for x val
                 * @return x
                 */
                double getX();

                /**
                 * @brief getter for y val
                 * @return y
                 */
                double getY();
        };
}

#endif