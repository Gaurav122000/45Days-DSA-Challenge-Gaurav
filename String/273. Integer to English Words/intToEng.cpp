class Solution {

private:
    vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

public:
    string numberToWords(int num) {
         if (num == 0) {
            return "Zero";
        }

        // for single digit
        if (num < 10) {
            return belowTen[num];
        } //here order of if conditions matter becausem if num = 7 then it gonna handle at the num<10 it not gonna pass to num<20

        // for twenty
        if (num < 20) {
            return belowTwenty[num - 10];// if num = 12, then 12-10 = 2 this 2 gives us 2 element from the array
        }

        // for double digit
        if (num < 100) {//74, 70
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        }

        // for triple digit or hundred
        if (num < 1000) {// case 1 = 999 max = (9 99) this we need to handle, case 2 = 900
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + numberToWords(num % 100) : "");
        }

        // for thousand
        if (num < 1000000) {// case 1 = 9000, case 2 = 999000 = (999 000) or 999111 or 999101 so on
            return numberToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + numberToWords(num % 1000) : "");
        }

        // for million
        if (num < 1000000000) {//990129786 = (990 129 786)
            return numberToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + numberToWords(num % 1000000) : "");
        }

        // for billion
        return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + numberToWords(num % 1000000000) : "");
    }
};