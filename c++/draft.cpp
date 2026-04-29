#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int id;
    string name;
    Node(int x, string s) : id(x), name(s) {
        cout << "构造函数被调用: id=" << id << ", name=" << name << endl;
    }
    Node(const Node& other) : id(other.id), name(other.name) {
        cout << "拷贝构造函数被调用" << endl;
    }
};

int main() {
    vector<Node> vec;
    
    cout << "--- push_back ---" << endl;
    vec.push_back(Node(1, "Apple"));  //区别emplace_back
    
    cout << "\n--- emplace_back ---" << endl;
    vec.emplace_back(2, "Banana");    // 直接构造，无拷贝
    
    return 0;
}