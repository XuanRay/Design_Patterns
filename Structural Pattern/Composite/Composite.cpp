/* Composite
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之组合模式，又叫部分整体模式。
 *
 * 创建了对象组的树形结构模式
 * 
 * 使用场景：1. 算术表达式包含一个操作数、一个操作符和另一个操作数，其中，操作数又可以是操作数
 * 、操作符和另一个操作数
 * 2. 部分、整体场景，如树形菜单，文件和文件夹
 * 
 */ 

#include <iostream>
#include <vector>


/*  Component 
 *
 *  defines an interface for all objects in the composition
 *  including Composite and Leaf node.
 */ 
class Component {
public:
    virtual ~Component() {}

    virtual Component* getChild(int) {
        return NULL;
    }

    virtual void add(Component *) {/* ... */}
    virtual void remove(int) {/* ... */}

    virtual void operation() = 0;
};

 
/*  Composite
 *
 *  defines behavior of the components having children and store child component.
 */ 
class Composite : public Component{
public:
    ~Composite() {
        for (int i = 0; i < v.size(); ++i) {
            delete v[i];
        }
    }

    virtual Component* getChild(int index) {
        return v[index];
    }

    virtual void add(Component *c) {
        v.push_back(c);
    }

    virtual void remove(int index) {
        Component* child = v[index];
        v.erase(v.begin() + index);
        delete child;
    }

    virtual void operation() {
        for (int i = 0; i < v.size(); ++i) {
            v[i]->operation();
        }
    }


private:
    std::vector<Component *> v;
};


/* Leaf
 *
 * defines the behavior for the elements in the composition,
 * it has no children.
 */
class Leaf : public Component {
public:
    Leaf(int i) : id(i) {}

    ~Leaf() {}

    virtual void operation() {
        std::cout << "Leaf id" << id << " operation" << std::endl;
    }

private:
    int id;
};


int main() {
    Composite composite;

    for (int i = 0; i < 10; ++i) {
        composite.add(new Leaf(i));
    }

    composite.remove(0);
    composite.operation();

    return 0;
}