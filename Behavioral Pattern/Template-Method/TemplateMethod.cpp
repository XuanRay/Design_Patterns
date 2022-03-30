/* Template Method
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

#include <iostream>

/* 行为型模式之模板方法
 *
 * 一个抽象类公开定义一套方法，子类重写实现，但调用将以抽象类中定义的方式和顺序进行
 * 
 * 使用场景：
 * 1. 一个通用的算法框架
 * 
 */ 

class TemplateMethod {
public:
    virtual ~TemplateMethod() {}

    void templateMethod() {
        // ...
        primitiveOperation1();
        // ...
        primitiveOperation2();
        // ...
    }

    virtual void primitiveOperation1() = 0;

    virtual void primitiveOperation2() = 0;
    // ...
};


class SubTemplateMethod : public TemplateMethod{
public:
    virtual ~SubTemplateMethod() {}

    void primitiveOperation1() {
        std::cout << "Operation1" << std::endl;
        // ...
    }

    void primitiveOperation2() {
        std::cout << "Operation2" << std::endl;
        // ...
    }
};


int main() {
    TemplateMethod* tm = new SubTemplateMethod();
    tm->templateMethod();

    delete tm;
    return 0;
}