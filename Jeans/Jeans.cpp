#include "Jeans.hpp"
#include <iostream>
#include <cstring>
#include <mutex>

pthread_mutex_t std::mutex;
int Jeans::purchase;

Jeans::Jeans(const char* color,int id, int price){

    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    
    this->id=id;
    this->price = price;
}

Jeans::~Jeans() {

    std::cout<<"Destructor JeansID "<< this->id << std::endl;
    delete[] color;
}

void Jeans::initializeMutex() {
    pthread_mutex_init(&std::mutex, nullptr);
}

Jeans::Jeans(const Jeans &copy) {
    std::cout<<"Copy constructor"<<std::endl;
    this->id = copy.id;
    this->price = copy.price;
    
    this->color = new char[strlen(copy.color) + 1];
    strcpy(this->color, copy.color);
    
}

Jeans::Jeans(Jeans &&move) {
    std::cout<<"Move constructor"<<std::endl;
    this->id = move.id;
    this->price = move.price;
    
    this->color = new char[strlen(move.color) + 1];
    strcpy(this->color, move.color);

    move.id=0;
    move.price = 0;
    move.color = nullptr;
}


Jeans& Jeans::operator=(const Jeans &copy){
    if(this != &copy){
    	std::cout<< "Copy assignment"<< std::endl;
    	this->id = copy.id;
        this->price = copy.price;

        delete[] this -> color;
        this->color = new char[strlen(copy.color) + 1];
        strcpy(this->color, copy.color);

    }
    return *this;
}

Jeans& Jeans::operator=(Jeans &&move){
 if(this != &move){
 	std::cout<< "Move assignment"<< std::endl;
    	this->id = move.id;
        this->price = move.price;
	this->color = move.color;
	
	move.id=0;
	move.price=0;
	move.color=nullptr;

    }
    return *this;
}

void *Jeans::buyJeans(void* arg) {
    pthread_mutex_lock(&std::mutex);
    purchase++;
    std::cout << "The item is bought!"<<"\nThread " << *(int*)arg << std::endl;
    std::cout << purchase << " Bought jeans!\n" <<std::endl;
    pthread_mutex_unlock(&std::mutex);
    pthread_exit(NULL);
}

void Jeans::display() {
    if(this->color == nullptr) {
        std::cout << "This jeans has been deleted!" <<std::endl;
        return;
    }
        
    std::cout << "This pair of jeans " << id << " costs "<< price <<"$" <<" and has the " <<this->color <<" color " << std::endl;
}

