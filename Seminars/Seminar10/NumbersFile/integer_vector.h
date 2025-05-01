class integer_vector {
private:
    int* data;
    int size;
    int capacity;

    void resize(int new_capacity);
    void free();
    void copy_from(const integer_vector& other);

public:
    integer_vector();
    integer_vector(const integer_vector& other);
    integer_vector& operator=(const integer_vector& other);
    ~integer_vector();

    void push_back(int value);
    void remove_at(int index);
    
    int& operator[](int index);
    const int& operator[](int index) const;
    
    int get_size() const;
    
    void clear();
    void sort();

    int* raw_data();
};

