/*
Name: Tasmia Chowdhury 
Class: 235 
Date: 3/1

ArrayBag interface for term project
CSCI 235 Spring 2023
*/

#include "LibraryRecord.hpp"


/** @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items_, false otherwise
    @post:    adds book to items_.
**/
bool LibraryRecord::checkIn(const Book& a_book){
    return add(a_book);
}

/** @param:   A reference to a Book object to be checked out   
    @return:  returns true if a book was successfully removed from items_, false otherwise
    @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books.
 **/
bool LibraryRecord::checkOut(const Book& a_book){
    if(remove(a_book)==true){
        copy_of_out_books.push_back(a_book);
        return true;
    }
    return false;
}

/**
    @param:   A reference to a Book object
    @return:  The number of times (int) the referenced Book has been checked out
*/
int LibraryRecord::getCheckOutHistory(const Book& a_book){
    int count;
    for(int i=0; i<copy_of_out_books.size(); i++){
        if(copy_of_out_books[i]==a_book){
            count+=1;
        }
       
    }
    return count;
}

/**
    @post:    Outputs the names of the Books in the LibraryRecord
     and the number of times each Book has been chceked out
**/
void LibraryRecord::display(){
   std::string displayed;
   for(int i =0; i<item_count_;i++){
        items_[i].display();
        std::cout<<"It has been checked out " + getCheckOutHistory(items_[i]);
        std::cout<<" times\n";
        
   } 
}

/**
     @post:    Prints the title of each Book in the LibraryRecord
     Example:
    "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
*/
void LibraryRecord::displayTitles(){
    std::string titles;
    for(int i =0; i<getCurrentSize()-1;i++){
        titles += items_[i].getTitle()+", ";
    }
    titles+=items_[-1].getTitle()+"!"+"\n";
    std::cout<<titles; 
}

/**
    @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
    @post:      Duplicates all the items in the LibraryRecord
**/
bool LibraryRecord::duplicateStock(){
    if(item_count_*2<DEFAULT_CAPACITY){
        for(int i=0; i<item_count_; i++){
            items_[item_count_] = items_[i];
            item_count_++;
        }
        return true;
    }
    return false;
}

/**
        @param:   A reference to a book
        @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
        @post: remove all occurrences of the referenced book
*/
bool LibraryRecord::removeStock(const Book& a_book){
    if(!contains(a_book)){
        return false;
    }
    while(contains(a_book)){
        remove(a_book);
    }
    return true;

}
/**
    @param:   A reference to another LibraryRecord
    @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), 
    regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
    and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.
*/
bool LibraryRecord::equivalentRecords(const LibraryRecord &rhs){
    if (getCurrentSize() != rhs.getCurrentSize()){
        return false;
    }
    for (int i = 0; i < getCurrentSize(); i++){
        if(!rhs.contains(copy_of_out_books[i])){
            return false;
        }
        else if(getFrequencyOf(copy_of_out_books[i])!=rhs.getFrequencyOf(copy_of_out_books[i]))
        {
            return false;
        }
        else{
            return true;
        }       
    }
}

/**
    @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, including duplicates.
 **/
void LibraryRecord:: operator+=(LibraryRecord &rhs) {
    int count=0;
        for(int i=0; i<rhs.item_count_;i++){
            if(item_count_==DEFAULT_CAPACITY){
                return;
            }
            add(rhs.items_[i]);
            count=rhs.getCheckOutHistory(rhs.items_[i]);
            for(int j=0; j<count;j++){
                copy_of_out_books.push_back(rhs.items_[i]);
            }    
        }
    }
    
/**
    @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
**/

void LibraryRecord::operator/=(LibraryRecord &rhs) {
   /** 
    int count=item_count_;
    if(item_count_==DEFAULT_CAPACITY){
        return;
    }
    else{
      for(int i=0; i<rhs.item_count_;i++){
         while(count<10){
            if(!contains(rhs.items_[i])){
               add(rhs.items_[i]);
               count++;
            }
        }
      }
    }
**/
    return;
}







