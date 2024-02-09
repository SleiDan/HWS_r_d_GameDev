#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

class Node {
public:
    int data;
    Node* next;

    Node(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    void push_front(int data)
    {
        Node* node = new Node(data);

        if (head != nullptr)
        {
            node->next = head;
        }

        head = node;
    }

    void popFront() {}

private:
    Node* head = nullptr;
};

//TODO, check if there're cycles in the list
// Node1 -> Node2 -> Node1 -> true
// Node1 -> Node2 -> Node3 -> false
bool has_cycle(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return false; // If head or head->next is null, no cycle
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast)
            return true; // If slow and fast meet, there's a cycle
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return false; // If fast reaches the end, there's no cycle
}


unsigned int uniqueWordsCount(const std::string& line) {
    std::set<std::string> uniqueWords;
    std::string word;
    for (char c : line) {
        if (c == ' ') {
            if (!word.empty()) {
                uniqueWords.insert(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        uniqueWords.insert(word);
    }
    return uniqueWords.size();
}

std::string mostOccuredWord(const std::string& line) {
    std::map<std::string, int> wordCount;
    std::string word;
    for (char c : line) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordCount[word]++;
    }
    std::string mostOccured;
    int maxCount = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostOccured = pair.first;
        }
    }
    return mostOccured;
}

bool areParenthesesBalanced(const std::string& line) {
    std::stack<char> stack;
    for (char c : line) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false; // More closing than opening
            }
            char top = stack.top();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // Mismatched parentheses
            }
            stack.pop();
        }
    }
    return stack.empty(); // Check if any opening parentheses are left unmatched
}


int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(5);
    Node* node3 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1; //OOPS, cycle is formed

    std::cout << "Cycle is present: " << (has_cycle(node1) ? "Yes" : "No") << std::endl;

    // Free memory (deallocate nodes)
    delete node1;
    delete node2;
    delete node3;
    std::string line = "Hello Hey Hello Bye Hey";
    std::cout << "Unique words count: " << uniqueWordsCount(line) << std::endl;

    std::cout << "Most occurred word: " << mostOccuredWord(line) << std::endl;

    std::string line3 = "{ [()][ ] }()";
    std::cout << "Parentheses balanced? " << (areParenthesesBalanced(line3) ? "Yes" : "No") << std::endl;

    std::string line4 = "[{]}";
    std::cout << "Parentheses balanced? " << (areParenthesesBalanced(line4) ? "Yes" : "No") << std::endl;
}
