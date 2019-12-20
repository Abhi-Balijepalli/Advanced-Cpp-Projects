Zoo Tycoon
Motivation

The goal of this assignment is to start working with inheritance in C++. As you implement your program you'll also expand your knowledge and familiarity of object-oriented programming.
Problem Statement

For this assignment, you will implement a small game where the player acts as the owner of the city's zoo, which has exhibits of monkeys, sea otters, and meerkats. As the owner, it's the player's job both to ensure the welfare of the animals and to generate as much profit as possible. They accomplish these goals by investing in animals, feeding them, caring for them when they are sick, and raising their babies when they are born.

Each species of animal has these specific traits:

    Age
        For all species, an animal is a baby if it is less than 5 weeks old.
        For all species, an animal is an adult if it is at least 2 years old.
        Clarification: For our purposes the age range between 5 weeks and 2 years can be considered as adolescence. The animal is no longer a baby but is not yet capable of reproducing.
    Cost
        Monkeys cost $15,000 each.
        Sea otters cost $5,000 each.
        Meerkats cost $500 each.
    Babies
        Monkeys have 1 baby at a time.
        Sea otters have 2 babies at a time.
        Meerkats have 5 babies at a time.
    Food cost
        The base daily food cost varies on a week-to-week basis (see below).
        Monkeys have a weekly food cost of 4 times the base food cost.
        Sea otters have a weekly food cost of 2 times the base food cost.
        Meerkats have a weekly food cost equal to the base food cost.
    Revenue
        Each animal generates weekly revenue equal to a percentage of the initial cost of one of its species.
            All animals except monkeys generate 5% of the cost of one of their species (i.e. each sea otter generates $250 each week, and each meerkat generates $25 each week).
            Each monkey generates 10% of the cost of a monkey (i.e. each monkey generates $1500 each week).
        On certain weeks, when attendance is high, each monkey generates some amount of bonus revenue. See below for details.

Game Flow

The game starts with the owner having no animals and $100,000 in the bank, and it proceeds one week at a time. You can think of each week as a turn for the player. During a single week, several things happen. Note: This list was causing confusion so I have added some clarification and rearranged the order. As long as your implementation follows the spirit of the assignment, it's okay to have minor differences.

    The age of each animal currently in the zoo increases by 1 week (note that you can track time in days if you prefer).

    A special event occurs. The special event is chosen at random from among the following options:
        One randomly chosen animal gets sick. In order to care for the sick animal, the owner must pay an amount equal to half the initial cost of an animal of the same species as the sick animal (e.g. a sick monkey costs half of $15,000, i.e. $7,500). If the owner has enough money to cover this cost, it is subtracted from their bank account. If they do not have enough money, then the sick animal dies and is removed from the zoo.
        A randomly chosen adult animal gives birth to the appropriate number of babies for its species (a non-adult can't have babies). Each baby starts with age 0 and is added into the zoo.
        A boom in zoo attendance occurs. Each time this happens, each monkey generates a random amount of extra bonus revenue between $300 and $700.
        No special event occurs during this week.
    The owner receives weekly revenue for each animal, as specified above.
    The owner may buy up to two adult animals of a single species. The owner may only buy one species per week, but they do not have to buy any animals if they don't want to. Each animal that the owner buys is exactly 2 years old. When the owner buys an animal, the cost of the animal is subtracted from the owner's bank account.
    The owner must pay the upcoming feeding cost for each animal in the zoo (including any they just bought). The cost of food for each animal is calculated using the base cost of food. This starts out as $40. Each week, the base cost changes to a random value between 75% and 125% of the base cost from the week before. Once the cost of food for each animal is calculated, this amount is subtracted from the owner's bank account.

In addition to the specifications above, your game must have these features:

    Each animal less than 5 weeks old (a baby) generates twice the amount of revenue as an adult animal. These babies (who are less than 5 weeks old) also cost twice as much as an adult if they get sick.

    If the player runs out of money at any point, the game ends with the zoo going bankrupt.

Other Program Requirements

    You must have a class for each of the following things: zoo, animal, monkey, sea otter, and meerkat.

    You must use inheritance: the classes for monkey, sea otter, and meerkat must inherit some traits and behaviors from the animal class, though each of them may also have unique traits or behaviors, as well (e.g. the bonus payout for monkeys).

    Within your zoo, the exhibit of each species of animal must be represented as a dynamically-allocated array of objects of the appropriate class.

    Your program should implement the game flow described above. The player may play one week at a time until they choose to quit the came. At the beginning of each week, you should let the player know how much money they have in the bank and how many adults (>= 2 years old) and babies (< 5 weeks old) they have of each species.

    Your program may not have any memory leaks. I strongly recommend that you use Valgrind to occasionally test your program as you develop it (even when everything seems to be working).
    The Big 3 must be implemented as appropriate.

    Your program must be factored into interface, implementation, and application. Specifically, you should have one header file and one implementation file for each class, and you should have a single application file containing your main() function. You should also include a Makefile that specifies compilation for your program.

    No use of libraries that have not been permitted in the course (namely <algorithms> and <vector>)
    Lack of correct coding style will incur an automatic 10 point deduction. You must follow the spirit of the assignment.
