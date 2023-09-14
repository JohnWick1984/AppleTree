// AppleTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Apple 
{
public:
    Apple(int weight) : weight(weight), left(nullptr), right(nullptr) {}

    int getWeight() const
    {
        return weight;
    }

    bool operator==(const Apple& other) const 
    {
        return weight == other.weight;
    }

    bool operator<(const Apple& other) const
    {
        return weight < other.weight;
    }

    bool operator>(const Apple& other) const 
    {
        return weight > other.weight;
    }

    Apple* left;
    Apple* right;

private:
    int weight;
};

class Tree 
{
public:
    Tree() : root(nullptr) {}

    void insert(const Apple& apple) 
    {
        root = insertRecursive(root, apple);
    }

    void print() const 
    {
        printInOrder(root);
    }

private:
    Apple* root;

    Apple* insertRecursive(Apple* current, const Apple& apple)
    {
        if (current == nullptr) 
        {
            return new Apple(apple.getWeight());
        }

        if (apple < *current)
        {
            current->left = insertRecursive(current->left, apple);
        }
        else
        {
            current->right = insertRecursive(current->right, apple);
        }

        return current;
    }

    void printInOrder(const Apple* current) const 
    {
        if (current != nullptr) 
        {
            printInOrder(current->left);
            cout << "Apple with weight " << current->getWeight() << "g\n";
            printInOrder(current->right);
        }
    }
};

int main() 
{
    
    srand(time(0));

    Tree tree;
    for (int i = 0; i < 20; ++i) 
    {
        int randomWeight = rand() % 151 + 50; 
        Apple apple(randomWeight);
        tree.insert(apple);
    }

    cout << "Apples on the tree:\n";
    tree.print();

    return 0;
}
