# ifndef DATA_CPP
# define DATA_CPP

class Data
{
    public:

        Data(void);
        Data(Data &src);
        Data(int val);
        Data &operator=(Data &src);
        ~Data(void);

        int getValue() const;
        void setValue(const int val);

    private:

        int _val;
};

# endif