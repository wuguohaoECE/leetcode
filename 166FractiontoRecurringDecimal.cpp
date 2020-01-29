class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long Numerator = (long)numerator;
        long Denominator = (long)denominator;
        string operand;
        if( (Numerator>0 && Denominator<0) ){
            operand = "-";
            Denominator = -Denominator;
        }
        if((Numerator<0 && Denominator>0)) {
            operand = "-";
            Numerator = -Numerator;
        }
        long quotient, remainder, poi = 0;
        quotient = Numerator/Denominator;
        remainder =  Numerator - quotient * Denominator;
        cout << quotient << " " <<  remainder << endl;
        string integer;
        string fraction;
        integer = to_string(quotient);
        unordered_map<long, long> map;
        while(remainder != 0 && !map.count(remainder)){
            map[remainder] = poi;
            ++poi;
            remainder *= 10;
            quotient = remainder/Denominator;
            remainder -= quotient * Denominator;
            
            fraction.append(to_string(quotient));
        }
        if(remainder != 0){
            fraction.insert(map[remainder], "(");
            fraction.append(")");
        }
        if(fraction.empty()) return operand+integer;
        return operand+integer+"."+fraction;

    }
};
