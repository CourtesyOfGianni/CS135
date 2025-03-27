#include "SortGame.hpp"
#include <iostream> //for cout
#include <iomanip>  //for setw
#include <cstdlib>  //for rand
#include <ctime>    //for time
#include <algorithm> //for swap

//TEMPLATE USED FROM PROJECT PDF

//TASK A: Constructors

//5.1 TASK:
//5.1-1.) numDiffElms = 2
//5.1-2.) capacity = 4
//5.1-3.) numEmptyBins = 1
SortGame::SortGame() : SortGame(2, 4, 1) 
{
    //SUMBITING TASK B: (given Warning:, randomize() does not need to be called here).
}

//5.2 TASK: 
SortGame::SortGame(int numDiffElms, int capacity, int numEmptyBins) 
{ 
    //5.2-1.) If given a parameter numDiffElms is smaller than 1, reset it to be 1.
    if (numDiffElms < 1)
    {
        numDiffElms = 1;
    }

    //5.2-2.) If given parameter capacity is smaller than 2, reset it to be 2.
    if (capacity < 2)
    {
        capacity = 2;
    }

    //5.2-3.) If given parameter numEmpttyBins is smaller than 1, reset it to be 1.
    if (numEmptyBins < 1)
    {
        numEmptyBins = 1;
    }

    //5.2-4.) Set up data members (if names are same use "this->" which is pointer to object).
    this->numDiffElms = numDiffElms;
    this->capacity = capacity;
    this->numEmptyBins = numEmptyBins;


    //5.1-4.) After initializing data memembers, initialize data member bins.
    //Creating filled bins.
    for (int i = 0; i < numDiffElms; i++) //for each shape
    {
        std::vector<int> row; // create an empty vector (empty bin)

        for (int j = 0; j < capacity; j++) //runs until the vector (bin) is full.
        {
            row.push_back(i + 1); //fills up the vector with that specified shape (not randomized.)
        }

        bins.push_back(row); //after the iteration is created and completed, adds it to the "bins" (vector).
    }
    //Creating empty bins.
    for (int i = 0; i < numEmptyBins; i++)
    {
        bins.push_back(std::vector<int>()); //creates an empty vector (empty bin), and adds it to the "bins" (vector).
    }


    //SUMBITING TASK B:
    randomize();
}

//5.3 TASK:
//Does not need to be randomized!
SortGame::SortGame(std::vector<std::vector<int>> binData, int numEmptyBins)

    //5.3-1.) call size method of binData [numDiffElms = binData.size()].
    //5.3-2.) Initialize capacity to be number of elements in row of binData [capacity = binData[0].size()].
    : SortGame(binData.size(), binData[0].size(), numEmptyBins) {

        //5.3-3.) add each row of "binData" to data members "bins".
        bins = binData;

        //5.3-4.) Add "numEmptyBins" empty bins to data member "bins".
        for (int i = 0; i < numEmptyBins; i++)
        {
            bins.push_back(std::vector<int>()); //creates an empty vector (empty bin), and adds it to the "bins" (vector).
        }
}

//--------------------------------------------------------------------

//TASK B: Randomize & Display

//6.1 TASK:
//Randomize (Approach 1): Randomize using 1D intermediate vector. (6.2)
void SortGame::randomize()
{
    //1.) given the "bins" vector create a 2D vector flatten it to 1D.

    std::vector<int> flattened; // new empty vector, (used to store 1D vector data)!

    for (int i = 0; i < numDiffElms; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            flattened.push_back(bins[i][j]); //going through each value in each bin and adds it into the newly created vector.
        }
    }

    //2.) With the 1D vector of values, randomize it.

    int currLastIdx = flattened.size() - 1; //set it equal to the last value of the vector.

    while (currLastIdx > 0) //repeats until there is just a single int in the vector left.
    {
        int k = rand() % (currLastIdx + 1); //gets a random value from the vector, that does not include the last index.

        std::swap(flattened[k], flattened[currLastIdx]); //swap places with the random value with the value of the last index.

        currLastIdx--; //goes to the next to last index, while also locking off the last index from being changed in the process.
    }


    //3.) After randomizing, using the 1D array revert back to "bins".
    
    int idx = 0; //counter for placing the vector back into "bins".

    for (int i = 0; i < numDiffElms; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            bins[i][j] = flattened[idx++]; //fills up the first bin to capacity, then the rest 1 by 1 with the randomized 1D vector.
        }
    }
}

//6.4 TASK:
void SortGame::display() const
{
    std::string shapes[] = {
       "\u2b24", //circle
       "\u2b1f", //pentagon
       "\u25fc", //medium square, can add color
       "\u272f", //star, can add color
       "\u2665", //heart
       "\u25b2", //triangle
    };
    int shapes_size = sizeof(shapes) / sizeof(shapes[0]);
 
    std::vector<std::string> colorShapeMap(numDiffElms);
    int colorCode = 31;
    //"\033[31m", a const char*, represents red text color
    //"\033[32m" represents green text color
    for (int i = 0; i < numDiffElms; i++) {
        colorShapeMap[i] = "\033[" + std::to_string(colorCode) + "m" + shapes[i % shapes_size] + "\033[0m";
        //restore to \033[0m, black color, after displaying a colored shape
        colorCode++;
    }


    //int i = 0; //ith bin, the first bin
    //for (int j = bins[i].size() -1; j >= 0; j--)
    for (int j = capacity -1; j >= 0; j--) {
        for (int i = 0; i < bins.size(); i++) {
            //remove the end of line endl,
            //since we do not print an endl after print the data of a bin.
            if (j < bins[i].size())
                //std::cout << "|  " << bins[i][j] << " |";
                std::cout << "|  " << colorShapeMap[bins[i][j]-1] << " |";
            else std::cout << "|    |";

            //print gap distance between bins, no spaces after the last bin.
            if (i < bins.size() -1)
               std::cout << "    ";
        }
  
        //add a new line after printing the jth item of all bins 
        std::cout << std::endl;
    }



    for (int i = 0; i < bins.size(); i++) 
    {
        std::cout << "+----+"; //prints the bottom portion of the bin.

        if (i < bins.size() - 1) //promt uses for spacer (used from template).
        {
            std::cout << "    "; 
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < bins.size(); i++) 
    {
        std::cout << "  Bin" << i + 1; //prints 'Bin' along with its corresponding #.

        if (i < bins.size() - 1) //promt uses for spacer (used from template).
        {
            std::cout << "    ";
        }
    }
    std::cout << std::endl;
}

//--------------------------------------------------------------------

//TASK C:  Move

bool SortGame::move(std::vector<std::vector<int>>& shapesInBins, int& numFinishedBins)
{
    //prompt user to enter 2 ints
    int moveOut;
    int moveIn;

    //std::cout << "Select which bin to move out of, then which bin to move into: "; [OPTIONAL]
    std::cin >> moveOut >> moveIn; //entering values for the 2 variables.

    //if both move out AND move in are -1, -> return false.
    if (moveOut == -1 && moveIn == -1)
    {
        return false;
    }

    //subtract the inputs by 1, to ensure the information used is the correct index, [ex: 1 = 0, 2=1, 3=2].
    moveOut -= 1;
    moveIn -= 1;

    //NOTE: return true = user still plans to keep trying to finish the game!

    //if move out OR move in are not in the range of [1, number of bins], -> print prompt and return true.
    if (moveOut < 0 || moveOut >= bins.size() || moveIn < 0 || moveIn >= bins.size())
    {
        std::cout << "wrong bin number" << std::endl;
        return true;
    }

    //if move out bin is empty (has no element), -> print prompt and return true.
    if (bins[moveOut].empty())
    {
        std::cout << "move out bin is empty" << std::endl;
        return true;
    }

    //declare int to hold top element of move out bin (use back method from vector class).
    int topElementOut = bins[moveOut].back();
    //declare int to hold top element of move in bin (if its empty declare it to be -1 to when an element is added is will become 0[first index], if not set it to be the last index in the vector).
    int topElementIn = (bins[moveIn].empty()) ? -1 : bins[moveIn].back();

    //if move in bin is not empty AND top element of in and out do NOT match, -> print prompt and return true.
    if (!bins[moveIn].empty() && topElementIn != topElementOut)
    {
        std::cout << "not match" << std::endl;
        return true;
    }

    //count the number of consecutive elements.
    int consecutiveElements = 0; //on top of the move out bin.

    for (int i = bins[moveOut].size() - 1; i >= 0; i--) //checking through each element in the moveout bin (starting from the top [because -1]).   
    {
        if (bins[moveOut][i] == topElementOut) //if the last index element of the out bin is equal to the topElementOut:
        {
            consecutiveElements++; //increase the count of consecutive elements in the out bin.
        }
        else
        {
            break;  
        }
    }

    //if adding intend-to-move from out bin(consecutive elements) to move in bin, AND it surpasses the capacity, -> print prompt and return true.

    int moveInCount = shapesInBins[moveIn][topElementOut - 1]; //gets the amount by checking [moveIn](bin #) [topElementOut -1](last index value).

    if ((moveInCount + consecutiveElements) > capacity) //if adding surpasses capacity:
    {
        std::cout << "The move in bin has no sufficient slots." << std::endl;
        return true;
    }

    //move all same-shape elements from the top of move out bin, to the top of move in bin.

    for (int i = 0; i < consecutiveElements; i++) //repeat the amount of times a consecutive element is moved:
    {
        bins[moveOut].pop_back(); //decrease the size of the move out bin.

        bins[moveIn].push_back(topElementOut); //add the previously defined 'topElementOut' to the move in bin.
    }

    //1.) must update data member bins and variable shapesInBins.
    shapesInBins[moveOut][topElementOut - 1] -= consecutiveElements;

    if (topElementIn != -1)
    {
        shapesInBins[moveIn][topElementIn - 1] += consecutiveElements; //if in bin has at least a shape.
    }
    else
    {
        shapesInBins[moveIn][topElementOut - 1] = consecutiveElements; //if in bin is empty.
    }

    //2.) If after adding the elements, the move in ball bin has capacity many same shape elements, -> increase numFinishedBins by 1.
    if (shapesInBins[moveIn][topElementOut - 1] == capacity)
    {
        numFinishedBins++;
    }

    //call display after moving all elements.
    display();

    return true;
}
