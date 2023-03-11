#include "LibraryRecord.hpp"



bool LibraryRecord::checkIn(const Book& a_book){
    return add(a_book);
}

bool LibraryRecord::checkOut(const Book& a_book){
    if(remove(a_book)==true){
        copy_of_out_books.push_back(a_book);
    }
    return remove(a_book);
}


int LibraryRecord::getCheckOutHistory(const Book& a_book){
    int count;
    for(int i=0; i<copy_of_out_books.size(); i++){
        if(copy_of_out_books[i]==a_book){
            count+=1;
        }
       
    }
    return count;
}


void LibraryRecord::display(){
   for(int i =0; i<item_count_;i++){
    items_[i].display();
   } 

}



void LibraryRecord::displayTitles(){
    std::string titles;
    for(int i =0; i<getCurrentSize()-1;i++){
        titles += items_[i].getTitle()+", ";
    }
    titles+=items_[-1].getTitle()+"!"+"\n";
    std::cout<<titles; 
}



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




bool LibraryRecord::removeStock(const Book& a_book){
    if(!contains(a_book)){
        return false;
    }
    while(contains(a_book)){
        remove(a_book);
    }
    return true;

}






/**@param:   A reference to another LibraryRecord
  @return:  Returns true if the 2 library records have the same contents 
  (including the same number of duplicates for each book), regardless of their order. 
  For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
  and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.

  However, [book1, book2, book2, book3] is not equivalent to [book1, book2, book3, book3], 
  because it contains two copies of book2 and only one copy of book3 
**/

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
    


void LibraryRecord::operator/=(LibraryRecord &rhs) {
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
}







