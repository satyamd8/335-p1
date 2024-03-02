#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = 0;
        price_ = 0;
        keywords_ = {};
        blurb_ = "";
    }

    Book::~Book()
    {
        delete icon_;
    }

    Book::Book(const Book& rhs)
    {
        //copy constructor
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = new int(*rhs.icon_);
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }

    Book& Book::operator=(const Book& rhs)
    {
        //copy assignment operator
        if (this != &rhs){
            title_ = rhs.title_;
            author_ = rhs.author_;
            ISBN_ = rhs.ISBN_;
            if (rhs.icon_ != nullptr){
                delete icon_;
                icon_ = rhs.icon_;
            }
            price_ = rhs.price_;
            keywords_ = rhs.keywords_;
            blurb_ = rhs.blurb_;
        }
        return *this;
    }

    Book::Book(Book&& rhs)
    {
        //move constructor
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }

    Book& Book::operator=(Book&& rhs)
    {
        //move assignment operator
        if (this != &rhs){
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = std::move(rhs.ISBN_);
            if (rhs.icon_ != nullptr){
                delete icon_;
                icon_ = std::move(rhs.icon_);
                delete rhs.icon_;
            }
            price_ = std::move(rhs.price_);
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
        }
        return *this;
    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        icon_ = icon;
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    void Book::print() const
    {
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "ISBN: " << getISBN() << std::endl;

        std::cout << "Icon: ";
        for (int i = 0; i < 80; i++){
            std::cout << getIcon()[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl;


        std::cout << "Keywords: ";
        for (int i = 0; i < getKeywords().size(); i++){
            if (i == getKeywords().size() - 1){
            std::cout << getKeywords()[i];
            }
            else {
            std::cout << getKeywords()[i] << ", ";
            }
        } 
        std::cout << std::endl;

        std::cout << "Blurb: " << getBlurb() << std::endl;
    }

    /* Copyright 2024 Satyam Dhar */