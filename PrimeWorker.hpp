//
//  PrimeWorker.hpp
//
//
//  Created by Alptuğ Ulugöl on 23/09/14.
//
//  License: LGPL
//

#ifndef __PrimeWorker__
#define __PrimeWorker__

#include <iostream>
#include <cmath>
#include <vector>

namespace AU
{
    class PrimeWorker
    {
        int no_primes;
        
    protected:
        std::vector<unsigned long long int> primes;
        
        
    public:
        PrimeWorker();
        PrimeWorker(PrimeWorker& other);
        ~PrimeWorker();
        bool isitprime(unsigned long long int n);
        void calculate_primes(unsigned long long int number);
        const std::vector<unsigned long long int>& get_primes() const;
        
    };
}

std::ostream& operator<<(std::ostream& os, const AU::PrimeWorker& obj);

#endif /* defined(__PrimeWorker__) */
