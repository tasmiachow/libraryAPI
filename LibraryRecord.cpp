/*
Name: Tasmia Chowdhury 
Class: 235 
Date: 3/1

Library Bag Method Implementation
CSCI 235 Spring 2023
*/

#include "LibraryRecord.hpp"

/** @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items_, false otherwise
    @post:    adds book to items_.
**/
bool LibraryRecord::checkIn(const Book& a_book){
    bool output = false;
    if(add(a_book) == true){
        output = true;
    }
    return output;
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
    else{
        return false;
    }
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
  for (int i = 0; i < getCurrentSize(); i++){
    items_[i].display();
    std::cout << "It has been checked out " << getCheckOutHistory(items_[i]) <<" times.\n";
  }
}

/**
     @post:    Prints the title of each Book in the LibraryRecord
     Example:
    "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
*/
void LibraryRecord::displayTitles(){
    std::string titles;
    for(int i = 0; i < getCurrentSize(); i++){
    if(i > 0)
    {
      std::cout << ", ";
    }
    std::cout << items_[i].getTitle() << "";
    if(i == (getCurrentSize() - 1))
    {
      std::cout << "!\n";
    }
  }
}

/**
    @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
    @post:      Duplicates all the items in the LibraryRecord
**/
bool LibraryRecord::duplicateStock(){
  bool final = false;
  if((item_count_ *2) <= DEFAULT_CAPACITY)
  {
    final = true;
    int before_dup_size = 0;
    before_dup_size = getCurrentSize();
    int j = 0;
        for(int i = 0; i < before_dup_size; i++)
        {
            items_[getCurrentSize()] = items_[j];
            item_count_++;
            j++;
        }
  }
  return final;
}

/**
        @param:   A reference to a book
        @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
        @post: remove all occurrences of the referenced book
*/
bool LibraryRecord::removeStock(const Book& a_book){
  bool final = false;
  int occurence = 0;
  occurence = getFrequencyOf(a_book);
  for(int i = 0; i < occurence; i++)
  {
    remove(a_book);
    final= true;
  }
  return final;

}
/**
    @param:   A reference to another LibraryRecord
    @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), 
    regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
    and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.
*/
bool LibraryRecord::equivalentRecords(const LibraryRecord &rhs){
   bool final = false;
    for(int i = 0; i < getCurrentSize(); i++){
    if(getFrequencyOf(items_[i]) != rhs.getFrequencyOf(items_[i])){
      final = false;
      break;
    }
    else if(rhs.contains(items_[i]) == true)
    {
      final = true;
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
  int totalCount= item_count_ + rhs.item_count_;
   if (totalCount<= DEFAULT_CAPACITY)
   {
      for (int i = 0; i < rhs.item_count_; i++)
      {
         if(!contains(rhs.items_[i]))
         {
            items_[item_count_] = rhs.items_[i];
            item_count_++;

          for(int j = 0; j < rhs.getCheckOutHistory(rhs.items_[i]); j++){
            copy_of_out_books.push_back((rhs.items_[i]));
            } 
         }
      }
   }
}







