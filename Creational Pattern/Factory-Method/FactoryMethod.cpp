/* FactoryMethod
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

#include <iostream>
#include <string>

/* 
 * 创建型模式之工厂方法
 *
 * 创建对象通过一个共同的接口指向新创建的对象，不会对客户端暴露创建逻辑
 * 
 * 使用场景：1. 日志可能记录到硬盘、远程服务器等，用户可以选择记录日志到什么地方。
 * 2. 数据库选择，选择不同数据库如MySQL, Oracle。
 * 3. 设计一个连接服务器的框架，需3个协议（“POP3”， “IMAP”， “HTTP”）,将这三个协议视为不同的产品类，共同实现一个接口。
 * 
 */


/*
*  这里以使用场景3为例 产品类
*/
class Protocol {
public:
    virtual ~Protocol() {}

    virtual std::string getProtocol() = 0;

    // ...
};


/*
*  具体产品1，子类进行定义
*/
class ConcreteProtocol_POP3 : public Protocol 
{
public:
    virtual ~ConcreteProtocol_POP3() {}

    std::string getProtocol() {
        return "POP3";
    }

    // ...
};

/*
*  具体产品2，子类进行定义
*/
class ConcreteProtocol_IMAP : public Protocol 
{
public:
    virtual ~ConcreteProtocol_IMAP() {}

    std::string getProtocol() {
        return "IMAP";
    }

    // ...
};


/*
*  具体产品3，子类进行定义
*/
class ConcreteProtocol_HTTP : public Protocol 
{
public:
    virtual ~ConcreteProtocol_HTTP() {}

    std::string getProtocol() {
        return "HTTP";
    }

    // ...
};


/*
*  工厂类（Creator）
*  抽象类
*/
class Creator {
public:
    virtual ~Creator() {}

    virtual Protocol* createProduct_POP3() = 0;
    virtual Protocol* createProduct_IMAP() = 0;
    virtual Protocol* createProduct_HTTP() = 0;

    virtual void removeProtocol(Protocol *) = 0;
};


/*
*  具体工厂类
*  实现工厂方法，用来创建具体产品
*/
class ConcreteCreator : public Creator {
public:
    ~ConcreteCreator() {}

    Protocol* createProduct_POP3() {
        return new ConcreteProtocol_POP3();
    }

    Protocol* createProduct_IMAP() {
        return new ConcreteProtocol_IMAP();
    }

    Protocol* createProduct_HTTP() {
        return new ConcreteProtocol_HTTP();
    }

    void removeProtocol(Protocol *p) {
        delete p;
    }

    // ...
};


// For test
int main() {
    Creator* creator = new ConcreteCreator();

    Protocol *p1 = creator->createProduct_POP3();
    std::cout << p1->getProtocol() << std::endl;
    creator->removeProtocol(p1);

    Protocol *p2 = creator->createProduct_IMAP();
    std::cout << p2->getProtocol() << std::endl;
    creator->removeProtocol(p2);

    Protocol *p3 = creator->createProduct_HTTP();
    std::cout << p3->getProtocol() << std::endl;
    creator->removeProtocol(p3);

    delete creator;
    return 0;
}