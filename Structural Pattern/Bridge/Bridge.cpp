/* Bridge
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之桥接模式。
 *
 * 桥接模式隶属于Structural Pattern。
 * 
 * 将抽象化和实现化解耦。
 * 
 * 使用场景：最典型的场景是 画不同颜色的图形（如正方形、圆形等）。
 * 
 */ 

#include <iostream>


/* 实现类的抽象接口 */
class Implementor {
public:
    virtual ~Implementor() {}

    virtual void action() = 0;
    //...
};


/* 具体实现类 */
class ConcreteImplementorA : public Implementor {
public:
    virtual ~ConcreteImplementorA() {}

    void action() {
        std::cout << "Concrete Implementation A." << std::endl;
    }
    //...
};


/* 具体实现类 */
class ConcreteImplementorB : public Implementor {
public:
    virtual ~ConcreteImplementorB() {}

    void action() {
        std::cout << "Concrete Implementation B." << std::endl;
    }
    //...s
};


/* 抽象类接口 */
class Abstract {
public:
    virtual ~Abstract() {}

    virtual void operation() = 0;
    //...
};


/* 抽象类 */
class ConcreteAbstract : public Abstract {
public:
    virtual ~ConcreteAbstract() {}

    ConcreteAbstract(Implementor* i) : implementor(i) {}

    void operation() {
        implementor->action();
    }
    //...

private:
    Implementor* implementor;
};


/* for test */
int main() {
    ConcreteImplementorA* a = new ConcreteImplementorA();
    ConcreteImplementorB* b = new ConcreteImplementorB();

    ConcreteAbstract* ca = new ConcreteAbstract(a);
    ca->operation();

    ConcreteAbstract* cb = new ConcreteAbstract(b);
    cb->operation();

    delete a;
    delete b;
    delete ca;
    delete cb;

    return 0;
}

