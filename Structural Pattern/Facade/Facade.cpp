/* Observer
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之外观模式
 *
 * 观察者模型：隶属于Structural Model。
 * 隐藏子系统的复杂性，给客户提供一个接口。
 * 
 * 场景：1.看病，由接待人员提供
 * 2.MVC模式
 * 
 */


#include <iostream>


class SubSystemA {
public:
    SubSystemA() {
        std::cout << "A ctor." << std::endl;
    }

    void suboperation() {
        std::cout << "SubSystemA Method." << std::endl;
    }
    //...
};

class SubSystemB {
public:
    void suboperation() {
        std::cout << "SubSystemB Method." << std::endl;
    }
    //...
};

class SubSystemC {
public:
    void suboperation() {
        std::cout << "SubSystemC Method." << std::endl;
    }
    //...
};


class Facade {
public:
    Facade() : a(new SubSystemA()), b(new SubSystemB()), c(new SubSystemC()) {}

    ~Facade() {
        delete c;
        delete b;
        delete a;
    }

    void operation1() {
        a->suboperation();
        b->suboperation();
    }

    void operation2() {
        c->suboperation();
    }

private:
    SubSystemA *a;
    SubSystemB *b;
    SubSystemC *c;
};


/* for test */
int main() {
    Facade* f = new Facade();
    f->operation1();
    f->operation2();

    delete f;
    return 0;
}