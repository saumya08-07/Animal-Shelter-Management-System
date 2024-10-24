Problem Statement: 

Animal Shelter Management System 

The goal of this project is to create a management system for an animal shelter that facilitates the tracking and administration of animals within the shelter. The system will allow users to add new animals, remove animals when adopted, search for animals by ID, and filter animals by species and gender. The data will be stored in a CSV file, which the program will read upon startup. 

Objectives 

To create a system that allows tracking and managing various animals in a shelter. 

Support basic operations like adding, removing, filtering, and displaying animal information. 

Store and retrieve data from a CSV file, ensuring persistence of information. 

 

 

Brief Explanation: 

This C++ program simulates an animal shelter management system where data about animals is read from a CSV file and stored as objects. The system allows for adding, removing, and viewing animals, as well as filtering based on specific criteria such as species or adoption month. Animals can also be categorized by species, and information regarding whether an animal has been returned is tracked. 

How We Built It 

We used two important programming concepts: inheritance and polymorphism. These concepts allow us to create a flexible and efficient framework that can easily adapt to the needs of different animal species. 

 

Key Features 

Class Inheritance Structure: 

Base Class (Animal): Represents general animal information, with fields like ID, intake details, shelter info, and movement/adoption details. 

Derived Classes: Specialized for different animals like Dog, Cat, Rabbit, Hamster, and Tortoise. These inherit from the base Animal class. 

 

Polymorphism: 

The program utilizes polymorphism to allow derived classes (specific animal types) to override base class methods. This enables dynamic method resolution, allowing the program to treat different animal types uniformly while still invoking their specific behaviours. 

 

 

 

File Handling: 

Reads and writes data to a CSV file. The readAnimalsFromCSV() function loads existing animals into the program, while new animals can be added and saved back to the file. 

 

Data Filtering and Search: 

Find by ID: Allows searching for animals by their unique ID. 

Filter by Species: Filters animals based on their species (Dog, Cat, Rabbit, Hamster, or Tortoise). 

Count by Adoption Month: Tracks how many animals were adopted in a specific month. 

Return Status Check: Verifies whether an animal has been returned to the shelter and provides the return details. 

 

Dynamic Memory Management: 

Animals are stored as pointers in a vector, and dynamic memory allocation is used. After program execution, memory cleanup is performed to avoid leaks. 

 

Menu-Driven Interface: 

A user-friendly console interface allows the user to choose different operations like displaying all animals, adding new ones, or removing animals based on their ID. 

 

Counting and Analysis: 

The system can count animals by species and display this information. 

Animals can be added and removed from the system, and the updated information is stored back in the CSV file. 

 

Conclusion 

The C++ program for the animal shelter management system demonstrates effective use of object-oriented programming principles, particularly inheritance and polymorphism, to enhance code reusability and maintainability. Its features, including file handling, data filtering, and a user-friendly menu, facilitate efficient management of animal records. 

By employing dynamic memory management, the program optimizes resource usage. Overall, this system streamlines operations in animal shelters and supports animal welfare, with opportunities for further enhancements to strengthen its functionality. 
