/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int resp = guess(middle);

            if (resp == 0)
            {
                return middle;
            }
            else if (resp == - 1)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return -1;
    }
};