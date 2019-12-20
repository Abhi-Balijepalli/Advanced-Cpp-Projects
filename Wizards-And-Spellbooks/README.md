The Wizard Spellbook Catalog

Problem Statement:

The great wizard school of Pogwarts has been adding a lot of new spellbooks to their library lately. As a result of all the new literature some mischievous students have been learning spells that are dangerous. In addition, it has become increasingly difficult for the staff to find specific spells they want to teach in class.
In order to alleviate these issues the school administration has hired you to create a spellbook catalog program that will allow for access restriction and make searching for spellbooks easier.
To simplify your task, the school has provided you with their spellbook and wizard profile information. These come in the form of two textfiles: wizards.txt and spellbooks.txt. NOTE: The two filenames are provided on the command line and should not be hardcoded in your program! The spellbooks.txt file contains a list of Pogwarts’s spellbooks and their included spells. This file will give you the spellbook and spell information that your program will organize and display. The wizards.txt file contains a listing of all wizards associated with Pogwarts. This file will give your program the information needed to control which spellbooks users can access.
Requirements
Command Line Arguments:

When starting the program, the user will provide two command line arguments. The first command line argument will be the name of the file that holds the information about the wizards. The second command line argument will be the name of the file that contains the information about spellbooks and included spells. If the user does not provide two names of existing files the program should print out an error message and quit. You can assume that the user always provides these two command line arguments in the correct order.
Wizard Login

Before the user can get information from the program they must login. You must prompt the user for an ID and password. The ID of the must be all ints. If it isn’t, you must re-prompt the user for an ID that is only ints. You will then prompt the user for the password. The password will be a string that could contain any number of characters and numbers. You do not need to do any error handling on the password. You will then need to check this information against the wizard_info.txt file contents to determine which wizard is logging in. If there is no match, you must reprompt for both username and password again. If the user fails to login after three attempts, you must provide an error message and quit out of the program. (Note: If the user provides an ID that is not all integers that should not count as an error towards the three attempts that they have to login). After a user logs in, you must display the corresponding name, ID, school position, and beard length
Sorting and Printing:

Once the user has logged in they should be prompted with a list of different ways to display the sorted spellbook and spell information. Wizards with student status cannot view any spell that has an effect of death or poison and cannot view any spellbook with a spell that has an effect of death or poison. After the user has chosen an option, they should be asked if they want the information printed to the screen or written to a file. If they choose to write to a file, they should be prompted for a file name. If the file name already exists, the information should be appended to the file. If the file name does not exist, a file should be created and the information should be written to the file. For your sorting, you cannot use the built-in sort function.

Available Options (after successful login):

    Sort spellbooks by number of pages: If the user picks this option the books must be sorted in ascending order by number of pages. Books with a spell that have an effect of death or poison should not be displayed when a student is logged in (i.e. hide those books from the results when a student is logged in). Once they are sorted, you should print/write to file the title of the book and the number of pages it has.
    Sort spells by effect: There are five types of spells: fire, bubble, memory_loss, death, poison. Remember that students cannot see spells that have the type death or poison. The spells with bubbles as the effect should be listed first, followed by memory_loss, fire, poison, and death. Once they are sorted, you should print/write to file the spell name and its effect.
    Sort by average success rate of spells: You must create a list of books sorted by the average success rate of all the spells contained within the book. Once calculated, you should print/write to file the title of each applicable book and the corresponding average success rate. Books with a spell that have an effect of death or poison should not be displayed when a student is logged in (i.e. hide those books from the results when a student is logged in).
    Quit: The program will exit.


 
