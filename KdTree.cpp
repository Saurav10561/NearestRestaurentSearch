#include "KdTree.h"

// Constructor for KdTree
KdTree::KdTree() : root(nullptr) {}

// Function to insert a new point into the tree
Node* KdTree::insert(Node* node, Point point, unsigned depth) {
    if (node == nullptr) return new Node(point);
    
    unsigned cd = depth % 2; // 0: compare x, 1: compare y

    if ((cd == 0 && point.x < node->point.x) || (cd == 1 && point.y < node->point.y))
        node->left = insert(node->left, point, depth + 1);
    else
        node->right = insert(node->right, point, depth + 1);

    return node;
}

void KdTree::insert(Point point) {
    root = insert(root, point, 0);
}

// Function to perform range search within a rectangular area
void KdTree::rangeSearch(Node* node, Point lowerLeft, Point upperRight, unsigned depth, std::vector<Point>& result) {
    if (node == nullptr) return;

    // Check if the point is within the rectangular range
    if (node->point.x >= lowerLeft.x && node->point.x <= upperRight.x &&
        node->point.y >= lowerLeft.y && node->point.y <= upperRight.y) {
        result.push_back(node->point);
    }

    unsigned cd = depth % 2;
    
    if ((cd == 0 && lowerLeft.x < node->point.x) || (cd == 1 && lowerLeft.y < node->point.y))
        rangeSearch(node->left, lowerLeft, upperRight, depth + 1, result);

    if ((cd == 0 && upperRight.x >= node->point.x) || (cd == 1 && upperRight.y >= node->point.y))
        rangeSearch(node->right, lowerLeft, upperRight, depth + 1, result);
}

std::vector<Point> KdTree::rangeQuery(Point lowerLeft, Point upperRight) {
    std::vector<Point> result;
    rangeSearch(root, lowerLeft, upperRight, 0, result);
    return result;
}

double KdTree::distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
