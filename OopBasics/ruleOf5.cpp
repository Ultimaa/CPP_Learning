#include <iostream>
#include <string>

class NumbersContainer {
    public:
    using size_type = int;
    using value_type = int;

    NumbersContainer(size_type max_size)
        :max_size(max_size),
        count(0),
        numbers(new value_type[max_size]){
    }

    ~NumbersContainer(){
        delete[] numbers;
        numbers = nullptr;
    }

    NumbersContainer(const NumbersContainer &other)
        : max_size(other.max_size),
          count(other.count),
          numbers(new value_type[max_size]){
              for (value_type i = 0; i < count; i++)
              {
                  numbers[i] = other.numbers[i];
              }    
    }

    NumbersContainer(NumbersContainer &&other)
        : max_size(other.max_size),
          count(other.count),
          numbers(other.numbers){
              other.numbers = nullptr;
    }

    NumbersContainer& operator=(const NumbersContainer &other){
        return *this = NumbersContainer(other);
    }

    NumbersContainer& operator=(NumbersContainer&& other){
        if (numbers){
            delete[] numbers;
        }
        max_size = other.max_size;
        count = other.count;
        numbers = other.numbers;
        other.numbers = nullptr;
        return *this;   
    }

    void add(value_type value){
        numbers[count] = value;
        count++;
    }

    void print_content(){
        for (size_type i = 0; i < count; i++)
        {
            std::cout << numbers[i] << " \n";
        }
        
    }
    private:
    size_type max_size;
    size_type count;
    value_type *numbers;
};

int main() {
    NumbersContainer containerA(10);
    containerA.add(1);
    containerA.add(2);
    containerA.add(3);

    std::cout << "Kontener A org: \n";
    containerA.print_content();
    std::cout << std::endl;
    /** Konstruktor kopiujacy oraz coppy operator
     * / NumbersContainer container_copy(containerA); /
     * / NumbersContainer container_copy = containerA; /
     */
    NumbersContainer container_copy = containerA;
    container_copy.add(21);
    std::cout << "Kontener skopiowany z dodanym 21: \n";
    container_copy.print_content();
    std::cout << std::endl;


    /** Konstruktor przenoszący 
     * Przy przenoszeniu na obiekcie przenoszonym wywoływany jest destruktor.
     * std::move z biblioteki standardowej robi dokładnie to samo 
     * / NumbersContainer containerB(std::move(containerA)); /
     * / static_cast<NumbersContainer&&>(containerA) /
     * 
     * Operator przypisania przenoszący oraz wywolanie konstruktora
     * /NumbersContainer container_move(std::move(containerA)); /
     * /NumbersContainer container_move = std::move(container_copy); /
     */ 
   
    NumbersContainer container_move = std::move(containerA);
    std::cout << "Kontener move z dodanym 11: \n";
    container_move.add(11);
    container_move.print_content();
    std::cout << std::endl;
    return 0;
}