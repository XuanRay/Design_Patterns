/* Prototype
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */


/** 构建型模式之原型模型（Prototype)
 *  
 *  Prototype用于创建重复的对象，同时保证性能，即创建当前对象的克隆。
 * 
 *  应用场景：
 *  1. 一个对象需要在一个高代价的数据库操作之后被创建，可以缓存该对象，在下一个请求时返回它的克隆，在需要的时候
 *  更新数据，减少数据库调用。
 */ 

#include <iostream>
#include <string>

class Prototype {
public:
    virtual ~Prototype() {}

    virtual Prototype *clone() = 0;
    virtual std::string type() = 0;
    // ...
};


class ConcretePrototypeA : public Prototype {
public:
    virtual ~ConcretePrototypeA() {}

    Prototype* clone() {
        return new ConcretePrototypeA();
    }

    std::string type() {
        return "Type A";
    }
    // ...
};


class ConcretePrototypeB : public Prototype {
public:
    virtual ~ConcretePrototypeB() {}

    Prototype* clone() {
        return new ConcretePrototypeB();
    }

    std::string type() {
        return "Type B";
    }
    // ...
};


/* client
*  创建一个新的对象，通过告知prototype克隆自身
*/
class Client {
public:
    static void init() {
        type[0] = new ConcretePrototypeA();
        type[1] = new ConcretePrototypeB();
    }

    static void remove() {
        delete type[0];
        delete type[1];
    }

    static Prototype* make(const int index) {
        if (index >= num_types) {
            return nullptr;
        }
        return type[index]->clone();
    }

private:
    static Prototype* type[2];
    static int num_types;
};

Prototype* Client::type[2];
int Client::num_types = 2;


int main() {
    Client::init();

    Prototype *prototype1 = Client::make(0);
    std::cout << prototype1->type() << std::endl;
    delete prototype1;

    Prototype *prototype2 = Client::make(1);
    std::cout << prototype2->type() << std::endl;
    delete prototype2;

    Client::remove();

    return 0;
}