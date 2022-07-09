class fraction{
    private:
    int numerator;
    int denomerator;
    public:
    fraction(int numerator,int denomerator)
    {
        this->numerator=numerator;
        this->denomerator=denomerator;
    }
    void print (){
        cout <<numerator<<"/"<<denomerator;

    }
    void simplify(){
        int gcd=1;
        int j=min(numerator,denomerator);
        for(int i=1;i<=j;i++)
        {
            if(numerator%i==0&&denomerator%i==0)
            {
                gcd=i;
            }
        }
        numerator/=gcd;
        denomerator/=gcd;
    }
    void add(fraction f2){
        int lcm=denomerator*f2.denomerator;
        int num=numerator*f2.denomerator+f2.numerator*denomerator;
        numerator=num;
        denomerator=lcm;
        simplify();
    }
};