#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <iterator>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
        this->parent = NULL;
    }

    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};

int treeHeight(const std::vector<Node> &nodes) {
    std::queue<Node> queue;
    // find the root of tree
    int max_height = 0;
    for (auto &node : nodes) {
        if (node.parent == NULL) {
            queue.push(node);
            break;
        }
    }
	Node marker;
	marker.key = -2;
	queue.push(marker);
	// traverse tree breadth-first
	while (!queue.empty()) {
		auto node = queue.front();
		queue.pop();
		if (node.key == marker.key ) {
			max_height++;
			if (!queue.empty())
				queue.push(marker);
		}
		else {
			if (!node.children.empty()) {
				for (auto child : node.children) {
					queue.push(*child);
				}
			}
		}
	}
    return max_height;
}

void testSolution() {
	for (int i = 1; i < 24; i++) {
		std::ostringstream testName;
		testName << "../tests_tree_height/" << std::setfill('0') << std::setw(2) << i;
		std::ifstream testFile(testName.str());
		std::cout << testName.str() << std::endl;
		std::ostringstream ansName;
		ansName << "../tests_tree_height/" << std::setfill('0') << std::setw(2) << i << ".a";
		std::cout << ansName.str() << std::endl;
		std::ifstream AnsFile(ansName.str());
		std::string text_number_nodes;
		std::string text_node_indices;
		// read number of nodes
		getline(testFile, text_number_nodes);
		int number_nodes = std::stoi(text_number_nodes);
		// read nodes indices
		getline(testFile, text_node_indices);
		std::vector<int> node_indices;
		std::stringstream ss(text_node_indices);
		std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(),
			std::back_inserter(node_indices));
		// create nodes 
		std::vector<Node> nodes;
		nodes.resize(number_nodes);
		for (int child_index = 0; child_index < number_nodes; child_index++) {
			int parent_index = node_indices[child_index];
			if (parent_index >= 0)
				nodes[child_index].setParent(&nodes[parent_index]);
			nodes[child_index].key = child_index;
		}
		std::string text_ans;
		getline(AnsFile, text_ans);
		int ans = std::stoi(text_ans);
		if (treeHeight(nodes) == ans)
			std::cout << "Passed Test " << i << std::endl;
		else
			throw "NOT PASSED";
	}

}

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        nodes[child_index].key = child_index;
    }
	std::cout << treeHeight(nodes) << std::endl;
    return 0;
}

int main(int argc, char **argv) {
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }

#endif
//	testSolution();
    return main_with_large_stack_space();
}
