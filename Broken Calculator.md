There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

 

Example 1:

Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: startValue = 5, target = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
Example 3:

Input: startValue = 3, target = 10
Output: 3
Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.
 

Constraints:

1 <= x, y <= 109


Abhay_Rautela's avatar
Abhay_Rautela
239
Last Edit: 10 hours ago

1.6K VIEWS

First Approach
After reading the problem first approach which would come in my mind is based on the operation which is given.
That is multiplying and subtracting for reaching from 'startValue' to 'target' value.
There would be possibly three cases in this...
1. If startValue == target then it will be zero.
2. If startValue > target then we only subtract by 1 till we get startValue == target.
3. If startValue < target then we only multiply it by till we get startValue equal to target or startValue > target. If startValue get greater than target then we only perform decrementing it.
 
 But this approach fails in second case '😅'  
	I/P startValue = 5 target = 8
	Acc to my approach 
	First we go from 5->10 ( X 2 )
	Second we subtract 10 -> 9 -> 8 
	Total steps is 3.
	But the answer is 2;
	HOW ?? by just decreasing by 1 and then multiplying by 2 i.e 5 -> 4 -> 8.
Second Approach
Instead of going from startValue to target value we go for opposite i.e target value to startValue.
By reversing the operation i.e instead of multiplying we go for dividing and instead of subtarcting we go for adding.
There would be also possibly three cases in this...
1. If target == startValue then it will be zero.
2. If  target > startValue then we only divide it by 2 till we get startValue == target or startValue get greater than target. 
	IN STEP SECOND WE HAVE ONE MORE SUB CASES.
	We only go for division if target is even else we only increase target by 1.
3. If target < startValue then we only increment it by 1.

Example 
	I/P  startValue = 5   target = 8
	Step - 1 target > startValue then divide target by 2 , it becomes 4.
	Step - 2 target < startValue then we only add by 1 till we get target == startValue. We can only find it by subtracting startValue - target value as startValue is > than target in this case.
	Therfore total no of steps taken is divide->add i.e '2' which is the answer.

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result=0;
        while(target>startValue)
        {
            result++;
            if(target%2==0)
                target=target/2;
            else
                target+=1;
        }
        result=result+(startValue-target);
        return result;
    }
};