/* Decorator
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之装饰器模式
 *
 * 装饰器模式：隶属于structural Model : 动态给一个对象增加一些额外的功能。
 * 可作为继承的替代，在不想引入很多子类时使用。
 * 
 * 场景：扩展一个类的功能；动态添加、动态撤销。
 * 
 */


#include <iostream>


/* 待装饰类的接口 */
class Component {
public:
    virtual ~Component() {}

    virtual void operation() = 0;
    //...
};


/* 待装饰类 */
class ConcreteComponent : public Component {
public:
    ~ConcreteComponent() {}

    void operation() {
        std::cout << "Concrete Component Operation." << std::endl;
    }
    //...
};


/* 装饰类接口 */
class Decorator {
public:
    virtual ~Decorator() {}

    Decorator(Component* c) : component(c) {}

    virtual void operation() {
        component->operation();
    }

private:
    Component* component;
};


/* 具体装饰类， 扩充待装饰类的功能 */
class ConcreteDecoratorA : public Decorator{
public:
    virtual ~ConcreteDecoratorA() {}

    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    void operation() {
        Decorator::operation();
        std::cout << "Concrete Decorator A." << std::endl;
    }
};


class ConcreteDecoratorB : public Decorator{
public:
    virtual ~ConcreteDecoratorB() {}

    ConcreteDecoratorB(Component* c) : Decorator(c) {}

    void operation() {
        Decorator::operation();
        std::cout << "Concrete Decorator B." << std::endl;
    }
};


/* for test */
int main() {
    ConcreteComponent* cc = new ConcreteComponent();
    cc->operation();

    ConcreteDecoratorA* aa = new ConcreteDecoratorA(cc);
    aa->operation();

    delete aa;
    delete cc;
    return 0;
}
