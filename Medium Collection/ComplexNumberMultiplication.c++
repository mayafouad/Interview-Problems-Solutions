/*


A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

 

Example 1:

Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.


Example 2:

Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 

Constraints:

num1 and num2 are valid complex numbers.


*/


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1.pop_back(); num2.pop_back();
        string real1, real2, img1, img2;
        for(int i=0; i<num1.length(); i++)
            if(num1[i] == '+'){
                real1 = num1.substr(0, i);
                img1 = num1.substr(i+1);
            }

        for(int i=0; i<num2.length(); i++)
            if(num2[i] == '+'){
                real2 = num2.substr(0, i);
                img2 = num2.substr(i+1);
            }

        int rr = stoi(real1)*stoi(real2);
        int ri = stoi(real1)*stoi(img2);
        int ir = stoi(img1)*stoi(real2);
        int ii = -1 * stoi(img1)*stoi(img2);

        int r = rr+ii, i = ri+ir;
        string ans = to_string(r) + "+" +  to_string(i) + "i";
        return ans;
    }
};
