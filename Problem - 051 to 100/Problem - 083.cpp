#include <iostream>
#include <queue>
#include <vector>

//static std::uint_fast32_t numbers[80][80];

class Node {
public:
    Node() = default;
    Node(const int wi, const int he, const int va) 
        : width(wi), height(he), val(va) {
    }
    int width;
    int height;
    int val;
};


int Solve() {
    auto u = [](Node a, Node b) { 
        return a.val > b.val; 
    };
    std::priority_queue< Node, std::vector<Node>, decltype(u)> nodes(u);
    
    bool checked[80][80] = { 0 };
    Node node = { 0, 0, 0 };
    
    nodes.push( { 0, 0, numbers[ 0 ][ 0 ] } );
    for (; !nodes.empty(); nodes.pop()) {
        node = nodes.top();
        
        //! Reached end
        if (node.height == 79 && node.width == 79) {
            break;
        }
        
        const int nodeW = node.width;
        const int nodeH = node.height;
        const int nodeV = node.val;
        
        const int iter[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        
        for (const auto& e : iter) {
            const int first = nodeW + e[0];
            const int second = nodeH + e[1];
            
            if (first >= 0 && first < 80 && second >= 0 && second < 80 && !checked[first][second] ) {
                checked[first][second] = true;
                nodes.push( { first, second, nodeV + numbers[first][second] } );
            }
        }
    } 
    return node.val;   
}


int main() {    
    const int solution = Solve();
    std::cout << "Solution: " << solution << std::endl;
}

