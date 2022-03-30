/* Proxy
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之代理模式
 *
 * 代理模式：隶属于structural Model : 一个类代表另一个类的功能
 * 为其他对象提供一种代理以提供对这个对象的访问。
 * 
 * 场景：买火车票去代理点；Windows中的快捷方式。
 * 
 * note: 1.和Adpter模式区别：Adapter模式主要改变接口，而Proxy模式不能改变所代理类的接口；
 * 2.和Decorater模式区别： Decorator主要为了增加功能，而Proxy模式为了加以控制。
 * 
 */


#include <iostream>


/* Subject : 抽象的接口 */
class Subject {
public:
    virtual ~Subject() {}

    virtual void request() = 0;
    //...
};


/* RealSubject class : 被代理对象 */
class RealSubject : public Subject {
public:
    virtual ~RealSubject() {}

    void request() {
        std::cout << "Real Subject Request." << std::endl;
    }
    //...
};


/* proxy class :  代理另一个类，实现控制 */
class Proxy: public Subject {
public: 
    virtual ~Proxy() {
        delete rs;
    }

    Proxy() {
        rs = new RealSubject();
    }

    void request() {
        rs->request();
    }
    //...

private:
    RealSubject* rs;
};


/* For Test */
int main() {
    Proxy *p = new Proxy();
    p->request();

    delete p;
}