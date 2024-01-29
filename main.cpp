//
// Created by vladimir on 29.01.24.
//
#include <cstddef>
#include <deque>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution116 {
public:
    static Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        std::deque<Node*> dummy;
        dummy.push_back(root);
        dummy.push_back(nullptr);
        while(!dummy.empty()){
            auto current = dummy.front();
            dummy.pop_front();
            if(!current)
                continue;
            auto right = dummy.front();

            dummy.push_back(nullptr);
            dummy.push_back(current->left);
            dummy.push_back(current->right);
            if(right != nullptr){
                current->next = right;
                dummy.push_back(right->left);
                dummy.push_back(right->right);


            }
            else
                dummy.pop_front();
        }
        return root;
    }
};

class Solution117 {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        std::deque<Node*> dummy;
        dummy.push_back(root);
        dummy.push_back(nullptr);
        while(!dummy.empty()){
            auto current = dummy.front();
            dummy.pop_front();
            if(!current)
                continue;
            auto right = dummy.front();
            dummy.push_back(nullptr);
            if(current->left)
                dummy.push_back(current->left);
            if(current->right)
                dummy.push_back(current->right);
            if(right != nullptr){
                current->next = right;
                if(right->left != nullptr)
                    dummy.push_back(right->left);
                if(right->right != nullptr)
                    dummy.push_back(right->right);

            }
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    Node* Left = new Node(2);
    Left->left = new Node(4);
    Left->right = new Node(5);
    root->left = Left;
    Node* Right = new Node(3);
    Right->left = new Node(6);
    Right->right = new Node(7);
    root->right = Right;
    auto new_root = Solution116::connect(root);

}
