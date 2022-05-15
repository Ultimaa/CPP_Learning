#include <iostream>
#include <memory>

int main(){
    //raw pointer
    int *ptr = new int{1};
    std::cout << "Adres where int is stored: " << ptr << std::endl; 
    std::cout << "Value of int: " << *ptr << std::endl;
    std::cout << "\"pointer to a pointer.\" Store addres to pointer value addres " << &ptr << std::endl;
    std::cout << "\n";
    //add 1 to raw pointer addres
    int *nPtr = ptr+1;
    std::cout << "Add 1 to raw pointer addres" << std::endl;
    std::cout << "Addres will points 4 bits(int) ahead " << nPtr << std::endl;
    std::cout << "Shows the value at the new(4bits ahead) address (probably 0 or trash value) " << *nPtr << std::endl;
    std::cout << "Address location \"pointer to a pointer.\" has not changed " << &nPtr << std::endl;
    std::cout << "\n";
    //To free alocated memory there is a need to delete the pointer.
    delete ptr;

    //Smart pointers
    std::cout << "Smart pointers:" << std::endl;
    std::unique_ptr<int> uniqueP = std::make_unique<int>(10);
    std::cout << "Unique pointer - auto delete after scope ends" << *uniqueP.get() << std::endl;
    std::shared_ptr<int> sharedP = std::make_shared<int>(10);
    std::cout << "Shared pointer - can be copy, has reference couter, when counter reach zero then call destructor " << std::endl;
    std::cout << "Shared pointer value: " << *sharedP << "Shared Pointer reference counter: " << sharedP.use_count() << std::endl;
    //std::weak_ptr<int> weakP = std::make_shared<int>(10);




    //std::cout << " " << *weakP << std::endl;

    std::shared_ptr < int > sptr(new int);
    std::shared_ptr < int > sptr2;

    std::cout << "sptr: " << sptr.use_count() << " sptr2: " << sptr2.use_count() << '\n';
    sptr2 = sptr;
    std::cout << "sptr: " << sptr.use_count() << " sptr2: " << sptr2.use_count() << '\n';

    {
        std::shared_ptr < int > sptr3 = sptr2;
        std::cout << "sptr: " << sptr.use_count() << " sptr2: " << sptr2.use_count() << '\n';
    }

    std::cout << "sptr: " << sptr.use_count() << " sptr2: " << sptr2.use_count() << '\n';
    return 0;
}