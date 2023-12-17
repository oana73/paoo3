#pragma once
#include <pthread.h>
#include <memory>
#include <vector>

class Jeans {
    protected: int id;
    	       int price;
               char* color;
               static int purchase;
    public: 
        Jeans(const char* color,int id, int price);
        ~Jeans();
        Jeans(const Jeans& copy);
        Jeans(Jeans&& move);
        
        Jeans& operator=(const Jeans &copy);
        Jeans& operator=(Jeans &&move);
        void display();
        static void initializeMutex();
        static void *buyJeans(void* arg);
    };

