# include "Data.hpp"

Data::Data() : _val(0) {}

Data::Data(Data &src) : _val(src._val) {}

Data::Data(int val) : _val(val) {}

Data &Data::operator=(Data &src) {
    this->_val = src._val;
    return (*this);
}

Data::~Data(){}

int Data::getValue() const {return (_val);}