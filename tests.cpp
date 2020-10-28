#include <gtest/gtest.h>
#include "ADT.cpp"
#include <iostream>
#include <chrono>

TEST(BST, Add)
{ 
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);
    ASSERT_TRUE(tree->getSize() == 6);

    delete tree;
}

TEST(BST, Find)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    Node *f = tree->find("6");
    bool equal = (f->getStr() == "6");
    ASSERT_TRUE(equal);
    f = tree->find("5");
    equal = (f->getStr() == "5");
    ASSERT_TRUE(equal);
    f = tree->find("4");
    equal = (f->getStr() == "4");
    ASSERT_TRUE(equal);
    f = tree->find("3");
    equal = (f->getStr() == "3");
    ASSERT_TRUE(equal);
    f = tree->find("2");
    equal = (f->getStr() == "2");
    ASSERT_TRUE(equal);
    f = tree->find("1");
    equal = (f->getStr() == "1");
    ASSERT_TRUE(equal);
    delete tree;
}

TEST(BST, FindParent)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    Node *f = tree->findParent("6");
    bool equal = (f->getStr() == "5");
    ASSERT_TRUE(equal);
    
    f = tree->findParent("5");
    equal = (f->getStr() == "3");
    ASSERT_TRUE(equal);
    
    f = tree->findParent("4");
    equal = (f->getStr() == "5");
    ASSERT_TRUE(equal);
    equal = false;

    f = tree->findParent("3");
    if (f != nullptr)
        equal = false;
    else
        equal = true;
    ASSERT_TRUE(equal);
    
    f = tree->findParent("2");
    equal = (f->getStr() == "3");
    ASSERT_TRUE(equal);

    f = tree->findParent("1");
    equal = (f->getStr() == "2");
    ASSERT_TRUE(equal);

    delete tree;
}

TEST(BST, Ascending)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    Node *root = tree->getRoot();
    vector <std::string> ascending = tree->getAllAscending(root);
    vector <std::string> cpy = {"1", "2", "3", "4", "5", "6"};
    ASSERT_TRUE(ascending == cpy);
    delete tree;
}

TEST(BST, Descending)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    Node *root = tree->getRoot();
    vector <std::string> descending = tree->getAllDescending(root);
    vector <std::string> cpy = {"6", "5", "4", "3", "2", "1"};
    ASSERT_TRUE(descending == cpy);

    delete tree;

}

TEST(BST, Remove)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    tree->remove("6");
    ASSERT_TRUE(tree->getSize() == 5);
    tree->remove("1");
    ASSERT_TRUE(tree->getSize() == 4);
    tree->remove("2");
    ASSERT_TRUE(tree->getSize() == 3);


    delete tree;
}

TEST(BST, EmptyTheTree)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("1", nullptr, nullptr);
    Node *n_2 = new Node("2", nullptr, nullptr);
    Node *n_4 = new Node("4", nullptr, nullptr);
    Node *n_6 = new Node("6", nullptr, nullptr);
    Node *n_5 = new Node("5", nullptr, nullptr);
    Node *n_3 = new Node("3", nullptr, nullptr);
    tree->insert(n_3);
    tree->insert(n_2);
    tree->insert(n_1);
    tree->insert(n_5);
    tree->insert(n_4);
    tree->insert(n_6);

    ASSERT_TRUE(tree->emptyTree());
    ASSERT_TRUE(tree->getSize() == 0);    

    delete tree;

}

TEST(BST, Space)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("Star Wars", nullptr, nullptr);
    Node *n_2 = new Node("Star Trek", nullptr, nullptr);
    Node *n_3 = new Node("Space Balls", nullptr, nullptr);
    Node *n_4 = new Node("Galaxy Quest", nullptr, nullptr);
    tree->insert(n_1);
    tree->insert(n_2);
    tree->insert(n_3);
    tree->insert(n_4);

    Node *root = tree->getRoot();

    vector <std::string> ascend = tree->getAllAscending(root);
    vector <std::string> descend = tree->getAllDescending(root);

    vector <std::string> m_ascend  = {"Galaxy Quest", "Space Balls", "Star Trek", "Star Wars"};
    vector <std::string> m_descend = {"Star Wars", "Star Trek", "Space Balls", "Galaxy Quest"};

    for (auto i : ascend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(ascend == m_ascend);

    for (auto i : descend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(descend == m_descend);

}

TEST(BST, Disney)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("Cars", nullptr, nullptr);
    Node *n_2 = new Node("Monsters Inc.", nullptr, nullptr);
    Node *n_3 = new Node("The Incredibles", nullptr, nullptr);
    Node *n_4 = new Node("Wall-E", nullptr, nullptr);
    tree->insert(n_1);
    tree->insert(n_2);
    tree->insert(n_3);
    tree->insert(n_4);
    
    Node *root = tree->getRoot();

    vector <std::string> ascend = tree->getAllAscending(root);
    vector <std::string> descend = tree->getAllDescending(root);

    vector <std::string> m_ascend = {"Cars", "Monsters Inc.", "The Incredibles", "Wall-E"};
    vector <std::string> m_descend = {"Wall-E", "The Incredibles", "Monsters Inc.", "Cars"};

    for (auto i : ascend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(ascend == m_ascend);

    for (auto i : descend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(descend == m_descend);
}

TEST(BST, Spooky)
{
    BST *tree = new BST();
    ASSERT_FALSE(tree->getSize());
    Node *n_1 = new Node("Halloween", nullptr, nullptr);
    Node *n_2 = new Node("A Nightmare On Elm Street", nullptr, nullptr);
    Node *n_3 = new Node("Hocus Pocus", nullptr, nullptr);
    Node *n_4 = new Node("Beetlejuice", nullptr, nullptr);
    tree->insert(n_1);
    tree->insert(n_2);
    tree->insert(n_3);
    tree->insert(n_4);
    
    Node *root = tree->getRoot();

    vector <std::string> ascend = tree->getAllAscending(root);
    vector <std::string> descend = tree->getAllDescending(root);

    vector <std::string> m_ascend = {"A Nightmare On Elm Street", "Beetlejuice", "Halloween", "Hocus Pocus"};
    vector <std::string> m_descend = {"Hocus Pocus", "Halloween", "Beetlejuice", "A Nightmare On Elm Street"};

    for (auto i : ascend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(ascend == m_ascend);

    for (auto i : descend)
        std::cout << i << ", ";
    std::cout << std::endl;
    ASSERT_TRUE(descend == m_descend);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}
