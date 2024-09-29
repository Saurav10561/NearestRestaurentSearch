#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include <algorithm>
#include <cmath>

// Define a Point struct for 2D coordinates (x, y)
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Node structure for KdTree
struct Node {
    Point point;
    Node* left;
    Node* right;
    Node(Point p) : point(p), left(nullptr), right(nullptr) {}
};

class KdTree {
private:
    Node* root;
    Node* insert(Node* node, Point point, unsigned depth);
    void rangeSearch(Node* node, Point lowerLeft, Point upperRight, unsigned depth, std::vector<Point>& result);
    double distance(Point p1, Point p2);

public:
    KdTree();
    void insert(Point point);
    std::vector<Point> rangeQuery(Point lowerLeft, Point upperRight);
};

#endif // KDTREE_H
