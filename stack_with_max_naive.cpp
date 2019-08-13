#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

vector<int> max_index;

class StackWithMax {
    vector<int> stack;

  public:

    void Push(int value) {
        stack.push_back(value);
        if(max_index.empty()){
        	max_index.push_back(stack.size()-1);
		}
		else if(stack[max_index.back()] <= value){
			max_index.push_back(stack.size()-1);
		} 
    }

    void Pop() {
    	int pop_value = stack.back();
        stack.pop_back();
        if(pop_value == stack[max_index.back()]){
        	max_index.pop_back();
		}
            
    }

    int Max() const {
        return	stack[max_index.back()];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;
	//int value;
    StackWithMax stack;
    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
