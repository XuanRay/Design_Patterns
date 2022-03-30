/* Flyweight
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之享元模式
 *
 * 享元模型：隶属于Structural Model。
 * 用于减少创建对象的数量，以减少内存占用和提高性能，享元模式尝试重用现有的同类对象，
 * 如果未找到，则创建新对象。
 * 
 * 场景：1.系统有大量相似对象；
 * 2.缓冲池场景。
 * 
 * note：注意分离外部状态与内部状态，否则可能引起线程安全问题。同时这些类必须有一个工厂加以控制。
 * 
 */


#include <iostream>
#include <map>


/* Flyweight接口 */
class Flyweight {
public:
    virtual ~Flyweight() {}

    virtual void operation() = 0;
    //...
};


/* 并不是所有的对象都是需要共享的 */
class UnsharedConcreteFlyweight : public Flyweight {
public:
    virtual ~UnsharedConcreteFlyweight() {}

    UnsharedConcreteFlyweight(const int intrinsic_state) : state(intrinsic_state) {}

    void operation() {
        std::cout << "Unshared Flyweight with state " << state << std::endl;
    }
    //...

private:
    int state;
};

/* 共享的对象 */
class ConcreteFlyweight : public Flyweight {
public:
    virtual ~ConcreteFlyweight() {}

    ConcreteFlyweight(const int s) : state(s) {}

    void operation() {
        std::cout << "Concrete Flyweight with state " << state << std::endl;
    }
    //...

private:
    int state;
};


/* 工厂类，管理这些个对象的 */
class FlyweightFactory {
public:
    ~FlyweightFactory() {
        for (auto it = flies.begin(); it != flies.end(); ++it) {
            delete it->second;
        }
        flies.clear();
    }

    Flyweight* getFlyweight(const int key) {
        if (flies.find(key) != flies.end()) {
            return flies[key];
        }
        ConcreteFlyweight* cfw = new ConcreteFlyweight(key);
        flies.insert(std::pair<int, Flyweight*>(key, cfw));
        return cfw;
    }
    //...

private:
    std::map<int, Flyweight*> flies;
};

/* for test */
int main() {
    FlyweightFactory* factory = new FlyweightFactory();
    factory->getFlyweight(1)->operation();
    factory->getFlyweight(2)->operation();

    delete factory;
    return 0;
}
