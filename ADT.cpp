#include "ADT.h"

// RIP ILAN 2020-2020

int getBiggerString(std::string s1, std::string s2)
{
    int ret = s1.compare(s2);
    if (ret == 0)
        return 0;
    else if (ret < 0)
        return 2;
    else
        return 1;

}


Node::Node(std::string _str, Node *_left, Node *_right)
{
    str = _str;
    left = _left;
    right = _right;
}

Node::~Node()
{
    if (left != nullptr)
        delete left;
    if (right != nullptr)
        delete right;
}

string Node::getStr() { return str; }
void Node::setStr(string _str) {str = _str; } 
void Node::setLeft(Node *_left) { left = _left; }
Node *Node::getLeft() { return left; }
void Node::setRight(Node *_right) { right = _right; }
Node *Node::getRight() { return right; }


BST::BST()
{
    root = nullptr;
    size = 0;
}

BST::~BST()
{
    delete root;
}

void BST::insert(Node *n)
{
    // If empty, set root to new node
    if (size == 0)
    {
        root = n;
        size++;
        return;
    }

    Node *cur = root;
    Node *prv = nullptr;
    
    while (cur != nullptr)
    {
        prv = cur;

        // compare new node to current
        if (getBiggerString(n->getStr(), cur->getStr()) == 2)
            cur = cur->getLeft();
        else
            cur = cur->getRight(); 
        
    }

    // check if can be inserted to the left
    if (getBiggerString(n->getStr(), prv->getStr()) == 2)
    {
        prv->setLeft(n);
        size++;
    }
    else
    {
        prv->setRight(n);
        size++;
    }

}

Node *BST::find(string str)
{
    // Start by checking left until not less than or at end
    Node *cur = root;
    Node *cur_left = nullptr;
    Node *cur_right = nullptr;
    while (cur != nullptr)
    {
        cur_left = cur->getLeft();
        cur_right = cur->getRight();

        // Check for match
        if (str.compare(cur->getStr()) == 0)
        {
            return cur;
        }
        if (cur_left != nullptr) if (str.compare(cur_left->getStr()) == 0)        
        {
            return cur_left;
        }
        if (cur_right != nullptr) if (str.compare(cur_right->getStr()) == 0)
        {
            return cur_right;
        }

        bool size;
        if (cur_left == nullptr)
            size = false; 
        else
            size = (getBiggerString(str, cur_left->getStr()) == 2);

        // Navigate Down
        if (size)
        {
            cur = cur_left;
        }
        else if (cur_right != nullptr) 
        {
            cur = cur_right;
        }
        else
            cur = nullptr;
    }

    return nullptr;

}

Node *BST::findParent(std::string str)
{
    // Start by checking left until not less than or at end
    Node *cur = root;
    Node *cur_left = nullptr;
    Node *cur_right = nullptr;
    Node *prv = nullptr;
    while (cur != nullptr)
    {
        cur_left = cur->getLeft();
        cur_right = cur->getRight();

        // Check for match
        if (str == cur->getStr())
        {
            return nullptr;
        }
        if (cur_left != nullptr) if (str == cur_left->getStr())        
        {
            return cur;
        }
        if (cur_right != nullptr) if (str == cur_right->getStr())
        {
            return cur;
        }

        // Navigate Down
        if (getBiggerString(str, cur_left->getStr()) == 2)
        {
            cur = cur_left;
        }
        else
        {
            cur = cur_right;
        }
        prv = cur;
    }

    return nullptr;

}


int BST::getSize(){ return size; }

Node *BST::getRoot() {return root; }

vector<string> BST::getAllAscending(Node *cur)
{
    vector<std::string> ascending;
    if (cur == nullptr)
        return ascending;
    vector<std::string> tmp1 = getAllAscending(cur->getLeft());
    vector<std::string> tmp2 = getAllAscending(cur->getRight()); 
    ascending.insert(ascending.end(), tmp1.begin(), tmp1.end());
    ascending.insert(ascending.end(), cur->getStr());
    ascending.insert(ascending.end(), tmp2.begin(), tmp2.end());

    return ascending;
}

vector<string> BST::getAllDescending(Node *cur)
{
    vector<std::string> descending;
    if (cur == nullptr)
        return descending;
    vector<std::string> tmp1 = getAllDescending(cur->getRight());
    vector<std::string> tmp2 = getAllDescending(cur->getLeft()); 
    descending.insert(descending.end(), tmp1.begin(), tmp1.end());
    descending.insert(descending.end(), cur->getStr());
    descending.insert(descending.end(), tmp2.begin(), tmp2.end());

    return descending;

}

bool BST::emptyTree()
{
    delete root;
    root = nullptr;
    size = 0;
    return true;
}


bool BST::remove(string str)
{
    Node *cur = find(str);
    Node *parent = findParent(str);

    if (cur == nullptr)
        return false;

    if (root == nullptr)
        return false;

    // No children
    if ((cur->getLeft() == nullptr) && (cur->getRight() == nullptr))
    {
        // just delete the node
        if (parent != nullptr)
        {  // check if parent is bigger or smaller than node to be removed
            if (getBiggerString(parent->getStr(), cur->getStr()) == 2)
                parent->setRight(nullptr);
            else 
                parent->setLeft(nullptr);
        }
        delete cur;
        size--;
        return true;
    }
    // one child on the right
    else if (cur->getLeft() == nullptr)
    {
        Node *tmp = cur->getRight();
        if (parent != nullptr)
        {
            if (getBiggerString(parent->getStr(), cur->getStr()) == 2)        
            {
                parent->setRight(tmp);
            }
            else 
            {
                parent->setLeft(tmp);
            }
        }
        else 
            root = tmp;
            
        cur->setLeft(nullptr);
        cur->setRight(nullptr);
        delete cur;
        size--;
        return true;

    }
    // one child on the left
    else if (cur->getRight() == nullptr)
    {
        Node *g_child = cur->getLeft();
        if (parent != nullptr)
        {
            if (getBiggerString(parent->getStr(), cur->getStr()) == 2)        
                parent->setRight(g_child);
            else 
                parent->setLeft(g_child);
        }
        else
            root = g_child;

        cur->setLeft(nullptr);
        cur->setRight(nullptr);
        delete cur;
        size--;
        return true;       

    }
    // two children
    else 
    {
        // get left most grandchild from the right child
        Node *gChild = cur->getRight();
        while (gChild->getLeft() != nullptr)
            gChild = gChild->getLeft();

         
        // have parent point to grandchild
        if (parent != nullptr)
        {
            if (getBiggerString(parent->getStr(), gChild->getStr()) == 2)        
                parent->setRight(gChild);
            else 
                parent->setLeft(gChild);
        }
        else // if parent is nullptr
        {
            // assign grandchild to root
            root = gChild;
        }
        
        // place right child of temp to parent of temp
        Node *tmp_parent = findParent(gChild->getStr());
        tmp_parent->setLeft(gChild->getRight());

        // Set the children of cur to the children of temp
        gChild->setLeft(cur->getLeft());
        gChild->setRight(cur->getRight());

        // Remove Cur
        cur->setLeft(nullptr);
        cur->setRight(nullptr);
        delete cur; 
        size--;
        return true;
    }
}
