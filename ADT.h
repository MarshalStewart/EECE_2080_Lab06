#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Node
{
public:

    Node(std::string _str, Node *_left, Node *_right);
    ~Node();

    std::string getStr();
    void setStr(std::string _str);
    Node *getLeft();
    void setLeft(Node *_left);
    Node *getRight();
    void setRight(Node *_right);
private:
    std::string str;
    Node *left;
    Node *right;
};

class IBST
{
public:
    
    IBST() {};
    ~IBST() {}; 
    // Accepts a node that is created outside this class.
    virtual void insert(Node *n) = 0;
    // accepts a value, locates the value in the tree and return pointer
    virtual Node *find(string str) = 0;
    virtual Node *findParent(string str) = 0;
    // returns the number of elements in the tree as an int
    virtual int getSize() = 0;
    virtual Node *getRoot() = 0;
    // returns std::vector with each node stored in order smallest to largest
    virtual vector<string> getAllAscending(Node *cur) = 0;
    // returns std::vector with each node stored in order largest to smallest
    virtual vector<string> getAllDescending(Node *cur) = 0;
    // removes all nodes in the tree while avoiding memory leaks
    virtual bool emptyTree() = 0;
    // Accepts a value, finds the value and removes it from the tree
    virtual bool remove(std::string str) = 0;
private:
};

class BST : public IBST
{
public:

    BST();
    BST(const BST &c);
    ~BST();
    void insert(Node *n) override;
    Node *find(string str) override;
    Node *findParent(string str) override;
    int getSize() override;
    Node *getRoot() override;
    vector<string> getAllAscending(Node *cur) override;
    vector<string> getAllDescending(Node *cur) override;
    bool emptyTree() override;
    bool remove(std::string str) override;
 
private:
    Node *root;
    int size;

};


