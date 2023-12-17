#include "Jeans.hpp"
#include <iostream>
#include <pthread.h>
#include <memory>

int main(int argc, char* argv[])
{   
    Jeans::initializeMutex();

    std::shared_ptr<Jeans> a = std::make_shared<Jeans>("babyBlue", 1,25);
    a->display();
    
    std::shared_ptr<Jeans> b = a;
    b->display();
    
    std::weak_ptr<Jeans> c = a;
    auto jns = c.lock();
    if(jns) {
        jns->display();
    }

    pthread_t threads[3];
    int id, ids[3] = {1, 2, 3};
    std::shared_ptr<Jeans> jeans[3] = {a, b, jns};

    for(id = 0; id < 3; id++)
        pthread_create(&threads[id], nullptr, jeans[id]->buyJeans, &ids[id]);

    for(id = 0; id < 3; id++)
        pthread_join(threads[id], nullptr);

    return 0;
}
