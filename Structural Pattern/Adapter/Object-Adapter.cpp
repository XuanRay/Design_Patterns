/* Adapter
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */


/**
 * 设计模式之适配器模式
 * 
 * 适配器模式用在将一个类的接口转换成另一个接口，相当于一个转接器的功能。
 * 
 * 使用场景：1. 220v和110v电压的转换器；
 * 2. 读卡器   3. java中的jdbc
 * 
 * 适配器可以分为类适配器和对象适配器。
 */

#include <iostream>


/*  Client
 * 
 *  define the interface that users want to use
 */
class Client {
public:
    virtual ~Client() {}

    virtual void request() = 0;

    //...
};


/*  Adaptee 
 *
 *  defines the existing interface that needs adapting.
 */
class Adaptee {
public:
    ~Adaptee() {}

    void existedInterface() {
        std::cout << "It is a existed interface." << std::endl;
    }

    //...
};


/*  Adapter
 *
 *  achieve the effect of Adapter by object.
 */
class Adapter : public Client {
public:
    Adapter() : adaptee() {}

    virtual ~Adapter() {
        delete adaptee;
    }

    virtual void request() {
        adaptee->existedInterface();
    }

    //...

private:
    Adaptee* adaptee;
};


int main() {
    Client* c = new Adapter();
    c->request();

    delete c;
    return 0;
}


