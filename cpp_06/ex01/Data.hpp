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

    private:

        int _val;
};

# endif