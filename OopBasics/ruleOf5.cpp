#include <iostream>
#include <string>

class NumbersContainer
{
public:
    using size_type = int;
    using value_type = int;

    NumbersContainer(size_type max_size)
        :max_size(max_size),
        count(0),
        numbers(new value_type[max_size])
    {
    }

    ~NumbersContainer()
    {
        delete[] numbers;
        numbers = nullptr;
    }

    NumbersContainer(const NumbersContainer& other)
        :max_size(other.max_size),
        count(other.count),
        numbers(new value_type[max_size])
    {
        for (value_type i = 0; i < count; i++)
        {
            numbers[i] = other.numbers[i];
        }
    }

    NumbersContainer(NumbersContainer&& other)
        :max_size(other.max_size),
        count(other.count),
        numbers(other.numbers)
    {
        other.numbers = nullptr;
    }

    NumbersContainer& operator=(const NumbersContainer& other)
    {
        return *this = NumbersContainer(other);
    }

    NumbersContainer& operator=(NumbersContainer&& other)
    {
        if (numbers)
        {
            delete[] numbers;
        }
        max_size = other.max_size;
        count = other.count;
        numbers = other.numbers;
        other.numbers = nullptr;
        return *this;
    }

    void add(value_type value)
    {
        numbers[count] = value;
        count++;
    }

    void deleteValue(value_type value)
    {
        for (size_type i = 0; i < count; i++)
        {
            if (numbers[i] == value)
            {
                numbers[i] = numbers[count - 1];
                count--;
                std::printf("Value: %i found at possition: %i and delete. \n", value, i);
                return;
            }
        }
        std::printf("Value: %i not found \n", value);
    }

    void deleteExactPosition(size_type position)
    {
        if (position > max_size || position < 0)
        {
            std::printf("Position %i is bigger or lower than size of array \n", position);
        } else if (position > count)
        {
            std::printf("Position %i is greater than the last item position \n", position);
        } else
        {
            deleteValue(numbers[position]);
        }
    }

    void print_content()
    {
        for (size_type i = 0; i < count; i++)
        {
            std::printf("%i: %i \n", i, numbers[i]);
        }
    }

private:
    size_type max_size;
    size_type count;
    value_type* numbers;
};

int main()
{
    NumbersContainer containerA(10);
    containerA.add(1);
    containerA.add(2);
    containerA.add(3);

    std::cout << "ContainerA: \n";
    containerA.print_content();
    std::cout << std::endl;

    /**
     * Copy constructor - test
     */
    NumbersContainer container_copy = containerA;
    container_copy.add(21);
    std::cout << "Container copied from: \"containerA\" and add \"21\" \n";
    container_copy.print_content();
    std::cout << std::endl;

    /**
     * Move constructor and delete functions - test
     */

    NumbersContainer container_move = std::move(containerA);
    std::cout << "Container moved from: \"containerA\" and add \"11\" \n";
    container_move.add(11);
    container_move.print_content();
    std::cout << std::endl;

    std::cout << "Container_move after delete possition 0 and try delete value \"1\" \n";
    container_move.deleteExactPosition(0);
    container_move.deleteValue(1);
    container_move.print_content();
    return 0;
}