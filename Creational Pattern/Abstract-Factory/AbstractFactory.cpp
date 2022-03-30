/* AbstractFactory
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

/* 创建型模式之抽象工厂
*
*  抽象工厂可以理解为工厂方法的更深层的抽象，工厂方法模式的一个工厂只能创建一个具体产品，而
*  抽象工厂模式的一个工厂可以创建一个类型的产品。
*
*/

/*
*  A类型的产品
*/
class ProductA {
public:
    virtual ~ProductA() {}

    virtual std::string getName() = 0;
    // ...
};


/*
*  A类型的具体产品X
*/
class ConcreteProductAX : public ProductA{
public:
    virtual ~ConcreteProductAX() {}

    virtual std::string getName() {
        return "A-X";
    }
    // ...
};


/*
*  A类型的具体产品Y
*/
class ConcreteProductAY : public ProductA{
public:
    virtual ~ConcreteProductAY() {}

    virtual std::string getName() {
        return "A-Y";
    }
    // ...
};


/*
*  B类型的产品
*/
class ProductB {
public:
    virtual ~ProductB() {}

    virtual std::string getName() = 0;
    // ...
};


/*
*  B类型的具体产品X
*/
class ConcreteProductBX : public ProductB{
public:
    virtual ~ConcreteProductBX() {}

    virtual std::string getName() {
        return "B-X";
    }
    // ...
};


/*
*  B类型的具体产品Y
*/
class ConcreteProductBY : public ProductB{
public:
    virtual ~ConcreteProductBY() {}

    virtual std::string getName() {
        return "B-Y";
    }
    // ...
};


/*
*  抽象工厂
*  提供抽象接口用于创建一系列产品家族
*/
class AbstractFactor {
public:
    virtual ~AbstractFactor() {}

    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
    // ...
};

/*
*  相对AbstractFactory来说是具体工厂
*  该工厂包含一系列产品
*/
class ConcreteFactoryX : public AbstractFactor{
public:
    virtual ~ConcreteFactoryX() {}

    ProductA* createProductA() {
        return new ConcreteProductAX();
    }

    ProductB* createProductB() {
        return new ConcreteProductBX();
    }
};


class ConcreteFactoryY : public AbstractFactor{
public:
    virtual ~ConcreteFactoryY() {}

    ProductA* createProductA() {
        return new ConcreteProductAY();
    }

    ProductB* createProductB() {
        return new ConcreteProductBY();
    }
};


int main() {
    AbstractFactor* factoryX = new ConcreteFactoryX();
    AbstractFactor* factoryY = new ConcreteFactoryY();

    ProductA *p1 = factoryX->createProductA();
    std::cout << p1->getName() << std::endl;

    ProductB *p2 = factoryY->createProductB();
    std::cout << p2->getName() << std::endl;

    delete factoryY;
    delete factoryX;

    return 0;
}