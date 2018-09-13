#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    //sort segments
    std::sort(segments.begin(), segments.end(), [](Segment i, Segment j) {
        return i.end < j.end;
    });
    vector<int> points;
    //write your code here
    int end = segments[0].end;
    points.push_back(end);
    for (size_t i = 1; i < segments.size(); ++i) {
        // check if this point ISNOT between next segment
        if (!(segments[i].start <= end && segments[i].end >= end)) {
            //add this point to points must be visited
            end = segments[i].end;
            points.push_back(end);
        }
    }
    return points;
}

void testSolution() {
    {
        vector<Segment> segments = {Segment{3, 1}, Segment{2, 5}, Segment{3, 6}};
        vector<int> points = optimal_points(segments);
        std::cout << points.size() << "\n";
        for (size_t i = 0; i < points.size(); ++i) {
            std::cout << points[i] << " ";
        }
        std::cout << '\n';
    }
    {
        vector<Segment> segments = {Segment{4, 7}, Segment{1, 3}, Segment{2, 5}, Segment{5, 6}};
        vector<int> points = optimal_points(segments);
        std::cout << points.size() << "\n";
        for (size_t i = 0; i < points.size(); ++i) {
            std::cout << points[i] << " ";
        }
        std::cout << '\n';
    }

}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
    //testSolution();
}
