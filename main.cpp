#include <iostream>
#include "KdTree.h"

int main() {
    // Create an instance of KdTree
    KdTree kdTree;
    
    // Insert some restaurant locations into the tree
    kdTree.insert(Point(1.0, 2.0));
    kdTree.insert(Point(3.0, 6.0));
    kdTree.insert(Point(5.0, 1.0));
    kdTree.insert(Point(7.0, 8.0));
    kdTree.insert(Point(9.0, 9.0));

    // Define the query rectangle (lower-left, upper-right)
    Point lowerLeft(2.0, 2.0);
    Point upperRight(8.0, 8.0);

    // Perform the range query
    std::vector<Point> result = kdTree.rangeQuery(lowerLeft, upperRight);

    // Output the points found in the range
    std::cout << "Restaurants in the range (" << lowerLeft.x << ", " << lowerLeft.y 
              << ") to (" << upperRight.x << ", " << upperRight.y << "):" << std::endl;
    for (const auto& p : result) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }

    return 0;
}
