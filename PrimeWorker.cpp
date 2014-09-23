//
//  PrimeWorker.cpp
//
//
//  Created by Alptuğ Ulugöl on 23/09/14.
//
//  License: LGPL
//

#include "PrimeWorker.hpp"

namespace AU
{
    PrimeWorker::PrimeWorker()
    {
        
    }
    
    PrimeWorker::PrimeWorker(PrimeWorker& other)
    :primes(other.primes), no_primes(other.no_primes)
    {
        
    }
    
    PrimeWorker::~PrimeWorker()
    {
        primes.clear();
        primes.shrink_to_fit();
    }
    
    bool PrimeWorker::isitprime(unsigned long long int n)
    {
        bool ans = true;
        unsigned long long int sq = sqrt(n);
        
        if (n==0 || n==1)
        {
            ans = false;
        }
        
        else
        {
            for (std::vector<unsigned long long int>::const_iterator it = primes.begin(); it != primes.end() && *it <= sq; it++)
            {
                if (n % *it == 0)
                {
                    ans = false;
                    break;
                }
            }
        }
        
        return ans;
    }
    
    void PrimeWorker::calculate_primes(unsigned long long int number)
    {
        primes.clear();
        primes.reserve(number);
        primes.push_back(2);
        no_primes = 1;
        for (unsigned long long int i=3; no_primes != number; i++)
        {
            if (isitprime(i))
            {
                primes.push_back(i);
                no_primes++;
            }
        }
    }
    
    const std::vector<unsigned long long int>& PrimeWorker::get_primes() const
    {
        return this->primes;
    }
}

std::ostream& operator<<(std::ostream& os, const AU::PrimeWorker& obj)
{
    const std::vector<unsigned long long int> prime = obj.get_primes();
    int k = 1;
    for (std::vector<unsigned long long int>::const_iterator it = prime.begin(); it != prime.end(); it++, k++)
    {
        os<<k<<". "<<*it<<std::endl;
    }
    
    return os;
}