
/*
Name: Tasmia Chowdhury 
Class: 235 
Date: 3/1

Book implementation for term project
CSCI 235 Spring 2023
*/

#pragma once
#include <iostream>
#include <string>

class Book{
	public:
		 /**
      	Default constructor.
      	Default-initializes all private members. Booleans are default-initialized to False.
   		*/
		Book()=default;

		/**
		 Parameterized constructor.
		@param      : The title of the book (a string)
		@param      : The author of the book (a string)
		@param      : The number of pages in the book (a positive int)
		@param      : A flag indicating whether the book is in digital form (a Boolean),
						with default value False
		@post       : The private members are set to the values of the corresponding parameters.
		*/
		Book(std::string title, std::string author, int page_count, bool is_digital_ = false);

		/**
			 @return : the title of the Book
		*/
		std::string getTitle() const;  //returns title of book

		/**
			 @return : the author of the Book
		*/
		std::string getAuthor() const;  //returns author of book

		/**
			 @return : the page count
		*/
		int getPageCount() const;  //returns page count of book

		/**
			@return : true if the book is available in digital form, false otherwise

			Note: this is an accessor function and must follow the same convention as
			all accessor functions even if it is not called getDigital
		*/
		bool isDigital() const;  //returns true if book is digital

		/**
		 	@param  : a reference to title of the Book
			@post   : sets the Book's title to the value of the parameter
		*/
		void setTitle(const std::string &title);

		/**
			@param  : a reference to the name of the author of the Book
			@post   : sets the Book's author to the value of the parameter
		*/
		void setAuthor(const std::string &author);


		/**
			@param  : a reference to a positive integer page count
			@pre    : page count > 0 - books cannot have a negative number of pages
			@post   : sets the page count to the value of the parameter
		*/
    	void setPageCount(const int &page_count);

		/**
		 @post   : sets the digital flag to true
		*/
		void setDigital();

        bool operator==(const Book &rhs) const;

        bool operator!=(const Book &rhs) const;

        void display();
        /**
            @post     : displays Book data in the form:
            "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n"     
        */

	private:
	std::string title_; // The title of the book (a string)
    std::string author_; // The author of the book (a string)
    int page_count_; // The page count (an integer)
    bool is_digital_; // A flag indicating whether the book is available in digital form (a Boolean)
};


