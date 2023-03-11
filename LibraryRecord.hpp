/*
Name: Tasmia Chowdhury 
Class: 235 
Date: 3/1

LibraryRecord interface for term project
CSCI 235 Spring 2023
*/
#pragma once 

#include <iostream>
#include <vector>
#include "Book.hpp"
#include "ArrayBag.hpp"


class LibraryRecord: public ArrayBag<Book>{
    public:
        /** @param:   A reference to a Book object to be checked in
        @return:  returns true if a book was successfully added to items_, false otherwise
        @post:    adds book to items_.
        **/
        bool checkIn(const Book& a_book);

        /** @param:   A reference to a Book object to be checked out   
            @return:  returns true if a book was successfully removed from items_, false otherwise
            @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books.
        **/
        bool checkOut(const Book& a_book);

        /**
        @param:   A reference to a Book object
        @return:  The number of times (int) the referenced Book has been checked out
        */
        int getCheckOutHistory(const Book& a_book); 

        /**
        @post:    Outputs the names of the Books in the LibraryRecord 
        and the number of times each Book has been cheked out

        **/
        void display();

        /**
        @post:    Prints the title of each Book in the LibraryRecord
        Example:
        "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
        */
        void displayTitles();

        /**
        @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
        @post:      Duplicates all the items in the LibraryRecord
        */
        bool duplicateStock();

        /**
        @param:   A reference to a book
        @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
        @post: remove all occurrences of the referenced book
        */
        bool removeStock(const Book& a_book);
        
        /**
             @param:   A reference to another LibraryRecord
            @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), 
            regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
            and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.
        */
        bool equivalentRecords(const LibraryRecord &rhs);

        /**
        @param:   A reference to another LibraryRecord object
        @post:    Combines the contents from both LibraryRecord objects, including duplicates.
        **/
        void operator+=(LibraryRecord &rhs);


        /**
          @param:   A reference to another LibraryRecord object
          @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
        **/
        void operator/=(LibraryRecord &rhs);
        



    private:
        std::vector<Book> copy_of_out_books;

    
};
