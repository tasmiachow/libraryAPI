/*
Name: Tasmia Chowdhury 
Class: 235 
Date: 3/1

ArrayBag interface for term project
CSCI 235 Spring 2023
*/
#pragma once 

#include <iostream>
#include <vector>
#include "Book.hpp"
#include "ArrayBag.hpp"


class LibraryRecord: public ArrayBag<Book>{
    public:
        bool checkIn(const Book& a_book);
        bool checkOut(const Book& a_book);
        int getCheckOutHistory(const Book& a_book); 
        void display();
        void displayTitles();
        bool duplicateStock();
        bool removeStock(const Book& a_book);
        bool equivalentRecords(const LibraryRecord &rhs);
        void operator+=(LibraryRecord &rhs);
        void operator/=(LibraryRecord &rhs);
        
        /**void operator+=(const LibraryRecord &rhs) const; 

        void operator/=(const LibraryRecord &rhs) const;**/




    private:
        std::vector<Book> copy_of_out_books;

    
};
