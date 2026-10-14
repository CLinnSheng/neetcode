#include <vector>
/*
 * Each cost $5. Customers are in a queue FIFO.
 * Each customer only buy one and pay either $5, $10 or $20.
 * We do not have any change in hand at first.
 *
 * Find out whether can we give each customer the correct change or not
 *
 * Intuition:
 * Simple, just keep track of the number of $5, $10 and $10 we have in hands every single time
 * */
class Solution
{
  public:
    bool lemonadeChange(std::vector<int> &bills)
    {
        int five{}, ten{}, twenty{};

        for (auto bill : bills)
        {
            // Base Case
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                ten++;

                if (five == 0)
                {
                    return false;
                }

                five--;
            }
            else
            {
                twenty++;

                // Consume ten first then only go to five if not enough
                if (ten)
                {
                    ten--;
                    bill -= 10;
                }

                while (five && bill > 5)
                {
                    five--;
                    bill -= 5;
                }

                if (bill != 5)
                {
                    return false;
                }
            }
        }

        return true;
    }
};